#include "lista_array.h"
#include "usuario_operacoes.h"

#include <stdio.h>

// Cadastra novo usuario
bool cadastrar_novo_usuario(lista_encadeada lista, int id) {
    if (id_enviado_eh_valido(id)) {
        return false;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        usuario novo_usuario;
        novo_usuario.id = id;
        novo_usuario.caixa_de_entrada = cria_lista_array();
        lista_encadeada_add_elemento(novo_usuario);
        return true;
    }
    if (lista_encadeada_checa_elemento_esta_presente(id)) {
        return false;
    }
    usuario novo_usuario;
    novo_usuario.id = id;
    novo_usuario.caixa_de_entrada = cria_lista_array();
    lista_encadeada_add_elemento(novo_usuario);
    return true;
}

bool remover_usuario(lista_encadeada lista, int id) {
    if (id_enviado_eh_valido(id)) {
        return false;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        printf("Impossivel remover, lista está vazia\n");
        return false;
    }
    if (lista_encadeada_checa_elemento_esta_presente(id)) {
        printf("usuario para remoção não existe") return false;
    }
    lista_encadeada_remove_elemento(lista, id);
    return true;
}

bool id_enviado_eh_valido(int id) {
    if (id < 0 || id > 10000) {
        printf("Parametro passado no id = %d invalido\n", id);
        return false;
    }
    return true;
}