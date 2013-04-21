#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

Contato *inicio = NULL;

/**
 * Complexidade: O(n)
 */
void inserir(int identidade, char *nome, char *telefone) {
  Contato *novo,
          *aux = NULL,
          *item = inicio;
  int cont = 1;

  novo = (Contato *) malloc(sizeof(Contato));
  novo->identidade = identidade;
  strcpy(novo->nome, nome);
  strcpy(novo->telefone, telefone);

  while (item != NULL && cont) {
    if (identidade < item->identidade) {
      cont = 0;
    } else {
      aux  = item;
      item = item->proximo;
    }
  }

  novo->proximo = item;
  if (aux == NULL)
    inicio = novo;
  else
    aux->proximo = novo;
}


/**
 * Complexidade: O(n)
 */
int remover(int identidade) {
  Contato *l, *prev = NULL;
  l = inicio;

  while(l != NULL) {
    if(l->identidade == identidade) {
      if(prev == NULL)
        inicio = l->proximo;
      else
        prev->proximo = l->proximo;

      free(l);
      return 1;
    }
    prev = l;
    l = l->proximo;
  }
  return 0;
}

/**
 * Complexidade: O(n)
 */
int buscar(char nome[80]) {
  Contato *l = inicio;

  while(l != NULL) {
    if(strcmp(l->nome, nome) == 0)
      return 1;
    l = l->proximo;
  }
  return 0;
}

/**
 * Complexidade: O(n)
 */
int tamanho() {
  int count = 0;
  Contato *cur;

  if(inicio != NULL) {
    cur = inicio;

    while(cur != NULL) {
      cur = cur->proximo;
      count++;
    }
  }
  return count;
}

void show_all() {
  Contato *c = inicio;
  while(c != NULL) {
    printf("- %d | %s | %s\n", c->identidade, c->nome, c->telefone);
    c = c->proximo;
  }
}
