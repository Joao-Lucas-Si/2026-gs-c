#ifndef GsDataH
#define GsDataH
#include "../utils/tipos.h"
#include "time.h"
typedef enum ComunicacaoStatusEnum {
  NULO = 0,
  INSTAVEL = 1,
  ESTAVEL = 2
} ComunicacaoStatus;

ComunicacaoStatus obterComunicacao();

int obterEnergia();

int obterTemperatura();

int obterEnergiaTesteAtivado();

String obterComunicacaoStr();

void mudarComunicacao(ComunicacaoStatus comunicacao);
void mudarEnergia(int energia);
void mudarEnergiaTesteAtivado(int);
void mudarTemperatura(int temperatura);
void salvar();
void iniciar();

typedef enum {
  INSERCAO_COMUNICACAO,
  INSERCAO_TEMPERATURA,
  INSERCAO_ENERGIA,
  TESTE_COMUNICACAO,
  TESTE_ENERGIA,
  TESTE_TEMPERATURA,
  // VISUALIZACAO,
  VISUALIZACAO_STATUS
} RegistroTipo;

String obterNomeRegistro(RegistroTipo tipo);
typedef struct {
  RegistroTipo tipo;
  int valor;
  struct tm data;
} Registro;

void adicionarRegistro(Registro registro);

typedef struct {

  Registro *registros;
  int tamanho;
} Historico;

Historico obterHistorico();

typedef struct DataStruct {
  int temperatura;
  ComunicacaoStatus comunicacao;
  int energia;
  int energiaTesteAtivado;
  Registro *registros;
  int registroTamanho;
} Data;

#endif