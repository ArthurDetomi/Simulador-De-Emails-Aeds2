#include "functions_utils.h"
#include "lista_array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("lista esta nula\n");
        return;
    }
    if (lista->itens != NULL) {
        for(int i = 0; i < lista_array_tamanho(lista); i++) {
            char *str = lista->itens[i].mensagem;
            if (str != NULL)
                free(str);
        }
        free(lista->itens);
        lista->itens = NULL;
    }
    free(lista);
    lista = NULL;
}

void lista_array_add(lista_array *lista, item item_param) {
    if (lista == NULL) {
        printf("lista esta nula\n");
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
    if (strlen(item_param.mensagem) <= 0) {
        lista->itens[posicao_final].mensagem = NULL;
    }
    lista->tamanho++;
}

void adiciona_item_indice_especifico(lista_array *lista, item item_param, int indice) {
    for (int i = lista->tamanho - 1; i >= indice ; i--) {
        lista->itens[i + 1] = lista->itens[i];
    }
    lista->tamanho++;
    lista->itens[indice] = item_param;
}

void lista_array_add_com_prioridade(lista_array *lista, item item_param) {
    if (lista == NULL) {
        printf("lista esta nula\n");
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
        lista->itens = (item *)realloc(lista->itens, nova_capacidade * sizeof(item));
        verifica_estouro_memoria(lista->itens, "lista_array_add()");
        lista->capacidade = nova_capacidade;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        item item_atual = lista->itens[i];
        if (item_param.prioridade > item_atual.prioridade) {
            adiciona_item_indice_especifico(lista, item_param, i);
            return;
        }else if (item_param.prioridade == item_atual.prioridade) {
            adiciona_item_indice_especifico(lista, item_param, i + 1);
            return;
        }
    }

    int posicao_final = lista->tamanho;
    lista->itens[posicao_final] = item_param;
    if (strlen(item_param.mensagem) <= 0) {
        lista->itens[posicao_final].mensagem = NULL;
    }
    lista->tamanho++;
    return;
}

int lista_array_tamanho(lista_array *lista) {
    if (lista == NULL || lista->itens == NULL) {
        printf("lista esta nula\n");
        return -1;
    }
    return lista->tamanho;
}

int lista_array_capacidade(lista_array *lista) {
    if (lista == NULL) {
        printf("lista esta nula\n");
        return -1;
    }
    return lista->capacidade;
}

void lista_array_set(lista_array *lista, int indice, item item) {
    if (lista == NULL) {
        printf("lista esta nula\n");
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
        printf("lista esta nula\n");
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
        printf("lista esta nula\n");
        return item;
    }
    if (indice >= lista->tamanho || indice < 0) {
        printf("Indice inserido invalido");
        return item;
    }
    return lista->itens[indice];
}

void percorre_lista_array_prioridades(lista_array *lista) {
    printf("chegou aqui\n");
    for (int i = 0; i < lista_array_tamanho(lista); i++) {
        printf("priori msg %d = %d \n", i, lista->itens->prioridade);
    }
}