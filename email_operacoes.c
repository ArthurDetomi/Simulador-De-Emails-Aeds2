#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Entrega mensagem para o usuário com id correspondente
bool entregar_email_para_usuario(lista_encadeada lista, int id_usuario, char *msg, int priori_msg) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return false;
    }

    usuario usuario_selecionado;
    if (!lista_encadeada_get_elemento_por_id(lista, id_usuario, &usuario_selecionado)) {
        printf("ERRO: CONTA %d NAO EXISTE\n", id_usuario);
        return false;
    }

    
    email novo_email;
    int tam = strlen(msg);
    if (tam > 0) {
        novo_email.mensagem = (char *) malloc(tam + 1);
        strcpy(novo_email.mensagem, msg);
    } else {
        novo_email.mensagem = NULL;
    }
    
    

    if (lista_array_esta_vazia(usuario_selecionado.caixa_de_entrada)) {
        lista_array_add(usuario_selecionado.caixa_de_entrada, novo_email);
        printf("OK: MENSAGEM PARA %d ENTREGUE\n", id_usuario);
        return true;
    }

    printf("Adicionou com priori\n");
    lista_array_add_com_prioridade(usuario_selecionado.caixa_de_entrada, novo_email);
    return true;
}