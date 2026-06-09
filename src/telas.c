#include "../utils/utils.h"
#include "data.h"
#include "idioma.h"
#include "introducao.h"
#include "telas/teste.c"
#include "telas/historico.h"
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void insercaoComunicacao() {
  ArquivoResultado comunicacaoAscii =
      lerLinhaALinha("recursos/ascii/comunicacao.txt");
  ArquivoResultado comunicacaoInstavelAscii =
      lerLinhaALinha("recursos/ascii/comunicacao_falha.txt");
  ArquivoResultado comunicacaoNulaAscii =
      lerLinhaALinha("recursos/ascii/comunicacao_nula.txt");

  String estavel[13] = {"3. Estavel"};
  copiarEm(estavel, comunicacaoAscii.conteudo, 1, comunicacaoAscii.linhas);
  String instavel[13] = {"2. Instavel"};
  copiarEm(instavel, comunicacaoInstavelAscii.conteudo, 1,
           comunicacaoInstavelAscii.linhas);
  String nulo[13] = {"1. Nulo"};
  copiarEm(nulo, comunicacaoNulaAscii.conteudo, 1, comunicacaoNulaAscii.linhas);
  String *tabela[3] = {nulo, instavel, estavel};
  int i[3] = {13, 13, 13};
  int selecionado = criarMenuSwitchMultilinha("Inserir Comunicação", tabela,
                                              len(tabela), i, 3);

  mudarComunicacao(selecionado - 1);
  Registro registro = {
      .tipo = INSERCAO_COMUNICACAO,
      .valor = selecionado - 1,

  };
  adicionarRegistro(registro);
  limpar();
}

void inserirMenu() {
  String *textos = obterTextos();
  enum Cor primario = obterPrimario();
  ArquivoResultado porta = lerLinhaALinha("recursos/ascii/saida.txt");
  ArquivoResultado temperaturaAscii =
      lerLinhaALinha("recursos/ascii/temperatura.txt");
  ArquivoResultado energiaAscii = lerLinhaALinha("recursos/ascii/energia.txt");
  ArquivoResultado comunicacaoAscii =
      lerLinhaALinha("recursos/ascii/comunicacao.txt");

  int continuar = 1;
  while (continuar) {
    String saida[10] = {
        stringf(100, "1. %s", textos[SAIR]),
    };
    copiarEm(saida, porta.conteudo, 1, porta.linhas);
    String temperatura[temperaturaAscii.linhas + 3];
    temperatura[0] = malloc(100);
    temperatura[1] = "";
    temperatura[2] = "";
    sprintf(temperatura[0], "2. %s (%d/100)", textos[INSERIR_TEMPERATURA],
            obterTemperatura());

    copiarEm(temperatura, temperaturaAscii.conteudo, 3,
             temperaturaAscii.linhas);
    String energia[energiaAscii.linhas + 1];
    energia[0] = malloc(100);
    sprintf(energia[0], "3. %s (%d/100)", textos[INSERIR_BATERIA],
            obterEnergia());
    copiarEm(energia, energiaAscii.conteudo, 1, energiaAscii.linhas);

    String comunicacao[comunicacaoAscii.linhas + 1];
    comunicacao[0] = malloc(100);
    sprintf(comunicacao[0], "4. %s (%s)", textos[INSERIR_COMUNICACAO],
            obterComunicacaoStr());
    copiarEm(comunicacao, comunicacaoAscii.conteudo, 1,
             comunicacaoAscii.linhas);

    String *opcoes[4] = {saida, temperatura, energia, comunicacao};
    int i[5] = {len(saida), len(temperatura), len(energia), len(comunicacao)};
    int temperaturaValor = 0;
    int energiaValor = 0;
    int efeitos[1] = {aplicarEfeitoCor(TEXTO, primario)};
    int selecionado = criarMenuSwitchMultilinha("Inserção de dados", opcoes,
                                                len(opcoes), i, 2);
    switch (selecionado) {
    case 1:
      continuar = 0;
      break;
    case 2:
      ativarEfeitos(efeitos);
      printf("temperatura: ");
      desativarEfeitos();
      scanf("%d", &temperaturaValor);
      mudarTemperatura(temperaturaValor);
      Registro registroTemperatura = {
          .tipo = INSERCAO_TEMPERATURA,
          .valor = temperaturaValor,

      };
      adicionarRegistro(registroTemperatura);
      break;
    case 3:
      ativarEfeitos(efeitos);
      printf("energia: ");
      desativarEfeitos();
      scanf("%d", &energiaValor);
      mudarEnergia(energiaValor);
      Registro registroEnergia = {
          .tipo = INSERCAO_ENERGIA,
          .valor = energiaValor,

      };
      adicionarRegistro(registroEnergia);
      break;

    case 4:
      insercaoComunicacao();
      break;
    }
  }
}

