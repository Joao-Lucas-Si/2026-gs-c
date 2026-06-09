#ifndef MenusH
#define MenusH
#include "../tipos.h"
// typedef struct HistoricoStruct {
//   char *id;
//   int atual;
//   int *acessados;
// } Historico;
// typedef struct OpcaoStruct {
//   char texto[100];
//   void (*codigo)();
// } Opcao;

typedef struct {
  String **conteudo;
  int *tamanho;
} MenuConteudoDinamico;

typedef void (*OpcaoMenu)();
void _criarMenuMultilinhaDinamica(String titulo,
                                  MenuConteudoDinamico (*gerarConteudo)(),
                                  OpcaoMenu *opcoes, int quantidadeOpcoes,
                                  int tamanho, int colunas);

int _criarMenuSwitch(char *titulo, String *opcoes, int tamanho, int colunas);
#define criarMenuSwitch(titulo, opcoes, colunas)                               \
  _criarMenuSwitch(titulo, opcoes, len(opcoes), colunas)
void _criarMenuMultilinha(String titulo, String **conteudo, OpcaoMenu *opcoes,
                          int quantidadeOpcoes, int tamanho, int *linhas,
                          int colunas);
#endif