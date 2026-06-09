#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Historico historicos[100];

// char *idAtual;

// int acharHistorico(Historico historico) {
//   if (historico.id == NULL) {
//     return 0;
//   }
//   return strcmp(historico.id, idAtual);
// }

// char *obterTexto(Opcao opcao) {
//   char *texto = opcao.texto;
//   return texto;
// }

int _criarMenuSwitch(char *titulo, String *opcoes, int tamanho, int colunas) {
  //   idAtual = id;
  //   Historico *historico = find(historicos, acharHistorico);

  //   if (historico == NULL) {
  //     Historico novo = {.id = id, .atual = 0};
  //     novo.acessados = malloc(sizeof(Historico));
  //     historico = &novo;
  //   }
  int primario = obterPrimario();
  int selecionado = 0;

  while (1) {
    int efeitos[] = {aplicarEfeitoCor(FUNDO_CLARO, primario), BOLD};
    ativarEfeitosTamanho(efeitos, 2);
    centralizar(titulo, ' ');
    desativarEfeitos();
    _criar_tabela(opcoes, tamanho, colunas);
    // centralizar("--", '-');
    printf("\nescolha: ");
    scanf("%d", &selecionado);
    limpar();

    // if (selecionado == 0) {
    //   break;
    // }

    if (selecionado < 0 || selecionado > tamanho) {
      mostrarErro("valor invalido\n");
      continue;
    }

    // selecionado--;
    return selecionado;
    // opcoes[selecionado].codigo();
    // if (!containsSize(historico->acessados, historico->atual, selecionado)) {
    //   historico->acessados = expand(historico->acessados);
    //   historico->acessados[historico->atual] = selecionado;
    //   //     debug(historico->acessados[historico->atual]);
    //   historico->atual++;
    // }
    // limpar();
  }
  return 0;
}

void _criarMenuMultilinhaDinamica(String titulo,
                                  MenuConteudoDinamico (*gerarConteudo)(),
                                  OpcaoMenu *opcoes, int quantidadeOpcoes,
                                  int tamanho, int colunas) {
  enum Cor primario = obterPrimario();
  int selecionado = 1;
  while (selecionado != 0) {
    int efeitos[] = {aplicarEfeitoCor(FUNDO_CLARO, primario), BOLD};
    ativarEfeitosTamanho(efeitos, 2);
    centralizar(titulo, ' ');
    desativarEfeitos();
    MenuConteudoDinamico conteudoDinamico = gerarConteudo();
    String **conteudo = conteudoDinamico.conteudo;
    int *linhas = conteudoDinamico.tamanho;
    // for (int i = 0; i < tamanho; i++) {
    //   for (int j = 0; j < linhas[i]; j++) {
    //     if (conteudo[i] && conteudo[i][j]) {
    //       printf("%s", conteudo[i][j]);
    //     }
    //   }
    // }
     criarTabelaMultilinha(conteudo, tamanho, linhas, colunas);

    printf("escolha: ");
    scanf("%d", &selecionado);
    limpar();

    if (selecionado == 0) {
      break;
    }
    if (selecionado < 1 || selecionado > quantidadeOpcoes) {
      mostrarErro("valor invalido\n");
      continue;
    }

    opcoes[selecionado - 1]();
    limpar();
  }
}

void _criarMenuMultilinha(String titulo, String **conteudo, OpcaoMenu *opcoes,
                          int quantidadeOpcoes, int tamanho, int *linhas,
                          int colunas) {
  enum Cor primario = obterPrimario();
  int selecionado = 1;
  while (selecionado != 0) {
    int efeitos[] = {aplicarEfeitoCor(FUNDO_CLARO, primario), BOLD};
    ativarEfeitosTamanho(efeitos, 2);
    centralizar(titulo, ' ');
    desativarEfeitos();

    criarTabelaMultilinha(conteudo, tamanho, linhas, colunas);

    printf("escolha: ");
    scanf("%d", &selecionado);
    limpar();

    if (selecionado == 0) {
      break;
    }
    if (selecionado < 1 || selecionado > quantidadeOpcoes) {
      mostrarErro("valor invalido\n");
      continue;
    }

    opcoes[selecionado - 1]();
    limpar();
  }
}