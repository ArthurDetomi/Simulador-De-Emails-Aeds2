#include "email_operacoes.h"
#include "lista_array.h"
#include "lista_encadeada.h"
#include "usuario_operacoes.h"
#include "functions_utils.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int operacao_desejada(char *nome_operacao) {
   char operacoes[][10] = {"CONSULTA", "CADASTRA", "REMOVE", "ENTREGA"};
   int qtd = 4;
   for (int i = 0; i < qtd; i++) {
      if (strcmp(nome_operacao, operacoes[i]) == 0) {
         return i;
      }
   }
   return -1;
}

int main(int argv, char *argc[]) {
   lista_encadeada lista_usuarios = NULL;
   if (argv != 2) {
        printf("ERRO: ARGUMENTOS INVALIDOS\n");
        exit(1);
   }

   FILE *arquivo = fopen(argc[1], "r");
   if (arquivo == NULL) {
      perror("Error");
      exit(1);
   }

   char operacao[10];
   while (!feof(arquivo)) {
      if (fscanf(arquivo, "%s", operacao) != 1) {
         perror("Error");
         exit(1);
      }
      int cod_operacao = operacao_desejada(operacao);
      if (cod_operacao == -1) {
         printf("FORMATO ARQUIVO INVALIDO");
         exit(1);
      }
      
      if (lista_usuarios == NULL) {
         lista_usuarios = cria_lista_encadeada();
      }

      int id_usuario, codigo_resposta;
      email email_consulta = {0, NULL};
      char c;
      char *msg_buffer = (char *) malloc(100 * sizeof(char)); 
      switch (cod_operacao) {
         case 1:
            if (fscanf(arquivo, " %d", &id_usuario) != 1) {
               perror("Error");
               exit(1);
            }
            if (lista_usuarios == NULL) {
               lista_usuarios = cria_lista_encadeada();
            }
            codigo_resposta = cadastrar_novo_usuario(lista_usuarios, id_usuario);
            mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
         break;
         case 2:
            if (fscanf(arquivo, " %d", &id_usuario) != 1) {
               perror("Error");
               exit(1);
            }
            codigo_resposta = remover_usuario(lista_usuarios, id_usuario);
            mensagens_servidor_resposta(codigo_resposta, id_usuario, NULL);
         break;
         case 0:
            if (fscanf(arquivo, " %d", &id_usuario) != 1) {
               perror("Error");
               exit(1);
            }
            codigo_resposta = consulta_id_msg_priori(lista_usuarios, id_usuario, &email_consulta);
            mensagens_servidor_resposta(codigo_resposta, id_usuario, email_consulta.mensagem);
         break;
         case 3:
            if (fscanf(arquivo, " %d", &id_usuario) != 1) {
               perror("Error");
               exit(1);
            }
            while ((c = fgetc(arquivo)) != EOF) {

            }
         break;
      }
   }

   destroi_lista_encadeada(lista_usuarios);
   return 0;
}
