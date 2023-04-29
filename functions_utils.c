#include "functions_utils.h"

#include <stdio.h>
#include <string.h>

void verifica_estouro_memoria(void *ponteiro, char *msg) {
    if (ponteiro == NULL) {
        printf("ERRO: %s falha ao alocar memoria na função\n", msg);
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