#ifndef TabelaH
#define TabelaH
#include "../../tipos.h"
typedef struct LinhaStruct {
  char *conteudo;
} Linha;
// void criarTabelaMultilinha(String **conteudo, int colunas, int *linhas,
//                            int sep);

int criarMenuSwitchMultilinha(String titulo, String **conteudo, int tamanho, int *linhas,
                               int colunas);


typedef struct {
  String** conteudo;
  int linhas;
} StringMultilinha;


typedef struct {
  String *esquerda;
  int esquerTamanho;
  String *direita;
  int direitaTamanho;
  // String *centro;
} MenuOpcoes;

int criarMenuSwitchMultilinhaComOpcoes(String titulo, String **conteudo,
                                       int tamanho, int *linhas, int colunas,
                                       MenuOpcoes opcoes) ;

StringMultilinha criarMultilinha(String **conteudo, int colunas, int *linhas, int sep);

StringMultilinha _criarTabelaMultilinha(String **conteudo, int colunas, int *linhas, int sep);
void criarTabelaMultilinha(String **conteudo, int colunas, int *linhas,
                            int sep);
#endif