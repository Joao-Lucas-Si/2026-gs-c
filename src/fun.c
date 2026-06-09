#include "../utils/utils.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>

int obterNumeroEmIntervalo(int inicio, int fim) {
  int numero = rand() % (fim - inicio + 1) + inicio;

  return numero;
}


StringEmLinhas encriptarMensagem(StringParte partes, int colunas,
                                 ComunicacaoStatus status) {
  if (status == ESTAVEL)
    return montarParagrafos(partes, colunas);
  String linhasFinais[partes.tamanho];
  int probabilidade = 0;

  if (status == NULO) {
    probabilidade = 100;
  } else if (status == INSTAVEL) {
    probabilidade = 20;
  }

  char caracteresDeErro[8] = {'#', '@', '*', '+', '/', '!', '$', '&'};

  for (int i = 0; i < partes.tamanho; i++) {
    linhasFinais[i] = malloc(100);
    linhasFinais[i][0] = 0;
    int chance = obterNumeroEmIntervalo(0, 100);
    if (chance < probabilidade) {
      int s = strlen(partes.palavras[i]);
      char palavra[s];
      for (int i = 0; i < s; i++) {
        int caractere = caracteresDeErro[obterNumeroEmIntervalo(
            0, len(caracteresDeErro) - 1)];

        palavra[i] = caractere;
      }
      strcpy(linhasFinais[i], palavra);
    } else {
      strcpy(linhasFinais[i], partes.palavras[i]);
    }
  }

  StringParte resultadoParte = {.palavras = linhasFinais,
                                .tamanho = partes.tamanho};

  StringEmLinhas resultado = montarParagrafos(resultadoParte, colunas);
  return resultado;
}


