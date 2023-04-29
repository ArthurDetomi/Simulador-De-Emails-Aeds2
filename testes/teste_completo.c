#include "email_operacoes.h"
#include "lista_array.h"
#include "lista_encadeada.h"
#include "usuario_operacoes.h"
#include "functions_utils.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    lista_encadeada lista_usuarios = cria_lista_encadeada();
    for (int i = 0; i < 10; i++) {
        int codigo_resposta = cadastrar_novo_usuario(lista_usuarios, i);
        mensagens_servidor_resposta(codigo_resposta, i, "");
    }
    char msg[] = "ola coisa louca";
    for (int i = 0; i < 10; i++) {
        int codigo_envio = enviar_email_para_usuario(lista_usuarios, 3, msg, i);
        mensagens_servidor_resposta(codigo_envio, 3, NULL);
    }

    char msg2[] = "verifi";
    int c = enviar_email_para_usuario(lista_usuarios, 3, msg2, 3);
    mensagens_servidor_resposta(c, 3, NULL);
    char msg3[] = "verifi2";
    c = enviar_email_para_usuario(lista_usuarios, 3, msg3, 3);
    mensagens_servidor_resposta(c, 3, NULL);
    char ms4[] = "verifi3";
    c = enviar_email_para_usuario(lista_usuarios, 3, ms4, 9);
    mensagens_servidor_resposta(c, 3, NULL);

    usuario usuario3; 
    lista_encadeada_get_elemento_por_id(lista_usuarios, 3, &usuario3);

    for (int i = 0; i < 13; i++) {
        printf("prioridade = %d msg=%s\n", lista_array_get(usuario3.caixa_de_entrada, i).prioridade, lista_array_get(usuario3.caixa_de_entrada, i).mensagem);
    }


    printf("consulta emails\n");
    for (int i = 0; i < 13; i++) {
        email email_requisicao;
        int resposta = consulta_id_msg_priori(lista_usuarios, 3, &email_requisicao);
        mensagens_servidor_resposta(resposta, 3, email_requisicao.mensagem);
        remove_email_ja_consultado(lista_usuarios, 3);
        // printf("prioridade = %d msg=%s\n", lista_array_get(usuario3.caixa_de_entrada, i).prioridade, lista_array_get(usuario3.caixa_de_entrada, i).mensagem);
    }

    for(int i = 0; i < 10; i++) {
        int codigo_remover_resp = remover_usuario(lista_usuarios, i);
        mensagens_servidor_resposta(codigo_remover_resp, i, NULL);
    }
    destroi_lista_encadeada(lista_usuarios);
}
