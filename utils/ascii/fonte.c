#include "fonte.h"
#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pontos[7] = {0, 1, 16, 26, 33, 62, 65};

int tamanhos[7] = {1, 15, 10, 7, 26, 6, 26};

FonteAscii *fontes;
int tamanhoFontes;

void adicionarFonte(FonteAscii fonte) {
  if (tamanhoFontes == 0) {
    tamanhoFontes++;
    fontes = malloc(sizeof(FonteAscii));
    fontes[0] = fonte;
  } else {
    tamanhoFontes++;
    fontes = realloc(fontes, tamanhoFontes * sizeof(FonteAscii));
    fontes[tamanhoFontes - 1] = fonte;
  }
}

FonteAscii obterFonte(String nome) {
  for (int i = 0; i < tamanhoFontes; i++) {
    if (strcmp(fontes[i].nome, nome) == 0) {
      return fontes[i];
    }
  }
  mostrarErro("Fonte não suportada");
  exit(1);
}

int comeco = 32;

int verificarSuporte(FonteSuporte *suportados, int tamanho, FonteSuporte alvo) {

  for (int i = 0; i < tamanho; i++) {
    if (suportados[i] == alvo) {
      return 1;
    }
  }

  return 0;
}

int obterInicio(FonteSuporte suporte, FonteSuporte *suportados, int tamanho) {
  int index = 0;
  for (int i = ESPACO; i < suporte; i++) {
    if (!verificarSuporte(suportados, tamanho, i)) {
      index += tamanhos[i];
    }
  }

  return index ;
}



DesenhoAscii desenharAscii(String fonteNome, String conteudo, int tamanho) {
  FonteAscii fonte = obterFonte(fonteNome);
  int maximo = 0;
  String *caracteres = lerLinhaALinha(fonte.caminho).conteudo;
  String *linhas = malloc(fonte.altura * sizeof(String));

  for (int i = 0; i < tamanho; i++) {
    char caractere = conteudo[i];
    int alvo = -1;
    int code = caractere - comeco;
    if (code == pontos[0] &&
        verificarSuporte(fonte.suportes, fonte.tamanhoSuporte, ESPACO)) {
      alvo = 0;
    } else if (code >= pontos[1] && code < pontos[2] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                SIMBOLOS)) {

      alvo = code - obterInicio(SIMBOLOS, fonte.suportes, fonte.tamanhoSuporte);
    } else if (code >= pontos[2] && code < pontos[3] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                NUMEROS)) {

      alvo = code - obterInicio(NUMEROS, fonte.suportes, fonte.tamanhoSuporte);
    } else if (code >= pontos[3] && code < pontos[4] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                SIMBOLOS2)) {
      alvo =
          code - obterInicio(SIMBOLOS2, fonte.suportes, fonte.tamanhoSuporte);
    } else if (code >= pontos[4] && code < pontos[5] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                MAIUSCULAS)) {
      alvo =
          code - obterInicio(MAIUSCULAS, fonte.suportes, fonte.tamanhoSuporte);
    } else if (code >= pontos[5] && code < pontos[6] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                SIMBOLOS3)) {
      alvo =
          code - obterInicio(SIMBOLOS3, fonte.suportes, fonte.tamanhoSuporte);
    } else if (code >= pontos[6] &&
               verificarSuporte(fonte.suportes, fonte.tamanhoSuporte,
                                MINUSCULAS)) {
      // print("code: %d\n", code);
      // print("inicio: %d\n",
      //       obterInicio(MINUSCULAS, fonte.suportes, fonte.tamanhoSuporte));
      alvo =
          code - obterInicio(MINUSCULAS, fonte.suportes, fonte.tamanhoSuporte);
    }
   
    if (alvo == -1) {
      mostrarErro(stringf(50, "caractere não encontrado: %c", caractere));
      exit(1);
    }
    if (maximo == 0) {
      maximo = strlen(caracteres[alvo]);
      for (int i = 0; i < fonte.altura; i++) {
        linhas[i] =
            stringf(maximo, "%s", caracteres[(alvo * fonte.altura) + i]);
      }
    } else {
      maximo += strlen(caracteres[alvo]);
      for (int i = 0; i < fonte.altura; i++) {
        linhas[i] = stringf(maximo + 10, "%s%s", linhas[i],
                            caracteres[(alvo * fonte.altura) + i]);
      }
    }
  }
  DesenhoAscii desenho = {
    .conteudo = linhas,
    .linhas = fonte.altura,
    .tamanho = strlen(linhas[0])
  };
  return desenho;
}
