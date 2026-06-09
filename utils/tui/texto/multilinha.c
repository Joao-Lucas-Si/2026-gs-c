#include "multilinha.h"
#include "../../sistema.h"
#include "../../string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StringEmLinhas montarParagrafos(StringParte palavras, int colunas) {
  int larguraParcial = tamanhoColuna(colunas);
  int tamanho = larguraParcial - 20;
  String *linhas = malloc(sizeof(String));
  linhas[0] = malloc(larguraParcial);
  linhas[0][0] = 0;
  int atual = 0;
  for (int i = 0; i < palavras.tamanho; i++) {
    int t1 = strlen(linhas[atual]);
    int t2 = strlen(palavras.palavras[i]);

    if (t1 + t2 + 1 > tamanho) {
      atual++;
      linhas = realloc(linhas, (atual + 1) * sizeof(String));
      linhas[atual] = malloc(tamanho);
      strcpy(linhas[atual], palavras.palavras[i]);

    } else if (t1 == 0) {
      strcpy(linhas[atual], palavras.palavras[i]);
    } else {
      sprintf(linhas[atual], "%s %s", linhas[atual], palavras.palavras[i]);
    }
  }
  StringEmLinhas resposta = {.linhas = atual + 1, .conteudo = linhas};
  return resposta;
}

StringEmLinhas quebrarLinhas(String conteudo, int colunas) {
  return montarParagrafos(dividir(conteudo, " "), colunas);
}
