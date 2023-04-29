#include "functions_utils.h"

#include <stdio.h>

void verifica_estouro_memoria(void *ponteiro, char *msg) {
    if (ponteiro == NULL) {
        printf("%s falha ao alocar memoria na função\n", msg);
        ponteiro = NULL;
    }
    return;
}

int id_enviado_eh_valido(int id) {
    if (id < 0 || id > 10000) {
        // id enviado eh invalido
        return 0;
    }
    return 1;
}

void mensagens_servidor_resposta(int codigo_resposta, int id_usuario, char *msg) {
    switch(codigo_resposta) {
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