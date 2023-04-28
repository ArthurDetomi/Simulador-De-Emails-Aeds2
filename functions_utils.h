#ifndef FUNCTIONS_UTILS_H
#define FUNCTIONS_UTILS_H

enum respostas_servidor_enum{
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

/*
 * Verifica se um ponteiro está nulo, passa-se o ponteiro e uma msg que pode ser
 * o nome da função
 */
void verifica_estouro_memoria(void *ponteiro, char *msg);

// verifica se o id passado é válido
int id_enviado_eh_valido(int id);

// recebe códigos de resposta, e envia mensagem
void mensagens_servidor_resposta(int codigo_resposta, int id_usuario, char *msg);



#endif