#include "lista_array.h"
#include "usuario_operacoes.h"
#include "functions_utils.h"

#include <stdio.h>
#include <stdlib.h>

// Cadastra novo usuario
bool cadastrar_novo_usuario(lista_encadeada lista, int id) {
    if (!id_enviado_eh_valido(id)) {
        return false;
    }
    if (lista_encadeada_esta_vazia(lista)) {
        usuario novo_usuario;
        novo_usuario.id = id;
        novo_usuario.caixa_de_entrada = cria_lista_array();
        lista_encadeada_add_elemento(lista, novo_usuario);
        return true;
    }
    if (lista_encadeada_checa_elemento_esta_presente(lista, id)) {
        printf("ERRO:CONTA %d JA EXISTENTE\n", id);
        return false;
    }
    usuario novo_usuario;
    novo_usuario.id = id;

    // Registra novo usuário  e cria nova caixa de entrada para ele
    novo_usuario.caixa_de_entrada = cria_lista_array();
    lista_encadeada_add_elemento(lista, novo_usuario);
    

    printf("OK: CONTA %d CADASTRADA\n", id);
    return true;
}

// Remove usuario e limpa sua caixa de entrada
bool remover_usuario(lista_encadeada lista, int id) {
    if (!id_enviado_eh_valido(id)) {
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
        printf("Falha ao remover usuário\n");
        return false;
    }

    // libera a memoria de sua caixa de mensagem e remove elemento,
    // desalocando-o
    if (!lista_array_esta_vazia(usuario_deletar.caixa_de_entrada)) {
        destroi_lista_array(usuario_deletar.caixa_de_entrada);
    }
 
    lista_encadeada_remove_elemento(lista, id);
    printf("OK: CONTA %d REMOVIDA\n", id);
    return true;
}