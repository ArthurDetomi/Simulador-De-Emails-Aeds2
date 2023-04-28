#include "lista_array.h"
#include "usuario_operacoes.h"
#include "functions_utils.h"

#include <stdio.h>
#include <stdlib.h>

// Cadastra novo usuario
int cadastrar_novo_usuario(lista_encadeada lista, int id) {
    if (!id_enviado_eh_valido(id)) {
        return 400;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        usuario novo_usuario;
        novo_usuario.id = id;
        novo_usuario.caixa_de_entrada = cria_lista_array();
        lista_encadeada_add_elemento(lista, novo_usuario);
        return 201;
    }
    if (lista_encadeada_checa_elemento_esta_presente(lista, id)) {
        return 401;
    }
    usuario novo_usuario;
    novo_usuario.id = id;

    // Registra novo usuário  e cria nova caixa de entrada para ele
    novo_usuario.caixa_de_entrada = cria_lista_array();
    lista_encadeada_add_elemento(lista, novo_usuario);

    return 201;
}

// Remove usuario e limpa sua caixa de entrada
int remover_usuario(lista_encadeada lista, int id) {
    if (!id_enviado_eh_valido(id)) {
        return 400;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        return 400;
    }
    if (!lista_encadeada_checa_elemento_esta_presente(lista, id)) {
        return 404;
    }
    usuario usuario_deletar;
    if (!lista_encadeada_get_elemento_por_id(lista, id, &usuario_deletar)) {
        return 400;
    }

    // libera a memoria de sua caixa de mensagem e remove elemento,
    // desalocando-o
    destroi_lista_array(usuario_deletar.caixa_de_entrada);
    
    lista_encadeada_remove_elemento(lista, id);
    return 204;
}