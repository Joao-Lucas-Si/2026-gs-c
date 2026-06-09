#include "i18n.h"
#include "tipos.h"
#include <stdlib.h>
#include <string.h>


Lingua *linguas;
int totalLinguas = 0;
String idiomaAtual = "";

Lingua obterIdioma() {
  Lingua atual;
  for (int i = 0; i < totalLinguas; i++) {
    if (strcmp(linguas[i].nome, idiomaAtual) == 0) {
        atual = linguas[i];
        break;
    }
  }
  return atual;
}

void mudarIdioma(String idioma) {
    idiomaAtual = idioma;
}

String* obterTextos() {
    return obterIdioma().textos;
}

void adicionarLingua(Lingua lingua) {
  if (totalLinguas == 0) {
    linguas = malloc(sizeof(Lingua));
    totalLinguas++;
    linguas[0] = lingua;
  } else {
    totalLinguas++;
    linguas = realloc(linguas, totalLinguas * sizeof(Lingua));
    linguas[totalLinguas - 1] = lingua;
  }
}