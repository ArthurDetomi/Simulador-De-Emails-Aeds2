#ifndef USUARIO_OPERACOES_H
#define USUARIO_OPERACOES_H
#include "lista_encadeada.h"
#include "lista_array.h"

// Cadastra novo usuario
bool cadastrar_novo_usuario(lista_encadeada lista, int id);
// Remove usuario e limpa sua caixa de entrada
bool remover_usuario(lista_encadeada lista, int id);

#endif

