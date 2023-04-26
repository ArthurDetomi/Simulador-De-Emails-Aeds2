#include "email_operacoes.h"
#include "functions_utils.h"
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Atribui todos os atributos do email
char* cria_email(email *email, char *msg, int priori_msg) {
    // Atribui mensagem
    int tamanho_msg = strlen(msg);
    email->mensagem = (char *) malloc(tamanho_msg * sizeof(char));
    strcpy(email->mensagem, msg);

    // Atribui hora
    time_t agora;
    time(&agora);
    email->data_hora_envio = agora;

    // Atribui prioridade da mensagem
    email->prioridade = priori_msg;
}

// Entrega mensagem para o usuário com id correspondente
bool entregar_email_para_usuario(lista_encadeada lista, int id_usuario, char *msg, int priori_msg) {
    if (!id_enviado_eh_valido(id_usuario)) {
        return false;
    }

    usuario *usuario_selecionado = (usuario *) malloc(sizeof(usuario));
    if (!lista_encadeada_get_elemento_por_id(lista, id_usuario, usuario_selecionado)) {
        printf("ERRO: CONTA %d NAO EXISTE\n", id_usuario);
        return false;
    }

    
    email *novo_email = (email *) malloc(sizeof(email));
    cria_email(novo_email, msg, priori_msg);

    if (lista_array_esta_vazia(usuario_selecionado->caixa_de_entrada)) {
        lista_array_add(usuario_selecionado->caixa_de_entrada, *novo_email);
        printf("OK: MENSAGEM PARA %d ENTREGUE\n", id_usuario);
        return true;
    }

    lista_array_add_com_prioridade(usuario_selecionado->caixa_de_entrada, *novo_email);
    free(novo_email);
    free(usuario_selecionado);
    return true;
}
