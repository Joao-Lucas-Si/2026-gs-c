#include "../../utils/utils.h"
#include "../data.h"
#include "../fun.h"
#include "../idioma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testeComunicacao() {
  String *textos = obterTextos();
  ArquivoResultado comunicacaoAscii =
      lerLinhaALinha("recursos/ascii/comunicacao.txt");
  ArquivoResultado comunicacaoInstavelAscii =
      lerLinhaALinha("recursos/ascii/comunicacao_falha.txt");
  ArquivoResultado comunicacaoNulaAscii =
      lerLinhaALinha("recursos/ascii/comunicacao_nula.txt");
  ArquivoResultado terra = lerLinhaALinha("recursos/ascii/terra.txt");
  ArquivoResultado nivel;

  switch (obterComunicacao()) {
  case NULO:
    nivel = comunicacaoNulaAscii;
    break;
  case INSTAVEL:
    nivel = comunicacaoInstavelAscii;
    break;
  case ESTAVEL:
    nivel = comunicacaoAscii;
    break;
  }
  char mensagem[] =
      "ola, ola, testando, testando, ha um asteroide a caminho, e necessario "
      "desviar para garantir que ele nao colida com a nave";
  StringParte partes = dividir(mensagem, " ");
  StringEmLinhas linhas = montarParagrafos(partes, 2);

  String original[linhas.linhas + 1];

  original[0] = malloc(100);

  strcpy(original[0], "Mensagem enviada");

  copiarEm(original, linhas.conteudo, 1, linhas.linhas);

  StringEmLinhas encriptado = encriptarMensagem(partes, 2, obterComunicacao());

  String *tabela[4] = {nivel.conteudo, encriptado.conteudo, original,
                       terra.conteudo};
  int i[len(tabela)] = {nivel.linhas, encriptado.linhas, linhas.linhas + 1,
                        terra.linhas};
  enum Cor primario = obterPrimario();
  ativarEfeitos((int[]){aplicarEfeitoCor(FUNDO, primario)});
  centralizar("Testando comunicacao", ' ');
  desativarEfeitos();
  criarTabelaMultilinha(tabela, len(tabela), i, 2);

  pausar();
}

void teste() {
  String *textos = obterTextos();
  int continuar = 1;
  while (continuar) {
    int obterTemperaturaTesteAtivado();
    char energiaMensagem[100];
    sprintf(energiaMensagem, "%s (%s)", textos[TESTAR_BATERIA],
            obterEnergiaTesteAtivado() ? "ativado" : "desativado");

    String opcoes[4] = {textos[SAIR], textos[TESTAR_TEMPERATURA],
                        energiaMensagem, textos[TESTAR_COMUNICACAO]};

    int selecionado = criarMenuSwitch("Painel de Testes", opcoes, 3);
      
    switch (selecionado) {
    case 1:
      continuar = 0;
      break;
    case 2:
      mudarTemperaturaTesteAtivado(!obterTemperaturaTesteAtivado());
      break;
    case 3:
      mudarEnergiaTesteAtivado(!obterEnergiaTesteAtivado());
      break;
    case 4:
      testeComunicacao();
      break;
    }
    limpar();
  }
}