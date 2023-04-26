#ifndef FUNCTIONS_UTILS_H

/*
 * Verifica se um ponteiro está nulo, passa-se o ponteiro e uma msg que pode ser
 * o nome da função
 */
void verifica_estouro_memoria(void *ponteiro, char *msg);

// verifica se o id passado é válido
int id_enviado_eh_valido(int id);

#endif