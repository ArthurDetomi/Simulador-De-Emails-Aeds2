#include "lista_encadeada.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    lista_encadeada lista = cria_lista_encadeada();
    lista_encadeada_add_item(lista, 1);
    lista_encadeada_add_item(lista, 2);
    lista_encadeada_add_item(lista, 3);
    assert(lista_encadeada_tamanho(lista) == 3);

    printf("Tamanho da lista: %d\n", lista_encadeada_tamanho(lista));
    lista_encadeada_remove_item(lista, 2);

    printf("Tamanho da lista: %d\n", lista_encadeada_tamanho(lista));
    assert(lista_encadeada_tamanho(lista) == 2);

    lista_encadeada_percorre_itens(lista);

    destroi_lista_encadeada(lista);
    return 0;
}