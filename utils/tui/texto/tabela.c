#include "tabela.h"
#include "../../tipos.h"
#include "../../utils.h"
#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String multiplicarStr(char ch, int vezes) {

  char *resultado = malloc(vezes);
  for (int i = 0; i < vezes; i++) {
    resultado[i] = ch;
  }

  resultado[vezes - 1] = 0;
  return resultado;
}

String textoCentralizado(String conteudo, int area) {
  int largura = area - strlen(conteudo);
  largura /= 2;

  String resultado = malloc(area);

  String espaco = multiplicarStr(' ', largura);
  snprintf(resultado, area, "%s%s%s", espaco, conteudo, espaco);
  // free(espaco);
  return resultado;
}

// String l(String conteudo, String atual, int largura, int larguraParcial) {
//   String a = textoCentralizado(conteudo, larguraParcial);

//   char *b = malloc(largura + 1);

//   strcpy(b, atual);
//   int ultimo = 0;
//   String espacoesRestantes =
//       multiplicarStr(' ', larguraParcial - strlen(a) - 1);
//   if (coluna == 0) {
//     sprintf(b, "%s%s", a, espacoesRestantes);
//   } else if (coluna > 0 && strlen(b) == 0) {
//     String espacos = multiplicarStr(' ', larguraParcial - 1);
//     for (int i = 0; i < coluna; i++) {
//       if (i == 0) {

//         sprintf(b, "%s", espacos);
//       } else {
//         sprintf(b, "%s|%s", b, espacos);
//       }
//     }
//     sprintf(b, "%s|%s", b, a);
//   } else if (strlen(a) == 0) {

//     sprintf(b, "%s|%s", b, espacoesRestantes);
//   } else {
//     String espacoes = multiplicarStr(' ', larguraParcial - strlen(a) - 1);
//     sprintf(b, "%s|%s%s", b, a, espacoesRestantes);
//   }
//   // free(espacoesRestantes);
//   // free(a);
//   return b;
// }

// #define criarTabelaMultilinhaMap(original, colunas, linhas, sep, map) ({\
//   String* conteudo[colunas];\ 
//   for (int i = 0; i < colunas; i++) {\
//     conteudo[i] = map(original[i]);\
//   }\
// })
// void criarTabelaMultilinha(String **conteudo, int colunas, int *linhas,
//                            int sep) {
//   int tamanho = 0;
//   int largura = obterLargura();
//   Linha *final = malloc(sizeof(Linha));
//   final[0].conteudo = malloc(largura);
//   final[0].conteudo[0] = 0;
//   int larguraParcial = (largura - sep + 1) / sep;
//   int atual = 1;
//   String primeiro = l("", "", largura + 1, larguraParcial, sep - 1, sep);
//   strcpy(final[0].conteudo, primeiro);
//   // free(primeiro);
//   int coluna = 0;
//   int max = 1;
//   int maxAtual = 0;
//   for (int i = 0; i < colunas; i++) {
//     int linha = linhas[i];
//     for (int j = 0; j < linha; j++) {
//       int r = max + j;
//       //   Linha resul;
//       if (r < atual) {
//         // resul = final[r];
//       } else {
//         atual++;
//         final = realloc(final, atual * sizeof(struct LinhaStruct));
//         final[r].conteudo = malloc(largura + 1);
//         final[r].conteudo[0] = 0;
//       }
//       String c = l(conteudo[i][j], final[r].conteudo, largura + 1,
//                    larguraParcial, coluna, sep);
//       strcpy(final[r].conteudo, c);
//       // free(c);

//       if (j > maxAtual) {
//         maxAtual = j;
//       }
//     }
//     if (linha < maxAtual) {
//       int repeticoes = maxAtual - linha;
//       for (int i = 0; i < repeticoes; i++) {
//         int r = max + i + linha;
//         String c =
//             l("", final[r].conteudo, largura + 1, larguraParcial, coluna,
//             sep);
//         strcpy(final[r].conteudo, c);
//         // free(c);
//       }
//     }

//     if (coluna == sep - 1) {
//       coluna = 0;
//       max += maxAtual + 2;
//       atual++;
//       final = realloc(final, atual * sizeof(struct LinhaStruct));
//       final[max - 1].conteudo = malloc(largura + 1);
//       final[max - 1].conteudo[0] = '\n';
//       String a = l("", "", largura + 1, larguraParcial, sep - 1, sep);
//       strcpy(final[max - 1].conteudo, a);
//       // free(a);
//       maxAtual = 0;
//     } else {
//       coluna++;
//     }
//   }

//   for (int i = 0; i < atual; i++) {
//     final[i].conteudo[largura - 1] = 0;
//     int vazio = strlen(final[i].conteudo);

//     printf("%s\n", final[i].conteudo);
//     // free(final[i].conteudo);
//   }
//   // atual = 0;
//   // max = 0;
//   // free(final);
//   // for (int  i = 0; i < atual; i++) {
//   //   free(final[i].conteudo);
//   // }
// }

