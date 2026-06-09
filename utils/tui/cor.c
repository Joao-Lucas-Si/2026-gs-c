#include "cor.h"
#include "../tipos.h"
#include <stdio.h>

int aplicarEfeitoCor(enum EfeitoCor efeito, enum Cor cor) {
  int resultado = efeito + cor;

  return resultado;
}

CorConfig corConfig = {.ativacao = 1};
void ativarEfeitosTamanho(int efeitos[], int tamanho) {
  if (corConfig.ativacao) {
    printf("\033[");
    for (int i = 0; i < tamanho; i++) {
      printf("%d", efeitos[i]);
      if (i < tamanho - 1) {
        printf(";");
      }
    }
    printf("m");
  }
}

void desativarEfeitos() { printf("\033[0m"); }

void desativarCores() { corConfig.ativacao = 0; }

void ativarCores() { corConfig.ativacao = 1; }

enum Cor obterPrimario() { return corConfig.primaria; }

enum Cor obterSecundario() { return corConfig.secundaria; }

void configurarCores(enum Cor primario, enum Cor secundario) {
  corConfig.primaria = primario;
  corConfig.secundaria = secundario;
}