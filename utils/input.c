
#include "input.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

void lerString(String valor, int tamanho) {
  fgets(valor, tamanho, stdin);

  if ((strlen(valor) > 0) && (valor[strlen(valor) - 1] == '\n'))
    valor[strlen(valor) - 1] = '\0';
  
}

#define KEY_ESCAPE 0x001b
// #define KEY_ENTER   0x000a
// #define KEY_UP      0x0105
// #define KEY_DOWN    0x0106
// #define KEY_LEFT    0x0107
// #define KEY_RIGHT   0x0108

enum Setas { NENHUM, BAIXO, ENTER, CIMA, ESQUERDA, DIREITA };

enum Setas obterSeta() {
  int c;
  enum Setas comando = NENHUM;
  while (0 == 0) {
    // char s = fgetc(stdin);
    // printf("%c", s);
    char j;
    printf("pressione: ");
    c = getchar();
    if (c == KEY_ESCAPE) {
      c = getchar();
      if (c == '[') {
        switch (getchar()) {
        case 'A':
          comando = CIMA;
          break;
        case 'B':
          comando = BAIXO;
          break;
        case 'C':
          comando = DIREITA;
          break;
        case 'D':
          comando = ESQUERDA;
          break;
        default:
          comando = NENHUM;
          break;
        }
      }
    }
    printf("%d", comando);
    if (comando != NENHUM) {
      break;
    }
  }
  return comando;
}

struct termios info;

void desabilitarEspera() {
  tcgetattr(0, &info);     /* get current terminal attirbutes; 0 is the file
                            descriptor for stdin */
  info.c_lflag &= ~ICANON; /* disable canonical mode */
  info.c_cc[VMIN] = 1;     /* wait until at least one keystroke available */
  info.c_cc[VTIME] = 0;    /* no timeout */
  tcsetattr(0, TCSANOW, &info);
}

void habilitarEspera() {

  tcgetattr(0, &info);
  info.c_lflag |= ICANON;
  tcsetattr(0, TCSANOW, &info);
}