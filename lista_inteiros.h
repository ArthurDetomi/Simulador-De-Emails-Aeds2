typedef int dados;

typedef struct{
    int tamanho;       // tamanho atual da lista
    int capacidade;   // capacidade total da lista
    dados* dados;      // ponteiro para o array de elementos da lista
}lista_inteiros;

// cria uma nova lista vazia com capacidade inicial
lista_inteiros* cria_lista(int capacity);

// libera a memória alocada pela lista
void destroi_lista(lista_inteiros* list);

// adiciona um elemento no final da lista
void lista_inteiros_add(lista_inteiros* list, int element);

// remove o elemento na posição indicada da lista
void lista_inteiros_removeAt(lista_inteiros* list, int index);

// retorna o elemento na posição indicada da lista
int lista_inteiros_get(lista_inteiros* list, int index);

// altera o valor do elemento na posição indicada da lista
void lista_inteiros_set(lista_inteiros* list, int index, int element);

// retorna o tamanho atual da lista
int lista_inteiros_size(lista_inteiros* list);

// retorna a capacidade total da lista
int lista_inteiros_capacity(lista_inteiros* list);