StringMultilinha criarMultilinha(String **conteudo, int colunas, int *linhas,
                                 int sep) {
  int tamanho = 0;
  int largura = obterLargura();
  int larguraParcial = (largura - sep + 1) / sep;
  String **final = malloc(sizeof(String));
  final[0] = malloc(sep * sizeof(String));
  for (int i = 0; i < sep; i++) {
    final[0][i] = malloc(larguraParcial);
    final[0][i][0] = 0;
  }
  int atual = 1;
  int linhasAtual = 1;
  int coluna = 0;
  int max = 1;
  int maxAtual = 0;
  for (int i = 0; i < colunas; i++) {
    int linha = linhas[i];
    for (int j = 0; j < linha; j++) {
      int r = max + j;
      //   Linha resul;
      if (!(r < atual)) {
        atual++;
        final = realloc(final, atual * sizeof(String));
        final[r] = malloc(sep * sizeof(String));
        for (int i = 0; i < sep; i++) {
          final[r][i] = malloc(larguraParcial + 1);
          final[r][i][0] = 0;
        }
      }
      String c = textoCentralizado(conteudo[i][j], larguraParcial);
      strcpy(final[r][coluna], c);

      if (j > maxAtual) {
        maxAtual = j;
      }
    }

    if (coluna == sep - 1) {
      coluna = 0;
      max += maxAtual + 1;
      maxAtual = 0;
    } else {
      coluna++;
    }
  }

  StringMultilinha resultado = {.conteudo = final, .linhas = atual};

  return resultado;

  // for (int i = 0; i < atual; i++) {
  //   // final[i].conteudo[largura - 1] = 0;
  //   // int vazio = strlen(final[i].conteudo);

  //   for (int j = 0; j < sep; j++) {
  //     if (final[i] && final[i][j]) {
  //       print("%s", final[i][j]);
  //     }else {
  //       String espacos = multiplicarStr(' ', larguraParcial);
  //       print(espacos);
  //     }
  //   }
  //   printf("\n");
  //   // free(final[i].conteudo);
  // }
  // atual = 0;
  // max = 0;
  // free(final);
  // for (int  i = 0; i < atual; i++) {
  //   free(final[i].conteudo);
  // }
}



void criarTabelaMultilinha(String **conteudo, int colunas, int *linhas,
                           int sep) {
  StringMultilinha multilinha = criarMultilinha(conteudo, colunas, linhas, sep);
  enum Cor secundario = obterSecundario();
  int largura = (obterLargura() - sep + 1) / sep;
  int coluna = 0;
  for (int i = 0; i < multilinha.linhas; i++) {
    for (int j = 0; j < sep; j++) {
      char nome[100];
      sprintf(nome, "%d,%d", i, j);
      nomear(nome);
      String conteudo = multilinha.conteudo[i][j];
      cederConteudo(conteudo);
      print("%s", conteudo);
      if (strlen(conteudo) < largura) {
        String espacos = multiplicarStr(' ', largura - strlen(conteudo));
        printf("%s", espacos);
      }
      if (j < sep - 1) {
        int e[1] = {aplicarEfeitoCor(TEXTO_CLARO, secundario)};
        ativarEfeitos(e);
        printf("|");
        desativarEfeitos();
      }
    }
    printf("\n");
    // if (coluna < sep) {

    //   coluna++;

    // } else {
    //   for (int i = 0; i < sep - 1; i++) {
    //     String espacos = multiplicarStr(' ', largura);
    //     printf("%s", espacos);
    //     int e[1] = {aplicarEfeitoCor(TEXTO_CLARO, secundario)};
    //     ativarEfeitos(e);
    //     printf("|");
    //     desativarEfeitos();
    //   }
    //   coluna = 0;
    // }

    // printf("\n");
  }
}

int criarMenuSwitchMultilinhaComOpcoes(String titulo, String **conteudo,
                                       int tamanho, int *linhas, int colunas,
                                       MenuOpcoes opcoes) {
  enum Cor primario = obterPrimario();

  String *topo[3];
  int topoJ[3];
  if (opcoes.direita) {

    topo[0] = opcoes.direita;
    topoJ[0] = opcoes.direitaTamanho;
  } else {
    topo[0] = malloc(sizeof(String));
    topo[0][0] = "";
    topoJ[0] = 1;
  }
  topo[1] = malloc(sizeof(String));
  topo[1][0] = titulo;
  topoJ[1] = 1;
  if (opcoes.esquerda) {
    topo[2] = opcoes.esquerda;
    topoJ[2] = opcoes.esquerTamanho;
  } else {
    char a[100];
    String vazio[2] = {a};
    topo[2] = vazio;
    topoJ[2] = 1;
  }

  while (1) {
    int selecionado = 0;
    int efeitos[] = {aplicarEfeitoCor(FUNDO, primario), BOLD};
    ativarEfeitos(efeitos);
    StringMultilinha tituloMultilinha =
        criarMultilinha(topo, len(topo), topoJ, 3);
    for (int i = 0; i < tituloMultilinha.linhas; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%s", tituloMultilinha.conteudo[i][j]);
      }
      printf("\n");
    }
    desativarEfeitos();
    criarTabelaMultilinha(conteudo, tamanho, linhas, colunas);
    printf("escolha: ");
    scanf("%d", &selecionado);
    limpar();

    if (selecionado < 1 || selecionado > tamanho) {
      mostrarErro("valor invalido\n");
      continue;
    }

    return selecionado;
  }
  return 0;
}

int criarMenuSwitchMultilinha(String titulo, String **conteudo, int tamanho,
                              int *linhas, int colunas) {
  enum Cor primario = obterPrimario();
  while (1) {
    int selecionado = 0;
    int efeitos[] = {aplicarEfeitoCor(FUNDO_CLARO, primario), BOLD};
    ativarEfeitosTamanho(efeitos, 2);
    centralizar(titulo, ' ');
    desativarEfeitos();

    criarTabelaMultilinha(conteudo, tamanho, linhas, colunas);

    printf("escolha: ");
    scanf("%d", &selecionado);
    limpar();

    if (selecionado < 1 || selecionado > tamanho) {
      mostrarErro("valor invalido\n");
      continue;
    }

    return selecionado;
  }
  return 0;
}