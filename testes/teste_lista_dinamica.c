#include "lista_array.h"

#include <assert.h>
#include <stdio.h>
#include <time.h>

int main() {
    lista_array *lista = cria_lista_array();
    lista_array_esta_vazia(lista);
    assert(lista != NULL && lista->tamanho == 0);

    printf("lista capacidade = %d\n", lista_array_capacidade(lista));
    assert(lista_array_capacidade(lista) == 0);

    if (lista_array_esta_vazia(lista)) {
        printf("Lista está vazia\n");
    }

    for (int i = 0; i < 10; i++) {
        time_t agora;
        time(&agora);
        email email_envio = { i, agora };
        lista_array_add(lista, email_envio);
    }
    printf("lista capacidade = %d\n", lista_array_capacidade(lista));
    
    int lista_tamanho = lista_array_tamanho(lista);
    assert(lista_tamanho == 10);

    time_t agora;
    time(&agora);
    int id = 99;
    email email_envio = { id, agora };
    lista_array_set(lista, 0, email_envio);


    printf("Imprimindo lista\n");
    for (int i = 0; i < lista_tamanho; i++) {
        email email_temp = lista_array_get(lista, i);
        printf("email: priori= %d, tempo = %ld\n", email_temp.prioridade, email_temp.data_hora_envio);
    }

    if (lista_array_remove(lista, 0)) {
        printf("removeu\n");
    } else {
        printf("Não removeu");
    }

    printf("tamanho lista = %d \n", lista_array_tamanho(lista));
    assert(lista_array_tamanho(lista) == 9);

    printf("Imprimindo lista\n");
    for (int i = 0; i < lista_array_tamanho(lista); i++) {
        email email_temp = lista_array_get(lista, i);
        printf("email: priori= %d, tempo = %ld\n", email_temp.prioridade, email_temp.data_hora_envio);
    }

    destroi_lista_array(lista);
}