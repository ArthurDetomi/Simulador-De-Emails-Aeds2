#ifndef USUARIO_OPERACOES_H
#define USUARIO_OPERACOES_H
#include "lista_encadeada.h"
#include "lista_array.h"
#include "functions_utils.h"

// Cadastra novo usuario
respostas_servidor cadastrar_novo_usuario(lista_encadeada lista, int id);
// Remove usuario e limpa sua caixa de entrada
respostas_servidor remover_usuario(lista_encadeada lista, int id);

#endif

