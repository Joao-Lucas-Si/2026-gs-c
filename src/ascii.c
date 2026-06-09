#include "../utils/utils.h"
#include "ascii.h"
#include <stdlib.h>

FonteAscii definirFonteBigMoney() {

  FonteAscii bigmoney = {
      .altura = 9,
      .caminho = "recursos/ascii/fontes/big-money.txt",
      .nome = "big money",
      .suportes = malloc(5 * sizeof(FonteSuporte)),
      .tamanhoSuporte = 5,
  };
  bigmoney.suportes[0] = ESPACO;
  bigmoney.suportes[1] = NUMEROS;
  bigmoney.suportes[2] = SIMBOLOS2;
  bigmoney.suportes[3] = MAIUSCULAS;
  bigmoney.suportes[4] = MINUSCULAS;

  return bigmoney;
}

FonteAscii definirAlligator() {
    FonteAscii alligator = {
        .altura = 7,
        .caminho="recursos/ascii/fontes/alligator.txt",
        .nome="alligator",
        .suportes = malloc(1 * sizeof(FonteSuporte)),
        .tamanhoSuporte = 1
    };

    alligator.suportes[0] = MAIUSCULAS;

    return alligator;
}

void iniciarFontes() {
    adicionarFonte(definirFonteBigMoney());
    adicionarFonte(definirAlligator());
}