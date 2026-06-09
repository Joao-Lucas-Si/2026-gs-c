#ifndef LayoutH
#define LayoutH
#include "../tipos.h"
void centralizarFixado(char *conteudo, char sep, int largura);
void centralizar_limitado(char *conteudo, char sep, int maximo);
void repetir(char c, int tamanho);
void centralizar(char *conteudo, char sep);
void centralizarVertical(void (*conteudo)(Any* vargs), int tamanho, Any* args);
void centralizarFixadoTamanho(char *conteudo, char sep, int largura, int tamanho);
void centralizarVerticalTopo(int tamanho);
#endif