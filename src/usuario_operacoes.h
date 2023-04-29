#ifndef USUARIO_OPERACOES_H
#define USUARIO_OPERACOES_H
#include "lista_encadeada.h"
#include "servidor_email_operacoes.h"

// Cadastra novo usuario
respostas_servidor cadastrar_novo_usuario(lista_encadeada lista_usuarios, int id);
// Remove usuario e limpa sua caixa de entrada
respostas_servidor remover_usuario(lista_encadeada lista_usuarios, int id);

#endif
