#include "array.c"
#include "array.h"
#include "data.c"
#include "input.c"
#include "print.c"
#include "print.h"
#include "sistema.c"
#include "sistema.h"
#include "string.c"
#include "tipos.h"
#include "tui/animacao.c"
#include "tui/cor.c"
#include "tui/cor.h"
#include "tui/layout.c"
#include "tui/layout.h"
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "tui/ui.h"
#include "tui/ui.c"

// void oi() { printf("oi usuário"); }



// String acessarString(Any arg) { return arg.stringv; }

// Any cederString(String arg) {
//   Any uni = {.stringv = arg};
//   return uni;
// }

// void a(Any *args) {
//   int tamanho = args[0].intv;
//   int textoTamanho = args[1].intv;
//   String membros[10];
//   mapSize(args[2].array.values, membros, args[2].array.tamanho, acessarString);
//   String logo[20];
//   mapSize(args[3].array.values, logo, args[3].array.tamanho, acessarString);
//   int larguraTotal = obterLargura();
//   if (larguraTotal % 2 == 1) {
//     larguraTotal -= 1;
//   }
//   int larguraParcial = larguraTotal - textoTamanho;
//   larguraParcial /= 2;
//   for (int i = 0; i < tamanho; i++) {
//     nomear("logo");
//     centralizarFixadoTamanho(logo[i], ' ', larguraParcial, textoTamanho);
//     printf("\n");
//     nomear(NULL);
//   }


//   int selecionados[1] = { -1 };
//   _criar_tabela(membros, 3, 3, selecionados, 1);
// }

// void criar_log(String *logo, char membros[][100], int tamanho,
//                int textoTamanho) {
//   AnyArray membrosArg;
//   membrosArg.tamanho = 3;
//   Any membrosValores[20];
//   mapSize(membros, membrosValores, 3, cederString);
//   membrosArg.values = membrosValores;
//   AnyArray logoArg;
//   logoArg.tamanho = tamanho;
//   Any logoValores[20] = {};
//   mapSize(logo, logoValores, tamanho, cederString);
//   logoArg.values = logoValores;
//   Any args[] = {tamanho, textoTamanho, [2].array = membrosArg,
//                 [3].array = logoArg};
//   centralizarVertical(a, tamanho + 1, args);
//   desativarEfeitos();
//   pausar();
//   limpar();
// }

// void esperarSegundo() { esperar(1); }

// void rodasAzuis() {
//   char *nome = obterNome();
//   char *conteudo = obterConteudo();
//   if ((strcmp(nome, "trem-5") == 0 &&
//        (strcmp(conteudo, "0") == 0 || strcmp(conteudo, "o") == 0))) {
//     int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, AZUL)};
//     aplicarEfeitos(efeitos, 1);
//   } else if ((strcmp(conteudo, "O") == 0 || strcmp(conteudo, "o") == 0) &&
//              (strcmp(nome, "trem-1") == 0 || strcmp(nome, "trem-2") == 0)) {
//     int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, BRANCO)};
//     aplicarEfeitos(efeitos, 1);
//   } else {
//     int efeitosa[] = {aplicarEfeitoCor(TEXTO_CLARO, ROXO)};
//     aplicarEfeitos(efeitosa, 1);
//   }
// }

// void configurarIntegrantes() {
//   char *nome = obterNome();
//   char *conteudo = obterConteudo();
//   int primario = obterPrimario();
//   int secundario = obterSecundario();
//   if (nome && strcmp(nome, "logo") == 0) {
//     if (strcmp(conteudo, "_") == 0 || strcmp(conteudo, "|") == 0 ||
//         strcmp(conteudo, "\\") == 0 || strcmp(conteudo, "/") == 0) {
//       int efeitos[] = {aplicarEfeitoCor(TEXTO, secundario)};
//       aplicarEfeitos(efeitos, 1);
//     } else {
//       int efeitos[] = {aplicarEfeitoCor(TEXTO, primario)};
//       aplicarEfeitos(efeitos, 1);
//     }
//   } else {
//     aplicarEfeitos(NULL, 0);
//   }
// }

// int main() {
//   obterLargura();
//   configurarCores(ROXO, AZUL);
//   limpar();

//   ArquivoResultado logo = lerLinhaALinha("ascii/larry_101.txt");

//   ArquivoResultado membros = lerLinhaALinha("ascii/bigmoney_integrantes.txt");


//   char membrosNomes[][100] = {"João Lucas", "Alan", "João Evangelista"};
//   int *tamanhos;
//   ativarAntes(rodasAzuis);
//   animarTrem();
//   resetarConfig();
//   ativarDepois(esperarSegundo);
//   ativarAntes(configurarIntegrantes);
//   criar_log(membros.conteudo, membrosNomes, membros.linhas, 110);
//   // resetarConfig();
//   // char textos[len(opcoes)][100];
//   //   criar_logo(logo, len(logo), 70);
//   //   criar_menu("titulo", opcoes, 3, "main");
//   return 0;
// }