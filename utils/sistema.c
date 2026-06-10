#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#if eWindows
  #include <windows.h>
  int obterLargura() {
     CONSOLE_SCREEN_BUFFER_INFO csbi;
      int columns, rows;
  
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
      rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  
      return columns;
  }
  int obterAltura() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
      int columns, rows;
  
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
      rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  
      return columns;
  }
#else
 #include <sys/ioctl.h>
 int obterLargura() {
   struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int columns = w.ws_col;
  if (columns == 0) {
    printf("você esta rodando o código pelo output do vscode, é recomendado "
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
    printf("você esta rodando o código pelo output do vscode, é recomendado "
           "usar o terminal");
    exit(1);
  }

  return columns;
}
#endif

int tamanhoColuna(int colunas) {
  int largura = obterLargura();
  int larguraParcial = (largura - colunas + 1) / colunas;
  return larguraParcial;
}


void limpar() {
  if (eWindows) {
      // printf("windows");
      system("cls");
  }
  else {
    printf("\033c");
  }
}


void esperar(int microSegundos) { usleep(microSegundos * 1000); }

void pausar() {
  printf("digite enter para proseguir\n");
  setbuf(stdin, NULL);
  getchar();
}