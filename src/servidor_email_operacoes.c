#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_encadeada.h"
#include "servidor_email_operacoes.h"
#include "usuario_operacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mensagens_servidor_resposta(
    int codigo_resposta, int id_usuario, char *msg
) {
    switch (codigo_resposta) {
        case CONSULTA_REALIZADA:
            printf("CONSULTA %d: %s\n", id_usuario, msg);
            break;
        case MENSAGEM_ENTREGUE:
            printf("OK: MENSAGEM PARA %d ENTREGUE\n", id_usuario);
            break;
        case CONTA_CADASTRADA:
            printf("OK: CONTA %d CADASTRADA\n", id_usuario);
            break;
        case CONTA_REMOVIDA:
            printf("OK: CONTA %d REMOVIDA\n", id_usuario);
            break;
        case DADOS_INVALIDOS:
            printf("ERRO: DADOS PASSADOS INVALIDOS\n");
            break;
        case CONTA_JA_EXISTENTE:
            printf("ERRO:CONTA %d JA EXISTENTE\n", id_usuario);
            break;
        case CONTA_NAO_EXISTE:
            printf("ERRO: CONTA %d NAO EXISTE\n", id_usuario);
            break;
        case CAIXA_DE_ENTRADA_VAZIA:
            printf("CONSULTA %d: CAIXA DE ENTRADA VAZIA\n", id_usuario);
            break;
        default:
            printf("ERRO: ERRO INESPERADO\n");
            break;
    }
}

operacoes_servidor operacao_desejada(char *nome_operacao) {
    char operacoes[][10] = { "CONSULTA", "CADASTRA", "REMOVE", "ENTREGA" };
    int qtd = 4;
    for (int i = 0; i < QTD_OPERACOES; i++) {
        if (strcmp(nome_operacao, operacoes[i]) == 0) {
            return i;
        }
    }
    return OPERACAO_INVALIDA;
}

void liberar_memoria_programa(
    FILE *arq_ponteiro, lista_encadeada lista_usuarios
) {
    if (arq_ponteiro != NULL) {
        fclose(arq_ponteiro);
    }
    arq_ponteiro = NULL;
    if (lista_usuarios != NULL) {
        destroi_lista_encadeada(lista_usuarios);
    }
    lista_usuarios = NULL;
}

void servidor_operacao_cadastro_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
) {
    int id_usuario, codigo_resposta;
    if (fscanf(arquivo, " %d", &id_usuario) != 1) {
        perror("Error");
        liberar_memoria_programa(arquivo, lista_usuarios);
        exit(1);
    }
    if (lista_usuarios == NULL) {
        lista_usuarios = cria_lista_encadeada();
    }
    codigo_resposta = cadastrar_novo_usuario(lista_usuarios, id_usuario);
    mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
}

void servidor_operacao_remover_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
) {
    int id_usuario, codigo_resposta;
    if (fscanf(arquivo, " %d", &id_usuario) != 1) {
        perror("Error");
        liberar_memoria_programa(arquivo, lista_usuarios);
        exit(1);
    }
    codigo_resposta = remover_usuario(lista_usuarios, id_usuario);
    mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
}

void servidor_operacao_entregar_mensagem_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
) {
    int id_usuario, prioridade, tamanho_atual_str_aux = 100, codigo_resposta;
    char msg_buffer[100];
    char *string_aux = (char *)malloc(tamanho_atual_str_aux * sizeof(char));
    verifica_estouro_memoria(string_aux, "main()");
    
    if (string_aux == NULL) {
        perror("ERROR");
        exit(1);
    }
    
    if (fscanf(arquivo, " %d %d ", &id_usuario, &prioridade) != 2) {
        perror("ERRO");
        liberar_memoria_programa(arquivo, lista_usuarios);
        exit(1);
    }
    char sentinela_fim_arquivo[] = "FIM";
    char *str_particao;
    int qtd_char_gravados = 0;
    bool chegou_fim_arquivo = false;
    while (fgets(msg_buffer, 100, arquivo) != NULL) {
        str_particao = strtok(msg_buffer, " \n");
        while (str_particao != NULL) {
            int tamanho_particao = strlen(str_particao);
            if (tamanho_particao == 3) {
                if (strcmp(str_particao, sentinela_fim_arquivo) == 0) {
                    string_aux[qtd_char_gravados] = '\0';
                    chegou_fim_arquivo = true;
                    break;
                }
            }
            for (int i = 0; i < tamanho_particao; i++) {
                if (qtd_char_gravados == (tamanho_atual_str_aux - 1)) {
                    tamanho_atual_str_aux *= 2;
                    string_aux = realloc(
                        string_aux, tamanho_atual_str_aux * sizeof(char)
                    );
                }
                string_aux[qtd_char_gravados] = str_particao[i];
                qtd_char_gravados++;
            }
            string_aux[qtd_char_gravados] = ' ';
            qtd_char_gravados++;
            str_particao = strtok(NULL, " \n");
        }
        if (chegou_fim_arquivo == true) {
            break;
        }
    }
    if (!chegou_fim_arquivo) {
        printf("ERRO: ARQUIVO COM FORMATO INVALIDO\n");
        liberar_memoria_programa(arquivo, lista_usuarios);
        exit(1);
    }
    codigo_resposta = enviar_email_para_usuario(
        lista_usuarios, id_usuario, string_aux, prioridade
    );
    free(string_aux);
    string_aux = NULL;
    mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
}

void servidor_operacao_consultar_mensagem_priori(
    FILE *arquivo, lista_encadeada lista_usuarios
) {
    int id_usuario, codigo_resposta;
    email email_consulta = { 0, NULL };
    if (fscanf(arquivo, " %d", &id_usuario) != 1) {
        perror("ERRO");
        liberar_memoria_programa(arquivo, lista_usuarios);
        exit(1);
    }
    codigo_resposta
        = consulta_id_msg_priori(lista_usuarios, id_usuario, &email_consulta);
    mensagens_servidor_resposta(
        codigo_resposta, id_usuario, email_consulta.mensagem
    );
    remove_email_ja_consultado(lista_usuarios, id_usuario);
}

void realiza_operacoes_servidor(
    int cod_operacao, lista_encadeada lista_usuarios, FILE *arquivo
) {
    int id_usuario, codigo_resposta, prioridade, tamanho_atual_str_aux = 100;
    char msg_buffer[100];
    char *string_aux = (char *)malloc(tamanho_atual_str_aux * sizeof(char));
    switch (cod_operacao) {
        case CADASTRA:
            servidor_operacao_cadastro_usuario(arquivo, lista_usuarios);
            break;
        case REMOVE:
            servidor_operacao_remover_usuario(arquivo, lista_usuarios);
            break;
        case CONSULTA:
            servidor_operacao_consultar_mensagem_priori(
                arquivo, lista_usuarios
            );
            break;
        case ENTREGA:
            servidor_operacao_entregar_mensagem_usuario(
                arquivo, lista_usuarios
            );
            break;
    }
    if (string_aux != NULL) {
        free(string_aux);
    }
}
