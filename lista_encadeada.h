#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <stdbool.h>
#include "lista_array.h"

typedef int chave;

typedef usuario elemento;

typedef struct celula {
    elemento elemento;
    struct celula *proximo;
} celula;

typedef struct celula *lista_encadeada;

// cria uma nova lista
lista_encadeada cria_lista_encadeada();

// Adiciona um elemento ao final da lista
void lista_encadeada_add_elemento(lista_encadeada lista, elemento elemento_param);

// Verifica se a lista está vazia
bool lista_encadeada_esta_vazia(lista_encadeada lista);

// Remove o primeiro elemento da lista encadeada
void lista_encadeada_remove_elemento(lista_encadeada lista, elemento elemento_param);

// Retorna a quantidade de itens presente na lista
int lista_encadeada_tamanho(lista_encadeada lista);

// Libera o espaço alocado da lista
void destroi_lista_encadeada(lista_encadeada lista);

// Percorre cada elemento da lista
void lista_encadeada_percorre_itens(lista_encadeada lista);

#endif