void colorirCritico() {
  String conteudo = obterConteudo();
  String nome = obterNome();
  if (nome && nome[2] == '0') {
    int f[1] = {aplicarEfeitoCor(TEXTO, VERMELHO)};
    aplicarEfeitos(f, len(f));
  } else {
    aplicarEfeitos(NULL, 0);
  }
}

void colorirAtencao() {
  String conteudo = obterConteudo();
  String nome = obterNome();
  if (nome && nome[2] == '0') {
    int f[1] = {aplicarEfeitoCor(TEXTO, LARANJA)};
    aplicarEfeitos(f, len(f));
  } else {
    aplicarEfeitos(NULL, 0);
  }
}

void statusMenu() {
  String *textos = obterTextos();
  DesenhoAscii critico =
      desenharAscii("alligator", textos[CRITICO], strlen(textos[CRITICO]));
  DesenhoAscii falha =
      desenharAscii("alligator", textos[ATENCAO], strlen(textos[ATENCAO]));
  DesenhoAscii seguro =
      desenharAscii("alligator", textos[SEGURO], strlen(textos[SEGURO]));

  DesenhoAscii alerta;
  int erros = 0;

  if (obterTemperatura() > 80) {
    erros++;
  }
  if (obterEnergia() < 20) {
    erros++;
  }
  if (obterComunicacao() == 0) {
    erros++;
  }

  if (erros >= 2) {
    alerta = critico;
  } else if (erros >= 1) {
    alerta = falha;
  } else {
    alerta = seguro;
  }

  String mensagem[7];
  copiarEm(mensagem, alerta.conteudo, 0, alerta.linhas);
  int t = 120;
  String data[11] = {malloc(t), malloc(t), malloc(t), "",
                     malloc(t), malloc(t), malloc(t), "",
                     malloc(t), malloc(t), malloc(t)};

  snprintf(data[0], t, "energia:");
  snprintf(data[1], t, "%d/100", obterEnergia());
  snprintf(data[2], t, "%s", obterEnergia() < 20 ? "economia de energia" : "");
  snprintf(data[4], t, "temperatura");
  snprintf(data[5], t, "%d/100", obterTemperatura());
  snprintf(data[6], t, "%s", obterTemperatura() > 80 ? "superaquecimento" : "");
  snprintf(data[8], t, "comunicacao: ");
  snprintf(data[9], t, "%s", obterComunicacaoStr());
  snprintf(data[10], t, "%s", obterComunicacao() == NULO ? "Falha" : "");

  String *tabela[2] = {
      mensagem,
      data,
  };
  int tamanho[2] = {alerta.linhas, len(data)};

  int f[1] = {aplicarEfeitoCor(FUNDO, ROXO)};
  ativarEfeitos(f);
  centralizar("Status", ' ');
  desativarEfeitos();
  printf("\n");
  if (erros >= 2) {
    ativarAntes(colorirCritico);
  } else if (erros >= 1) {
    ativarAntes(colorirAtencao);
  }
  criarTabelaMultilinha(tabela, len(tabela), tamanho, 2);
  resetarConfig();
  pausar();
  limpar();
  Registro registro = {.tipo = VISUALIZACAO_STATUS};

  adicionarRegistro(registro);
}

