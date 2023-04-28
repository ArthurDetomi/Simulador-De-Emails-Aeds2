#include "email_operacoes.h"
#include "lista_array.h"
#include "lista_encadeada.h"
#include "usuario_operacoes.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    lista_encadeada lista_usuarios = cria_lista_encadeada();
    for (int i = 0; i < 10; i++) {
        bool cadastrou = cadastrar_novo_usuario(lista_usuarios, i);
    }
    char msg[] = "ola coisa louca";
    for (int i = 0; i < 10; i++) {
        enviar_email_para_usuario(lista_usuarios, 3, msg, i);
    }

    usuario usuario3; 
    lista_encadeada_get_elemento_por_id(lista_usuarios, 3, &usuario3);

    printf("printf emails\n");
    for (int i = 0; i < 10; i++) {
        printf("prioridade = %d msg=%s\n", lista_array_get(usuario3.caixa_de_entrada, i).prioridade, lista_array_get(usuario3.caixa_de_entrada, i).mensagem);
    }


    for(int i = 0; i < 10; i++) {
        remover_usuario(lista_usuarios, i);
    }
    destroi_lista_encadeada(lista_usuarios);
}
