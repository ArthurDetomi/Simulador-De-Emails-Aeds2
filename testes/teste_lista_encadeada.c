#include "lista_encadeada.h"

#include <assert.h>
#include <stdio.h>
#define QTD 100

int main(void) {
    lista_encadeada lista = cria_lista_encadeada();
    assert(lista->proximo == NULL);

    for (int i = 0; i < QTD; i++) {
        lista_encadeada_add_item(lista, i + 1);
    }
    assert(lista_encadeada_tamanho(lista) == QTD);

    printf("Tamanho da lista: %d\n", lista_encadeada_tamanho(lista));
    lista_encadeada_remove_item(lista, 67);

    printf("Tamanho da lista: %d\n", lista_encadeada_tamanho(lista));
    assert(lista_encadeada_tamanho(lista) == QTD - 1);

    lista_encadeada_percorre_itens(lista);

    destroi_lista_encadeada(lista);
    return 0;
}