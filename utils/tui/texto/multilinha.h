#ifndef MultilinhaH
#define MultilinhaH
#include "../../tipos.h"
#include "../../string.h"
typedef struct StringEmLinhasStruct {
  String *conteudo;
  int linhas;
} StringEmLinhas;
StringEmLinhas montarParagrafos(StringParte palavras, int colunas);
StringEmLinhas quebrarLinhas(String conteudo, int colunas);
#endif