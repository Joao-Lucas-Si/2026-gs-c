#include "tipos.h"
#include "string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarEm(String *dest, String *src, int indice, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    dest[indice + i] = src[i];
  }
}

int strMax(char** textos, int tamanho) {
    int max;
    for (int i = 0; i < tamanho; i++) {
        if (strlen(textos[i]) > max) {
            max = strlen(textos[i]);
        }
    }

    return max;
}

char* substituir(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}



StringParte dividir(String str, const String separador) {

  String *tokens = malloc(sizeof(char *));
  tokens[0] = malloc(100);
  tokens[0][0] = 0;
  int i = 1;
  int j = 1;
  String token = strtok(str, separador);

  while (token != NULL) {
    if (j > i) {
      i++;
      tokens = realloc(tokens, i * sizeof(String));
      tokens[i - 1] = (char *)malloc(100);
      tokens[i - 1][0] = 0;
    }
    sprintf(tokens[i - 1], "%s", token);
    j++;
    token = strtok(NULL, separador);
  }
  StringParte resultado = {.palavras = tokens, .tamanho = i};
  return resultado;
}

String stringf(int tamanho, const String __restrict __format, ...) {
  va_list args;
  va_start(args, __format);
  String resultado = malloc(tamanho);
  vsprintf(resultado, __format, args);
  return resultado;
}