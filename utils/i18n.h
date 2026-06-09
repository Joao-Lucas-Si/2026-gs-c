#ifndef I18nH
#define I18nH
#include "tipos.h"
typedef struct {
  String nome;
  String *textos;
} Lingua;

void mudarIdioma(String idioma);
String* obterTextos();
void adicionarLingua(Lingua lingua) ;
#endif