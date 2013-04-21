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

void show_all();

#endif
