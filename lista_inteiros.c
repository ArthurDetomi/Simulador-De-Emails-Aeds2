#include "lista_inteiros.h"
#include <stdlib.h>

lista_inteiros* cria_lista(int capacidade) {
    lista_inteiros* l = (lista_inteiros*) malloc(sizeof(lista_inteiros));
    
    // necessário para evitar bug na alocação 0 x Z = 0
    capacidade = (capacidade == 0) ? 1 : capacidade;

    l->itens = (item*) malloc(capacidade * sizeof(item));
    l->tamanho = 0;
    l->capacidade = capacidade;
    return l;
}

void destroi_lista(lista_inteiros* lista) {
    if (lista == NULL) {
        return;
    }
    if (lista->itens != NULL) {
        free(lista->itens);
    }
    free(lista);
}

void lista_inteiros_add(lista_inteiros* lista, item item_param) {
    if (lista == NULL || lista->itens == NULL) return;
    if (lista->tamanho < lista->capacidade) {
        int nova_capacidade = lista->capacidade * 2;
        lista->itens = realloc(lista->itens, nova_capacidade * sizeof(item));
        lista->capacidade = nova_capacidade;
    }
    int pos_final = lista->tamanho;
    lista->itens[pos_final] = item_param;
    lista->tamanho++;
}

int lista_inteiros_tamanho(lista_inteiros* lista) {
    if (lista == NULL || lista->itens == NULL) {
        perror("erro: lista está nula");
        return -1;
    }
    return lista->tamanho; 
}