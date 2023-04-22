#include "lista_inteiros.h"
#include "lista_encadeada.h"

#include <assert.h>
#include <stdio.h>

int main() {
    lista_inteiros *lista = cria_lista();
    lista_inteiro_esta_vazia(lista);
    assert(lista != NULL && lista->tamanho == 0);

    printf("lista capacidade = %d\n", lista_inteiros_capacidade(lista));
    assert(lista_inteiros_capacidade(lista) == 0);

    if (lista_inteiro_esta_vazia(lista)) {
        printf("Lista está vazia\n");
    }

    for (int i = 0; i < 10; i++) {
        item item = i;
        lista_inteiros_add(lista, item);
    }
    printf("lista capacidade = %d\n", lista_inteiros_capacidade(lista));
    int lista_tamanho = lista_inteiros_tamanho(lista);
    assert(lista_tamanho == 10);

    lista_inteiros_set(lista, 0, 10);

    printf("Imprimindo lista\n");
    for (int i = 0; i < lista_tamanho; i++) {
        printf("Item = %d\n", lista_inteiros_get(lista, i));
    }

    if (lista_inteiros_remove(lista, 0)) {
        printf("verdade\n");
    }

    printf("tamanh = %d \n", lista_inteiros_tamanho(lista));
    assert(lista_inteiros_tamanho(lista) == 9);

    printf("Imprimindo lista\n");
    for (int i = 0; i < lista_inteiros_tamanho(lista); i++) {
        printf("Item = %d\n", lista_inteiros_get(lista, i));
    }

    destroi_lista(lista);
}