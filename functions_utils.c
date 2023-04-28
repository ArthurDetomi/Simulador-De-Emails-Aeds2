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
        printf("Parametro passado no id = %d invalido\n", id);
        return 0;
    }
    return 1;
}

void mensagens_servidor_resposta(int codigo_resposta, int id_usuario, char *msg) {
    switch(codigo_resposta) {
        case 200:
            printf("CONSULTA %d: %s\n", id_usuario, msg);
        break;
        case 202:
            printf("OK: MENSAGEM PARA %d ENTREGUE\n", id_usuario);
        break;
        case 201:
            printf("OK: CONTA %d CADASTRADA\n", id_usuario);
        break;
        case 204:
            printf("OK: CONTA %d REMOVIDA\n", id_usuario);
        break;
        case 400:
            printf("ERRO: DADOS PASSADOS INVALIDOS\n");
        break;
        case 401:
            printf("ERRO:CONTA %d JA EXISTENTE\n", id_usuario);
        break;
        case 404:
            printf("ERRO: CONTA %d NAO EXISTE\n", id_usuario);
        break;
        case 406:
            printf("CONSULTA %d: CAIXA DE ENTRADA VAZIA\n", id_usuario);
        break;
        default:
            printf("ERRO: ERRO INESPERADO\n");
        break;
    }
}