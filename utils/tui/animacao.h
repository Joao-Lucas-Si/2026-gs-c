#ifndef AnimacaoH
#define AnimacaoH
#include "../tipos.h"

enum Comparacao {
    IGUAL,
    MENOR,
    MAIOR
};

void animarTrem(String caminho) ;
void animarValor(int valorInicial, int valorFinal, int valorEtapa, enum Comparacao comparacao, void(*animacao)(int));
#endif