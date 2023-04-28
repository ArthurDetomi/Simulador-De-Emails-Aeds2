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
    for (int i = 0; i < 100; i++) {
        entregar_email_para_usuario(lista_usuarios, 3, msg, 3);
        entregar_email_para_usuario(lista_usuarios, 3, msg, 2);
        entregar_email_para_usuario(lista_usuarios, 3, msg, 2);
        entregar_email_para_usuario(lista_usuarios, 3, msg, 2);
        entregar_email_para_usuario(lista_usuarios, 3, msg, 2);
    }


    for(int i = 0; i < 10; i++) {
        remover_usuario(lista_usuarios, i);
    }
    destroi_lista_encadeada(lista_usuarios);
}
