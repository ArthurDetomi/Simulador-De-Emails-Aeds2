#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void preenche_email(email *email_envio, int prioridade, char *msg) {
    int tam = strlen(msg);
    if (tam > 0) {
        email_envio->mensagem = (char *) malloc(tam + 1);
        verifica_estouro_memoria(email_envio->mensagem, "preenche_email()\n");
        strcpy(email_envio->mensagem, msg);
    } else {
        email_envio->mensagem = NULL;
    }
    email_envio->prioridade = prioridade;
}

// Entrega mensagem para o usuário com id correspondente
bool enviar_email_para_usuario(lista_encadeada lista, int id_usuario, char *msg, int priori_msg) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return false;
    }

    usuario usuario_selecionado;
    if (!lista_encadeada_get_elemento_por_id(lista, id_usuario, &usuario_selecionado)) {
        printf("ERRO: CONTA %d NAO EXISTE\n", id_usuario);
        return false;
    }

    
    email novo_email;
    preenche_email(&novo_email, priori_msg, msg);    
    
    if (lista_array_esta_vazia(usuario_selecionado.caixa_de_entrada)) {
        lista_array_add(usuario_selecionado.caixa_de_entrada, novo_email);
        printf("OK: MENSAGEM PARA %d ENTREGUE\n", id_usuario);
        return true;
    }

    printf("Adicionou com priori\n");
    lista_array_add_com_prioridade(usuario_selecionado.caixa_de_entrada, novo_email);
    return true;
}