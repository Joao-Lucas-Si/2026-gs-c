#ifndef FonteH
#define FonteH
#include "../tipos.h"
typedef enum {
    ESPACO, 
    SIMBOLOS,
    NUMEROS,
    SIMBOLOS2,
    MAIUSCULAS,
    SIMBOLOS3,
    MINUSCULAS,
} FonteSuporte;

typedef struct {
    String nome;
    FonteSuporte* suportes;
    int tamanhoSuporte;
    int altura;
    String caminho;
} FonteAscii ;

typedef struct {
    String* conteudo;
    int linhas;
    int tamanho;
} DesenhoAscii;

void adicionarFonte(FonteAscii fonte);
DesenhoAscii desenharAscii(String fonteNome, String conteudo, int tamanho);
#endif