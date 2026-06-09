#include "data.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "idioma.h"

Data data;

String caminhoBanco = "recursos/database/db.bin";
String caminhoBancoHistorico = "recursos/database/historico.bin";

void iniciar() {
  if (arquivoExiste(caminhoBanco)) {

    lerArquivoUnico(&data, Data, caminhoBanco);
    data.registros = malloc(data.registroTamanho * sizeof(Registro));
    ler_arquivo(data.registros, Registro, caminhoBancoHistorico);
  } else {
    data.temperatura = 20;
    data.comunicacao = ESTAVEL;
    data.energia = 100;
    data.energiaTesteAtivado = 0;
  }

  if (data.energiaTesteAtivado && data.energia < 20) {
    desativarCores();
  }
}

int obterTemperatura() { return data.temperatura; }

int obterEnergiaTesteAtivado() { return data.energiaTesteAtivado; }

int obterEnergia() { return data.energia; }

ComunicacaoStatus obterComunicacao() { return data.comunicacao; }

String obterComunicacaoStr() {
  switch (data.comunicacao) {
  case INSTAVEL:
    return "INSTAVEL";
  case NULO:
    return "NULO";
  case ESTAVEL:
    return "ESTAVEL";
  default:
    return "ERRO";
  }
}

void salvar() { 
  escreverArquivoUnico(&data, Data, caminhoBanco); 
  escreverArquivoTamanho(data.registros, data.registroTamanho, Registro, caminhoBancoHistorico);
}

void mudarComunicacao(ComunicacaoStatus comunicacao) {
  data.comunicacao = comunicacao;
  salvar();
}

void mudarEnergia(int energia) {
  data.energia = energia;

  if (obterEnergiaTesteAtivado() && energia < 20) {
    desativarCores();
  } else {
    ativarCores();
  }

  salvar();
}

void mudarTemperatura(int temperatura) {
  data.temperatura = temperatura;
  salvar();
}

void mudarEnergiaTesteAtivado(int energiaTesteAtivado) {
  data.energiaTesteAtivado = energiaTesteAtivado;

  if (energiaTesteAtivado && obterEnergia() < 20) {
    desativarCores();
  } else {
    ativarCores();
  }

  salvar();
}



void adicionarRegistro(Registro registro) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  registro.data = tm;
  data.registros =
      data.registroTamanho == 0
          ? malloc(sizeof(Registro))
          : realloc(data.registros, (data.registroTamanho + 1) * sizeof(Registro));

  data.registros[data.registroTamanho] = registro;
  data.registroTamanho++;
  salvar();
}

Historico obterHistorico() {
  Historico historico = {.tamanho = data.registroTamanho, .registros = data.registros};

  return historico;
}

String obterNomeRegistro(RegistroTipo tipo) {
  {
    String *textos = obterTextos();
    switch (tipo) {
    case INSERCAO_COMUNICACAO:
      return textos[INSERIR_COMUNICACAO];
    case INSERCAO_TEMPERATURA:
      return textos[INSERIR_TEMPERATURA];
    case INSERCAO_ENERGIA:
      return textos[INSERIR_BATERIA];
    case TESTE_COMUNICACAO:
      return textos[TESTAR_COMUNICACAO];
    case TESTE_ENERGIA:
      return textos[TESTAR_BATERIA];
    case TESTE_TEMPERATURA:
      return textos[TESTAR_TEMPERATURA];
    case VISUALIZACAO_STATUS:
      return textos[VISUALIZAR];
    }
  }
}