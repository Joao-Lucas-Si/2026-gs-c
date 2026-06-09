#ifndef StringH
#define StringH
#include "tipos.h"
typedef struct StringParteStruct {
  String *palavras;
  int tamanho;
} StringParte;
StringParte dividir(String str, const String separador);
char* substituir(char* str, char find, char replace);
int strMax(char** textos, int tamanho);
void copiarEm(String *dest, String *src, int indice, int tamanho) ;

String stringf(int, const String __restrict __format, ...);
#endif