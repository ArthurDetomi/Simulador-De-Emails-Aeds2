#ifndef LISTA_INTEIROS_H
#define LISTA_INTEIROS_H
#include <stdbool.h>
typedef int item;

typedef struct {
    int tamanho; // tamanho atual da lista
    int capacidade; // capacidade total da lista
    item *itens; // ponteiro para o array de elementos da lista
} lista_inteiros;

// cria uma nova lista vazia com capacidade inicial
lista_inteiros *cria_lista(void);

// libera a memória alocada pela lista
void destroi_lista(lista_inteiros *lista);

// verifica se a lista está vazia
bool lista_inteiro_esta_vazia(lista_inteiros *lista);

// adiciona um elemento no final da lista
void lista_inteiros_add(lista_inteiros *lista, item item);

// remove o elemento na posição indicada da lista
bool lista_inteiros_remove(lista_inteiros *lista, int indice);

// retorna o elemento na posição indicada da lista
int lista_inteiros_get(lista_inteiros *lista, int indice);

// altera o valor do elemento na posição indicada da lista
void lista_inteiros_set(lista_inteiros *lista, int indice, item item);

// retorna o tamanho atual da lista
int lista_inteiros_tamanho(lista_inteiros *lista);

// retorna a capacidade total da lista
int lista_inteiros_capacidade(lista_inteiros *lista);

#endif
