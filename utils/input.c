
#include "input.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerString(String valor, int tamanho) {
  fgets(valor, tamanho, stdin);

  if ((strlen(valor) > 0) && (valor[strlen(valor) - 1] == '\n'))
    valor[strlen(valor) - 1] = '\0';
  
}
