#ifndef UIH
#define UIH
#include "../tipos.h"
void criar_logo(char **logo, int tamanho, int textoTamanho);

void _criar_tabela(String *tabela, int tamanho, int colunas);

#define criar_tabela(tabela, colunas)                                          \
  {                                                                            \
    _criar_tabela(tabela, len(tabela), colunas);                               \
  }
void mostrarErro(char *erro);
  
#endif