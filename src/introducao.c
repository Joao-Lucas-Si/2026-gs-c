#include "../utils/utils.h"
#include "data.h"
#include <stdio.h>
#include <string.h>

void esperarSegundo() { esperar(1); }

void colorirTrem() {
  char *nome = obterNome();
  char *conteudo = obterConteudo();
  if (strcmp(conteudo, "+") == 0) {
    int efeitos[1] = {aplicarEfeitoCor(TEXTO_CLARO, AZUL)};
    aplicarEfeitos(efeitos, 1);
  } else if ((strcmp(nome, "trem-5") == 0 &&
              (strcmp(conteudo, "0") == 0 || strcmp(conteudo, "o") == 0))) {
    int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, AZUL)};
    aplicarEfeitos(efeitos, 1);
  } else if ((strcmp(conteudo, "O") == 0 || strcmp(conteudo, "o") == 0) &&
             (strcmp(nome, "trem-1") == 0 || strcmp(nome, "trem-2") == 0)) {
    int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, BRANCO)};
    aplicarEfeitos(efeitos, 1);
  } else {
    int efeitosa[] = {aplicarEfeitoCor(TEXTO_CLARO, ROXO)};
    aplicarEfeitos(efeitosa, 1);
  }
}

void colorirIntegrantes() {
  String conteudo = obterConteudo();
  enum Cor primario = obterPrimario();
  enum Cor secundario = obterSecundario();
  if (strcmp(conteudo, "|") == 0 || strcmp(conteudo, "\\") == 0 ||
      strcmp(conteudo, "//") == 0 || strcmp(conteudo, "_") == 0 ||
      strcmp(conteudo, "/") == 0) {

    ativarEfeitos((int[]){aplicarEfeitoCor(TEXTO_CLARO, secundario)});
  } else {
    ativarEfeitos((int[]){aplicarEfeitoCor(TEXTO_CLARO, primario)});
  }
}

void mostrarIntegrantes() {
  String integrantes[3] = {"João Lucas Silva Lopes", "Alan",
                           "João Pedro Evangelista"};
  // ArquivoResultado integranteLogo =
  // lerLinhaALinha("recursos/integrantes.txt");
  String integrantesAscii = "Integrantes";
  DesenhoAscii integranteLogo =
      desenharAscii("big money", integrantesAscii, strlen(integrantesAscii));
  // debug(integranteLogo.tamanho);
  // for (int i = 0; i < integranteLogo.linhas; i++) {
  //   printf("%c\n", integranteLogo.conteudo[i][integranteLogo.tamanho - 1]);
  // }
  if (!(obterEnergiaTesteAtivado() && obterEnergia() < 20))
    ativarDepois(esperarSegundo);
  ativarAntes(colorirIntegrantes);
  centralizarVerticalTopo(12);
  criar_logo(integranteLogo.conteudo, integranteLogo.linhas,
             integranteLogo.tamanho);
  desativarEfeitos();
  resetarConfig();
  esperarSegundo();
  ativarDepois(esperarSegundo);
  criar_tabela(integrantes, 3);
}

void logos() {
  obterLargura();
  ativarAntes(colorirTrem);

  String trem = "recursos/ascii/logos/logo_principal.txt";
    limpar();
  if (!(obterEnergiaTesteAtivado() && obterEnergia() < 20)) {
    animarTrem(trem);
  } else {
    ArquivoResultado a = lerLinhaALinha(trem);
    centralizarVerticalTopo(a.linhas);
    for (int i = 0; i<a.linhas;i++ ) {
        printf("%s\n", a.conteudo[i]);
    }
    //criar_logo(a.conteudo, a.linhas, maxSize(a.colunas, a.linhas));
    esperar(1000);
  }
  limpar();
  resetarConfig();
  mostrarIntegrantes();
  esperar(1 * 1000);
  limpar();
}