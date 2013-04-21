#include <assert.h>
#include <stdio.h>
#include <string.h>
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


  /* Teste buscar() */
  assert(buscar("Joao") == 0);
  assert(buscar("Pedro") == 1);
  assert(buscar("Chico") == 1);


  /* Teste salvar() */

  /*
  $ ./out --save filename
  */
  if(strcmp(argv[1], "--save") == 0 && argv[2] != NULL) {
    assert(salvar(argv[2]) == 1);
  }

  /* Teste abrir() */

  /*
  $ ./out --open filename
  */
  if(strcmp(argv[1], "--open") == 0 && argv[2] != NULL) {
    assert(abrir(argv[2]) == 1);
    assert(abrir("NAO EXISTE") == 0);
  }

  show_all();

  return EXIT_SUCCESS;
}
