#ifndef LISTA_ORDENADA_H_
#define LISTA_ORDENADA_H_

typedef struct Contato {
  int identidade;
  char nome[80];
  char telefone[20];
  struct Contato *proximo;
} Contato;

void inserir(int identidade, char *nome, char *telefone);

int remover(int identidade);

int buscar(char nome[80]);

int tamanho();

/**
 * Salva um arquivo
 * retorna 0 caso a lista esteja vazia
 * retorna 1 se o arquivo for criado com sucesso
 */
int salvar(char * nome);

int abrir(char * nome);

void show_all();

#endif
