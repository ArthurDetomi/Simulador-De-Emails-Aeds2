#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_array.h"
#include "lista_encadeada.h"
#include "usuario_operacoes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int operacao_desejada(char *nome_operacao) {
    char operacoes[][10] = { "CONSULTA", "CADASTRA", "REMOVE", "ENTREGA" };
    int qtd = 4;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(nome_operacao, operacoes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argv, char *argc[]) {
    lista_encadeada lista_usuarios = NULL;
    if (argv != 2) {
        printf("ERRO: ARGUMENTOS INVALIDOS\n");
        exit(1);
    }

    FILE *arquivo = fopen(argc[1], "r");
    if (arquivo == NULL) {
        perror("Error");
        exit(1);
    }

    char operacao[10];
    while (!feof(arquivo)) {
        if (fscanf(arquivo, "%s", operacao) != 1) {
            perror("Error");
            exit(1);
        }
        int cod_operacao = operacao_desejada(operacao);
        if (cod_operacao == -1) {
            printf("FORMATO ARQUIVO INVALIDO");
            exit(1);
        }

        if (lista_usuarios == NULL) {
            lista_usuarios = cria_lista_encadeada();
        }

        int id_usuario, codigo_resposta, prioridade, tamanho_atual_str_aux = 100;
        email email_consulta = { 0, NULL };
        char msg_buffer[100];
        char *string_aux = (char *)malloc(tamanho_atual_str_aux * sizeof(char));
        switch (cod_operacao) {
            case 1:
                if (fscanf(arquivo, " %d", &id_usuario) != 1) {
                    perror("Error");
                    exit(1);
                }
                if (lista_usuarios == NULL) {
                    lista_usuarios = cria_lista_encadeada();
                }
                codigo_resposta
                    = cadastrar_novo_usuario(lista_usuarios, id_usuario);
                mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
                break;
            case 2:
                if (fscanf(arquivo, " %d", &id_usuario) != 1) {
                    perror("Error");
                    exit(1);
                }
                codigo_resposta = remover_usuario(lista_usuarios, id_usuario);
                mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
                break;
            case 0:
                if (fscanf(arquivo, " %d", &id_usuario) != 1) {
                    perror("ERRO");
                    exit(1);
                }
                codigo_resposta = consulta_id_msg_priori(
                    lista_usuarios, id_usuario, &email_consulta
                );
                mensagens_servidor_resposta(
                    codigo_resposta, id_usuario, email_consulta.mensagem
                );
                remove_email_ja_consultado(lista_usuarios, id_usuario);
                break;
            case 3:
                if (fscanf(arquivo, " %d %d ", &id_usuario, &prioridade) != 2) {
                    perror("ERRO");
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
                                    string_aux,
                                    tamanho_atual_str_aux * sizeof(char)
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
                    exit(1);
                }
                codigo_resposta = enviar_email_para_usuario(
                        lista_usuarios, id_usuario, string_aux, prioridade
                );
                free(string_aux);
                string_aux = NULL;
                mensagens_servidor_resposta(
                        codigo_resposta, id_usuario, NULL
                );
            break;
        }
        if (string_aux != NULL) {
            free(string_aux);
        }
    }
    fclose(arquivo);
    arquivo = NULL;
    destroi_lista_encadeada(lista_usuarios);
    return 0;
}
