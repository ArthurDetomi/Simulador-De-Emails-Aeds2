#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include "lista_array.h"

#include <stdbool.h>

// elemento passado deve possuir id, logo deve ser uma struct
typedef usuario elemento;

typedef struct celula {
    elemento elemento;
    struct celula *proximo;
} celula;

typedef struct celula *lista_encadeada;

// cria uma nova lista
lista_encadeada cria_lista_encadeada();

// Adiciona um elemento ao final da lista
void lista_encadeada_add_elemento(
    lista_encadeada lista, elemento elemento_param
);

// Verifica se a lista está vazia
bool lista_encadeada_esta_vazia(lista_encadeada lista);

// Remove o elemento com o id passado
void lista_encadeada_remove_elemento(lista_encadeada lista, int id_elemento);

// Retorna a quantidade de itens presente na lista
int lista_encadeada_tamanho(lista_encadeada lista);

// Libera o espaço alocado da lista
void destroi_lista_encadeada(lista_encadeada lista);

/* Percorre a lista encontra o elemento com o respectivo id e verifica se ele se
 * encontra ou não na lista*/
bool lista_encadeada_checa_elemento_esta_presente(
    lista_encadeada lista, int id
);

// Passa o elemento pesquisado atraves de um ponteiro, retorna se operação
// falhou ou não
bool lista_encadeada_get_elemento_por_id(
    lista_encadeada lista, int id, elemento *elemento
);

#endif
