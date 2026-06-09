#include "../../utils/utils.h"
#include "../data.h"
#include <stdio.h>

void verHistorico() {
  Historico historico = obterHistorico();

  centralizar("Historico", ' ');

  for (int i = historico.tamanho - 1; i >= 0; i--) {
    Registro registro = historico.registros[i];
    String data =
        stringf(50, "%02d/%02d/%d %02d:%02d", registro.data.tm_mday,
                registro.data.tm_mon + 1, registro.data.tm_year + 1900,
                registro.data.tm_hour, registro.data.tm_min);
    switch (registro.tipo) {
    case INSERCAO_COMUNICACAO:
    case INSERCAO_ENERGIA:
    case INSERCAO_TEMPERATURA:
      printf("acao: %s, valor: %d data: %s\n", obterNomeRegistro(registro.tipo),
             registro.valor, data);
      break;
    default:
      printf("acao: %s, data: %s \n", obterNomeRegistro(registro.tipo), data);
      break;
    }
  }
  pausar();
}