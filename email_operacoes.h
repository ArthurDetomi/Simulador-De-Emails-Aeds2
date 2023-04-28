#ifndef EMAIL_OPERACOES_H
#define EMAIL_OPERACOES_H
#include "lista_array.h"
#include "lista_encadeada.h"

#include <stdbool.h>

bool enviar_email_para_usuario(lista_encadeada lista, int id_usuario, char *msg, int priori_msg);

#endif