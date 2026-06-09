#include "../print.h"
#include "../sistema.h"
#include "../tipos.h"
#include <stdio.h>
#include <string.h>

void repetir(char c, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    print("%c", c);
  }
}

void centralizarVerticalTopo(int tamanho) {
  int altura = obterAltura();

  int alturaParcial = (altura - tamanho) / 2;

  repetir('\n', alturaParcial);
}

void centralizarFixadoTamanho(char *conteudo, char sep, int largura,
                              int tamanho) {
  repetir(sep, largura);

  for (int i = 0; i < tamanho; i++) {
    if (conteudo && conteudo[i]) {

      char ch[2];
      sprintf(ch, "%c", conteudo[i]);
      cederConteudo(ch);
      print("%c", conteudo[i]);
    }
  }
  repetir(sep, largura);
}

void centralizarFixado(char *conteudo, char sep, int largura) {
  nomear("separador-centralizado");
  char separador[2] = {sep, 0};
  cederConteudo(separador);
  repetir(sep, largura);
  cederConteudo(conteudo);
  nomear("conteudo-centralizado");
  print("%s", conteudo);
  cederConteudo(separador);
  nomear("separador-centralizado");
  repetir(sep, largura);
  cederConteudo(NULL);
}

void centralizar_limitado(char *conteudo, char sep, int maximo) {
  int larguraTotal = maximo;
  if (larguraTotal % 2 == 1) {
    larguraTotal -= 1;
  }
  int tamanho = strlen(conteudo);
  int larguraParcial = larguraTotal - tamanho;

  larguraParcial /= 2;

  centralizarFixado(conteudo, sep, larguraParcial);
  //   if (larguraTotal != larguraParcial * 2 + tamanho) {
  //     larguraParcial += 1;
  //   }
}

void definir_esquerda_limitado(char *conteudo, char sep, int maximo) {
  int larguraTotal = maximo;

  int larguraParcial = larguraTotal - strlen(conteudo);

  printf("%s", conteudo);
  repetir(sep, larguraParcial);
}

void centralizar(char *conteudo, char sep) {
  int tamanho = strlen(conteudo);
  int larguraTotal = obterLargura();
  centralizar_limitado(conteudo, sep, larguraTotal);
  printf("\n");
}

void centralizarVertical(void (*conteudo)(Any *), int tamanho, Any *args) {
  limpar();
  int altura = obterAltura();

  int alturaParcial = altura - tamanho - 1;
  // printf("%d\n", alturaParcial);
  alturaParcial /= 2;
  for (int i = 0; i < alturaParcial; i++) {
    printf("\n");
  }
  conteudo(args);
  for (int i = 0; i < alturaParcial; i++) {
    printf("\n");
  }
}