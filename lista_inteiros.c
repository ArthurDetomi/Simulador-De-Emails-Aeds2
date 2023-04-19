#include "lista_inteiros.h"
#include <stdlib.h>

lista_inteiros* cria_lista(int capacidade) {
    lista_inteiros* l = (lista_inteiros*) malloc(sizeof(lista_inteiros));
    
    // necessário para evitar bug na alocação 0 x Z = 0
    capacidade = (capacidade == 0) ? 1 : capacidade;

    l->dados = (dados *) malloc(capacidade * sizeof(dados));
    l->tamanho = 0;
    l->capacidade = capacidade;
    return l;
}

void destroi_lista(lista_inteiros* lista) {
    if (lista == NULL) {
        return;
    }
    free(lista->dados);
    free(lista);
}

void lista_inteiros_add(lista_inteiros* lista, int dado) {
    if (lista == NULL) return;
    if (lista->tamanho < lista->capacidade) {
        lista->dados = realloc(lista->dados, lista->capacidade * 2);
    }
    int pos_final = lista->tamanho - 1;

}