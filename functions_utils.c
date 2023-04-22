#include "functions_utils.h"

#include <stdio.h>

void verifica_estouro_memoria(void *ponteiro, char *msg) {
    if (ponteiro == NULL) {
        printf("%s falha ao alocar memoria na função\n", msg);
    }
    return;
}