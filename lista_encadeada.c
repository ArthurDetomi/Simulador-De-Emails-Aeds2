#include "lista_encadeada.h"
#include "functions_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

celula *cria_celula(elemento elemento_param) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    verifica_estouro_memoria(nova_celula, "cria_celula()");
    nova_celula->elemento = elemento_param;
    nova_celula->proximo = NULL;
    return nova_celula;
}

lista_encadeada cria_lista_encadeada() { 
    elemento elemento_vazio;
    return cria_celula(elemento_vazio); 
}

void lista_encadeada_add_elemento(lista_encadeada lista, elemento elemento_param) {
    if (lista_encadeada_esta_vazia(lista)) {
        celula *nova_celula = cria_celula(elemento_param);
        lista->proximo = nova_celula;
        return;
    }

    celula *celula_aux = lista->proximo;
    celula *nova_celula = cria_celula(elemento_param);
    lista->proximo = nova_celula;
    lista->proximo->proximo = celula_aux;
}

bool lista_encadeada_esta_vazia(lista_encadeada lista) {
    return (lista->proximo == NULL);
}

void lista_encadeada_remove_primeiro_da_lista(lista_encadeada lista) {
    if (lista_encadeada_esta_vazia(lista)) {
        printf("Lista esta vazia\n");
    }
    celula *celula_anterior = lista->proximo;
    lista->proximo = lista->proximo->proximo;
    free(celula_anterior);
}

void lista_encadeada_remove_elemento(lista_encadeada lista, elemento elemento_param) {
    if (lista_encadeada_esta_vazia(lista)) {
        printf("Lista vazia");
        return;
    }
    celula *celula_atual = lista->proximo;
    celula *celula_anterior = lista;
    while (celula_atual != NULL) {
        if (celula_atual->elemento.id == elemento_param.id) {
            celula_anterior->proximo = celula_atual->proximo;
            free(celula_atual);
            return;
        }
        celula_anterior = celula_atual;
        celula_atual = celula_atual->proximo;
    }
    printf("elemento não encontrado na lista \n");
}

int lista_encadeada_tamanho(lista_encadeada lista) {
    if (lista_encadeada_esta_vazia(lista)) {
        return 0;
    }
    int tamanho = 0;
    while (lista->proximo != NULL) {
        tamanho++;
        lista = lista->proximo;
    }
    return tamanho;
}

void destroi_lista_encadeada(lista_encadeada lista) {
    while (lista->proximo != NULL) {
        lista_encadeada_remove_primeiro_da_lista(lista);
    }
    free(lista);
}