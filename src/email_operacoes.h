#ifndef EMAIL_OPERACOES_H
#define EMAIL_OPERACOES_H
#include "lista_encadeada.h"
#include "servidor_email_operacoes.h"

#include <stdbool.h>

// Envia email para usuário
respostas_servidor enviar_email_para_usuario(
    lista_encadeada lista, int id_usuario, char *msg, int priori_msg
);

// Consulta primeira mensagem da caixa de entrada e a remove
respostas_servidor consulta_id_msg_priori(
    lista_encadeada lista_usuarios, int id_usuario, email *email_consulta
);

void remove_email_ja_consultado(lista_encadeada lista_usuarios, int id_usuario);

#endif