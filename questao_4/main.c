#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "contato.h"


int main(int argc, char **argv) {
  inserir(1824127, "Chico", "9988-1123");
  inserir(19381, "Pedro", "8849-9283");
  inserir(1381, "Tripa", "8183-9926");
  inserir(432001, "Chico", "9988-1123");
  inserir(138456, "Pedro", "8849-9283");
  inserir(913, "Tripa", "8183-9926");

  /* Teste tamanho() e insersir() */
  assert(tamanho() == 6);

  /* Teste remover() */
  assert(remover(1824127) == 1);
  assert(remover(1381) == 1);
  assert(remover(913) == 1);
  assert(remover(250001) == 0); /* não existe */

  /* Checar se foi removido */
  assert(tamanho() == 3);


  /* Testet buscar() */
  assert(buscar("Joao") == 0);
  assert(buscar("Pedro") == 1);
  assert(buscar("Chico") == 1);


  show_all();

  return EXIT_SUCCESS;
}
