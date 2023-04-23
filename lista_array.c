#include "functions_utils.h"
#include "lista_array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

lista_array *cria_lista_array(void) {
    lista_array *l = (lista_array *)malloc(sizeof(lista_array));
    verifica_estouro_memoria(l, "cria_lista() - modulo 'lista_dinamica.h'");
    l->tamanho = 0;
    l->capacidade = 0;
    return l;
}

bool lista_array_esta_vazia(lista_array *lista) {
    if (lista == NULL) {
        return true;
    }
    else if (lista->tamanho <= 0) {
        return true;
    }
    return false;
}

void destroi_lista_array(lista_array *lista) {
    if (lista == NULL) {
        printf("lista esta nula");
        return;
    }
    if (lista->itens != NULL) {
        free(lista->itens);
    }
    free(lista);
}

void lista_array_add(lista_array *lista, item item_param) {
    if (lista == NULL) {
        printf("lista esta nula");
        return;
    }
    if (lista->itens == NULL) {
        int nova_capacidade = 1;
        lista->itens = (item *)malloc(nova_capacidade * sizeof(item));
        verifica_estouro_memoria(lista->itens, "lista_array_add()");
        lista->capacidade = nova_capacidade;
    }
    else if (lista->tamanho >= lista->capacidade) {
        int nova_capacidade
            = (lista->capacidade > 0) ? lista->capacidade * 2 : 1;
        lista->itens = realloc(lista->itens, nova_capacidade * sizeof(item));
        verifica_estouro_memoria(lista->itens, "lista_array_add()");
        lista->capacidade = nova_capacidade;
    }
    int posicao_final = lista->tamanho;
    lista->itens[posicao_final] = item_param;
    lista->tamanho++;
}

int lista_array_tamanho(lista_array *lista) {
    if (lista == NULL || lista->itens == NULL) {
        printf("lista esta nula");
        return -1;
    }
    return lista->tamanho;
}

int lista_array_capacidade(lista_array *lista) {
    if (lista == NULL) {
        printf("lista esta nula");
        return -1;
    }
    return lista->capacidade;
}

void lista_array_set(lista_array *lista, int indice, item item) {
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

bool lista_array_remove(lista_array *lista, int indice) {
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

item lista_array_get(lista_array *lista, int indice) {
    item item;
    if (lista == NULL) {
        printf("lista esta nula");
        return item;
    }
    if (indice >= lista->tamanho || indice < 0) {
        printf("Indice inserido invalido");
        return item;
    }
    return lista->itens[indice];
}