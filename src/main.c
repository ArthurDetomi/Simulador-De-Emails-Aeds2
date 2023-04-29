#include "lista_encadeada.h"
#include "servidor_email_operacoes.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
            liberar_memoria_programa(arquivo, lista_usuarios);
            exit(1);
        }
        int cod_operacao = operacao_desejada(operacao);
        if (cod_operacao == OPERACAO_INVALIDA) {
            printf("FORMATO ARQUIVO INVALIDO");
            liberar_memoria_programa(arquivo, lista_usuarios);
            exit(1);
        }

        if (lista_usuarios == NULL) {
            lista_usuarios = cria_lista_encadeada();
        }

        realiza_operacoes_servidor(cod_operacao, lista_usuarios, arquivo);
    }
    liberar_memoria_programa(arquivo, lista_usuarios);
    return 0;
}
