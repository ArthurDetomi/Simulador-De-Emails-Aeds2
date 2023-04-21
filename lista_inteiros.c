#include "lista_inteiros.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

lista_inteiros *cria_lista(void) {
    lista_inteiros *l = (lista_inteiros *)malloc(sizeof(lista_inteiros));
    l->tamanho = 0;
    l->capacidade = 0;
    return l;
}

bool lista_inteiro_esta_vazia(lista_inteiros *lista) {
    if (lista == NULL) {
        return true;
    }
    else if (lista->tamanho <= 0) {
        return true;
    }
    return false;
}

void destroi_lista(lista_inteiros *lista) {
    if (lista == NULL) {
        printf("lista esta nula");
        return;
    }
    if (lista->itens != NULL) {
        free(lista->itens);
    }
    free(lista);
}

void lista_inteiros_add(lista_inteiros *lista, item item_param) {
    if (lista == NULL) {
        printf("lista esta nula");
        return;
    }
    if (lista->itens == NULL) {
        int nova_capacidade = 1;
        lista->itens = (item *)malloc(nova_capacidade * sizeof(item));
        lista->capacidade = nova_capacidade;
    }
    else if (lista->tamanho > lista->capacidade) {
        int nova_capacidade
            = (lista->capacidade > 0) ? lista->capacidade * 2 : 1;
        lista->itens = realloc(lista->itens, nova_capacidade * sizeof(item));
        lista->capacidade = nova_capacidade;
    }
    int posicao_final = lista->tamanho;
    lista->itens[posicao_final] = item_param;
    lista->tamanho++;
}

int lista_inteiros_tamanho(lista_inteiros *lista) {
    if (lista == NULL || lista->itens == NULL) {
        printf("lista esta nula");
        return -1;
    }
    return lista->tamanho;
}

int lista_inteiros_capacidade(lista_inteiros *lista) {
    if (lista == NULL) {
        printf("lista esta nula");
        return -1;
    }
    return lista->capacidade;
}

void lista_inteiros_set(lista_inteiros *lista, int indice, item item) {
    if (lista == NULL) {
        printf("lista esta nula");
        return;
    }
    if (indice >= lista->tamanho || indice < 0) {
        printf("Indice inserido invalido");
        return;
    }
    lista->itens[indice] = item;
}

bool lista_inteiros_remove(lista_inteiros *lista, int indice) {
    if (lista == NULL) {
        printf("lista esta nula");
        return false;
    }
    if (indice >= lista->tamanho || indice < 0) {
        printf("Indice inserido invalido");
        return false;
    }
    if (indice == lista->tamanho - 1) {
        item item;
        lista->itens[indice] = item;
    }
    else {
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->itens[i] = lista->itens[i + 1];
        }
    }
    lista->tamanho--;
    return true;
}

int lista_inteiros_get(lista_inteiros *lista, int indice) {
    if (lista == NULL) {
        printf("lista esta nula");
        return -1;
    }
    if (indice >= lista->tamanho || indice < 0) {
        printf("Indice inserido invalido");
        return -1;
    }
    return lista->itens[indice];
}