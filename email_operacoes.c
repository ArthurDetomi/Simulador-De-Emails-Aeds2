#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void preenche_email(email *email_envio, int prioridade, char *msg) {
    int tam = strlen(msg);
    if (tam > 0) {
        email_envio->mensagem = (char *)malloc(tam + 1);
        verifica_estouro_memoria(email_envio->mensagem, "preenche_email()\n");
        strcpy(email_envio->mensagem, msg);
    }
    else {
        email_envio->mensagem = NULL;
    }
    email_envio->prioridade = prioridade;
}

// Entrega mensagem para o usuário com id correspondente
respostas_servidor enviar_email_para_usuario(
    lista_encadeada lista_usuarios, int id_usuario, char *msg, int priori_msg
) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return DADOS_INVALIDOS;
    }
    if (priori_msg < 0 || priori_msg > 9) {
        return DADOS_INVALIDOS;
    }
    if (lista_encadeada_esta_vazia(lista_usuarios)) {
        return DADOS_INVALIDOS;
    }

    usuario usuario_selecionado;
    if (!lista_encadeada_get_elemento_por_id(
            lista_usuarios, id_usuario, &usuario_selecionado
        ))
    {
        return CONTA_NAO_EXISTE;
    }

    email novo_email;
    preenche_email(&novo_email, priori_msg, msg);

    if (lista_array_esta_vazia(usuario_selecionado.caixa_de_entrada)) {
        lista_array_add(usuario_selecionado.caixa_de_entrada, novo_email);
        return MENSAGEM_ENTREGUE;
    }

    lista_array_add_com_prioridade(
        usuario_selecionado.caixa_de_entrada, novo_email
    );
    return MENSAGEM_ENTREGUE;
}

respostas_servidor consulta_id_msg_priori(
    lista_encadeada lista_usuarios, int id_usuario, email *email_consulta
) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return DADOS_INVALIDOS;
    }
    if (lista_encadeada_esta_vazia(lista_usuarios)) {
        return DADOS_INVALIDOS;
    }

    usuario usuario_selecionado;
    if (!lista_encadeada_get_elemento_por_id(
            lista_usuarios, id_usuario, &usuario_selecionado
        ))
    {
        return CONTA_NAO_EXISTE;
    }

    lista_array *caixa_de_entrada_usuario = usuario_selecionado.caixa_de_entrada;
    if (lista_array_esta_vazia(caixa_de_entrada_usuario)) {
        return CAIXA_DE_ENTRADA_VAZIA;
    }

    *email_consulta = lista_array_get(caixa_de_entrada_usuario, 0);
    return CONSULTA_REALIZADA;
}

void remove_email_ja_consultado(
    lista_encadeada lista_usuarios, int id_usuario
) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return;
    }
    if (lista_encadeada_esta_vazia(lista_usuarios)) {
        return;
    }

    usuario usuario_selecionado;
    if (!lista_encadeada_get_elemento_por_id(
            lista_usuarios, id_usuario, &usuario_selecionado
        ))
    {
        return;
    }
    bool removeu = lista_array_remove(usuario_selecionado.caixa_de_entrada, 0);
}