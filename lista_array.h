#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H
#include <stdbool.h>
#include <time.h>

typedef struct {
    int prioridade;
    char *mensagem;
} email;

typedef email item;

typedef struct {
    int tamanho; // tamanho atual da lista
    int capacidade; // capacidade total da lista
    item *itens; // ponteiro para o array de elementos da lista
} lista_array;

typedef struct {
    int id;
    lista_array *caixa_de_entrada;
} usuario;

// cria uma nova lista vazia com capacidade inicial
lista_array *cria_lista_array(void);

// libera a memória alocada pela lista
void destroi_lista_array(lista_array *lista);
    
// verifica se a lista está vazia
bool lista_array_esta_vazia(lista_array *lista);

// adiciona um elemento no final da lista
void lista_array_add(lista_array *lista, item item);

// remove o elemento na posição indicada da lista
bool lista_array_remove(lista_array *lista, int indice);

// retorna o elemento na posição indicada da lista
item lista_array_get(lista_array *lista, int indice);

// altera o valor do elemento na posição indicada da lista
void lista_array_set(lista_array *lista, int indice, item item);

// retorna o tamanho atual da lista
int lista_array_tamanho(lista_array *lista);

// retorna a capacidade total da lista
int lista_array_capacidade(lista_array *lista);

// Adiciona item com prioridade, ordenando por inserção
void lista_array_add_com_prioridade(lista_array *lista, item item_param);

void percorre_lista_array_prioridades(lista_array *lista);

#endif
