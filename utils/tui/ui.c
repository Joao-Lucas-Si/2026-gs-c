
#include "../array.h"
#include "../print.h"
#include "../sistema.h"
#include "../tipos.h"
#include "cor.h"
#include "layout.h"
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void _criar_tabela(String *tabela, int tamanho, int colunas) {
  enum Cor secundario = obterSecundario();
  int larguraTotal = obterLargura() - (colunas - 1);

  int largura = larguraTotal / colunas;

  int resto = larguraTotal % colunas;

  int currentColumn = 1;

  for (int i = 0; i < tamanho; i++) {
    if (resto != 0) {
      printf(" ");
      // largura += 1;
    }
    // if (containsSize(selecionados, selecionadosTamanho, i)) {
    //   int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, ROXO)};
    //   ativarEfeitos(efeitos, 1);
    // }

    char start[100];
    sprintf(start, "%d. %s", i + 1, tabela[i]);
    // strcat(start, num);
    // strcat(start, ". ");
    // strcat(start, tabela[i]);
    int strTamanho = strlen(start);
    int largura_individual = largura - strTamanho;

    centralizar_limitado(start, ' ', largura);
    desativarEfeitos();
    if (currentColumn == colunas) {
      printf("\n");
      currentColumn = 1;
    } else {
      int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, secundario)};
      ativarEfeitos(efeitos);

      printf("|");
      desativarEfeitos();
      currentColumn++;
    }
  }
}


void mostrarErro(char *erro) {
  int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, VERMELHO), PISCAR_LENTO};

  ativarEfeitosTamanho(efeitos, 2);
  printf("%s", erro);
  desativarEfeitos();
}


#define criar_menu(titulo, tabela, colunas, id)                                \
  {                                                                            \
    char textos[len(tabela)][100];                                             \
    for (int i = 0; i < len(tabela); i++) {                                    \
      strcpy(textos[i], obterTexto(tabela[i]));                                \
    }                                                                          \
    _criar_menu(titulo, tabela, textos, len(tabela), colunas, id);             \
  }

String obterString(Any arg) {
  return arg.stringv;
}

Any stringParaAny(String str) {
  Any any = { .stringv =str };
  return any;
}

// void logoConteudo(Any* args) {
//   int tamanho = args[0].intv;
//   int larguraParcial = args[1].intv;
//   int si = args[3].intv;
//   String logo[100];
//   mapSize(args[2].array.values, logo, tamanho, obterString);

//   for (int i = 0; i < tamanho; i++) {
//     centralizarFixadoTamanho(logo[i], ' ', larguraParcial, si);
//     printf("\n");
//   }
// }


void criar_logo(char **logo, int tamanho, int textoTamanho) {
  
  int larguraTotal = obterLargura();
  if (larguraTotal % 2 == 1) {
    larguraTotal -= 1;
  }
  int larguraParcial = larguraTotal - textoTamanho;

  larguraParcial /= 2;
  AnyArray array;
  Any arraya[tamanho];
  array.values = arraya;
  array.tamanho = tamanho;
  mapSize(logo, arraya, array.tamanho, stringParaAny);
  Any args[] = {tamanho, larguraParcial, [2].array=array, textoTamanho};
  // int tamanho = args[0].intv;
  // int larguraParcial = args[1].intv;
  // int si = args[3].intv;
  // String logo[100];
  // mapSize(args[2].array.values, logo, tamanho, obterString);

  for (int i = 0; i < tamanho; i++) {
    centralizarFixadoTamanho(logo[i], ' ', larguraParcial, textoTamanho);
    printf("\n");
  }
  esperar(2);

}