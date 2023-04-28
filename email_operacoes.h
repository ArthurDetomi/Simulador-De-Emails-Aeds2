#ifndef EMAIL_OPERACOES_H
#define EMAIL_OPERACOES_H
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdbool.h>

// Envia email para usuário
int enviar_email_para_usuario(lista_encadeada lista, int id_usuario, char *msg, int priori_msg);

// Consulta primeira mensagem da caixa de entrada e a remove
int consulta_id_msg_priori(lista_encadeada lista_usuarios, int id_usuario, email *email_consulta);

#endif