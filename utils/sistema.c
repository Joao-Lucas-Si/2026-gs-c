#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int tamanhoColuna(int colunas) {
  int largura = obterLargura();
  int larguraParcial = (largura - colunas + 1) / colunas;
  return larguraParcial;
}


void limpar() {
  if (eWindows) {
      system("cls");
  }
  else {
    printf("\033c");
  }
}

int obterLargura() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int columns = w.ws_col;
  if (columns == 0) {
    printf("você está rodando o código pelo output do vscode, é recomendado "
           "usar o terminal");
    exit(1);
  }

  return columns;
}

int obterAltura() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int columns = w.ws_row;
  if (columns == 0) {
    printf("você está rodando o código pelo output do vscode, é recomendado "
           "usar o terminal");
    exit(1);
  }

  return columns;
}

void esperar(int microSegundos) { usleep(microSegundos * 1000); }

void pausar() {

  setbuf(stdin, NULL);
  getchar();
}