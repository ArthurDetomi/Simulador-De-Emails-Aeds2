#include "lista_array.h"
#include "usuario_operacoes.h"

#include <stdio.h>

int id_enviado_eh_valido(int id) {
    if (id < 0 || id > 10000) {
        printf("Parametro passado no id = %d invalido\n", id);
        return 0;
    }
    return 1;
}

// Cadastra novo usuario
bool cadastrar_novo_usuario(lista_encadeada lista, int id) {
    if (id_enviado_eh_valido(id)) {
        return false;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        usuario novo_usuario;
        novo_usuario.id = id;
        lista_encadeada_add_elemento(lista, novo_usuario);
        lista_array *lista_array_nova = cria_lista_array();
        novo_usuario.caixa_de_entrada = lista_array_nova;
        return true;
    }
    if (lista_encadeada_checa_elemento_esta_presente(lista, id)) {
        printf("ERRO:CONTA %d JA EXISTENTE\n", id);
        return false;
    }
    usuario novo_usuario;
    novo_usuario.id = id;
    lista_encadeada_add_elemento(lista, novo_usuario);
    lista_array *lista_array_nova = cria_lista_array();
    novo_usuario.caixa_de_entrada = lista_array_nova;
    printf("OK: CONTA %d CADASTRADA\n", id);
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
    if (!lista_encadeada_checa_elemento_esta_presente(lista, id)) {
        printf("ERRO: CONTA %d NAO EXISTE\n", id);
        return false;
    }
    usuario usuario_deletar;
    if (!lista_encadeada_get_elemento_por_id(lista, id, &usuario_deletar)) {
        printf("Falha ao remover usuário");
        return false;
    }

    // libera a memoria de sua caixa de mensagem e remove elemento,
    // desalocando-o
    destroi_lista_array(usuario_deletar.caixa_de_entrada);
    lista_encadeada_remove_elemento(lista, id);

    printf("OK: CONTA %d REMOVIDA\n", id);
    return true;
}