void estilizarAstronauta() {
  String nome = obterNome();
  StringParte cordenadas = dividir(nome, ",");
  enum Cor primario = obterPrimario();
  if (cordenadas.tamanho > 1) {
    int y = stringParaInteiro(cordenadas.palavras[0]);
    int x = stringParaInteiro(cordenadas.palavras[1]);
    if ((y > 1 && y < 12) || (y > 12 && y < 23)) {
      int efeitos[] = {aplicarEfeitoCor(TEXTO_CLARO, primario)};
      aplicarEfeitos(efeitos, len(efeitos));
    } else {
      aplicarEfeitos(NULL, 0);
    }
  }
}


void principal() {
  String *textos = obterTextos();
  enum Cor primario = obterPrimario();
  enum Cor secundario = obterSecundario();
  ArquivoResultado porta = lerLinhaALinha("recursos/ascii/saida.txt");
  ArquivoResultado salvarAscii = lerLinhaALinha("recursos/ascii/inserir.txt");
  ArquivoResultado escudoAscii = lerLinhaALinha("recursos/ascii/escudo.txt");
  ArquivoResultado papiroAscii = lerLinhaALinha("recursos/ascii/papiro.txt");
  ArquivoResultado painelAscii = lerLinhaALinha("recursos/ascii/painel.txt");
  ArquivoResultado logoCompacta =
      lerLinhaALinha("recursos/ascii/logos/logo_compacta.txt");
  ArquivoResultado logoMinima =
      lerLinhaALinha("recursos/ascii/logos/logo_minima.txt");

  // int f[2] = {aplicarEfeitoCor(FUNDO, primario), BOLD};
  // ativarEfeitos(f);

  String encerrar[porta.linhas + 1];

  encerrar[0] = stringf(100, "1. %s", textos[ENCERRAR]);

  copiarEm(encerrar, porta.conteudo, 1, porta.linhas);
  //"Executar análise",

  String dados[salvarAscii.linhas + 1];
  dados[0] = stringf(100, "2. %s", textos[INSERIR]);

  copiarEm(dados, salvarAscii.conteudo, 1, salvarAscii.linhas + 1);

  String visualizar[painelAscii.linhas + 1];
  visualizar[0] = stringf(100, "3. %s", textos[VISUALIZAR]);

  copiarEm(visualizar, painelAscii.conteudo, 1, painelAscii.linhas);

  String testar[escudoAscii.linhas + 1];

  testar[0] = stringf(100, "5. %s", textos[TESTAR]);

  copiarEm(testar, escudoAscii.conteudo, 1, escudoAscii.linhas);

  String historico[papiroAscii.linhas + 1];

  historico[0] = stringf(100, "4. %s", textos[HISTORICO]);

  copiarEm(historico, papiroAscii.conteudo, 1, papiroAscii.linhas);

  String creditos[logoCompacta.linhas + 1];
  creditos[0] = stringf(100, "6. %s", textos[CREDITOS]);

  copiarEm(creditos, logoCompacta.conteudo, 1, logoCompacta.linhas);

  String *opcoes[6] = {encerrar,  dados,  visualizar,
                       historico, testar, creditos};
  int continuar = 1;
  int tamanhos[6] = {len(encerrar),  len(dados),  len(visualizar),
                     len(historico), len(testar), len(creditos)};

  MenuOpcoes menu = {.esquerTamanho = logoMinima.linhas,
                     .esquerda = logoMinima.conteudo};
  while (continuar) {
    // ativarAntes(estilizarAstronauta);

    int selecionado = criarMenuSwitchMultilinha(textos[PAINEL], opcoes,
                                                len(opcoes), tamanhos, 3);
    // resetarConfig();
    switch (selecionado) {
    case 1:
      continuar = 0;
      break;
    case 2:
      inserirMenu();
      break;

    case 3:
      statusMenu();
      break;
    case 4:
      verHistorico();
      break;
    case 5:
      teste();
      break;
    case 6:
      logos();
      break;
    }
  }
}
