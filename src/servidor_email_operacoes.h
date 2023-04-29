#ifndef SERVIDOR_EMAIL_OPERACOES_H
#define SERVIDOR_EMAIL_OPERACOES_H

#include "lista_encadeada.h"

#include <stdio.h>
#include <stdlib.h>

enum operacoes_servidor_enum {
    CONSULTA = 0,
    CADASTRA = 1,
    REMOVE = 2,
    ENTREGA = 3,
    OPERACAO_INVALIDA = -1,
    QTD_OPERACOES = 4
};

typedef enum operacoes_servidor_enum operacoes_servidor;

enum respostas_servidor_enum {
    CONSULTA_REALIZADA = 200,
    MENSAGEM_ENTREGUE = 202,
    CONTA_CADASTRADA = 201,
    CONTA_REMOVIDA = 204,
    DADOS_INVALIDOS = 400,
    CONTA_JA_EXISTENTE = 401,
    CONTA_NAO_EXISTE = 404,
    CAIXA_DE_ENTRADA_VAZIA = 406
};

typedef enum respostas_servidor_enum respostas_servidor;

// recebe códigos de resposta, e envia mensagem
void mensagens_servidor_resposta(
    int codigo_resposta, int id_usuario, char *msg
);

// Recebe uma String que diz o tipo de opração que será executada pelo servidor
operacoes_servidor operacao_desejada(char *nome_operacao);

// Entrega para usuário lendo o arquivo
void servidor_operacao_entregar_mensagem_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
);

// Remove usuário especificado no arquivo
void servidor_operacao_remover_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
);

// Libera toda memoria do programa
void liberar_memoria_programa(
    FILE *arq_ponteiro, lista_encadeada lista_usuarios
);

// Cadastra usuário especificado no arquivo
void servidor_operacao_cadastro_usuario(
    FILE *arquivo, lista_encadeada lista_usuarios
);

// Recebe uma consulta do arquivo e mostra a primeira mensagem com maior prioridade
void servidor_operacao_consultar_mensagem_priori(
    FILE *arquivo, lista_encadeada lista_usuarios
);

// Defini qual operação será realizada conforme especificações do arquivo de entrada
void realiza_operacoes_servidor(
    int cod_operacao, lista_encadeada lista_usuarios, FILE *arquivo
);

#endif