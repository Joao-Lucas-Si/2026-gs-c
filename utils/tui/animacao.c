#include "../sistema.h"
#include "cor.h"
#include "../data.h"
#include <stdarg.h>
#include <stdio.h>
#include "../tipos.h"
#include "layout.h"
#include "../print.h"

#include "animacao.h"

void animarValor(int valorInicial, int valorFinal, int valorEtapa, enum Comparacao comparacao, void(*animacao)(int)) {
    int valor = valorInicial;
    while ((comparacao == IGUAL && valor != valorFinal) || (comparacao == MAIOR && valor < valorFinal) || (comparacao == MENOR && valor > valorFinal)) {
        
        animacao(valor);
        esperar(175);

        valor += valorEtapa;
    }
}

ArquivoResultado ascii;

void trem(int valor) {
    limpar();
    int largura = obterLargura();
    int train = 400;

    int maxAltura = 7;
    int max = largura + train;
   
    int atual = largura - valor;
    centralizarVerticalTopo(maxAltura);
    // repetir(alturaParcial, '\n');
    for (int i = 0; i < maxAltura; i++) {
        int esquerda = atual < 0 ? 0 : atual ;
        if (esquerda > 0) {
            repetir(' ', esquerda);
        }
        int tremP = valor > train ? train : valor;
        int tremI = valor > largura ? valor - largura : 0;
        
        if (valor) {
            char nome[100];
            sprintf(nome, "trem-%d", i);
            nomear(nome);
            for (int j = tremI; j < tremP; j++) {
                if (ascii.conteudo[i] && ascii.conteudo[i][j]) {
                    char target[2] = " \0";
                    sprintf(target, "%c", ascii.conteudo[i][j]);
                    cederConteudo(target);

                    print("%c", ascii.conteudo[i][j]);
                }else {
                    print(" ");
                }
            }
        }
        // int direita = (train - valor) * -1;
        
        // if (direita > 0) repetir(direita, ' ');
        printf("\n");
    }
    // repetir(alturaParcial, '\n');
}

void animarTrem(String caminho) {
    ascii = lerLinhaALinha(caminho);
    int largura = obterLargura();
    int altura = obterAltura();
    int trainLargura = 100;
    int max = largura + trainLargura;
    int maxAltura = 100;
    int efeitos[] = { BOLD, aplicarEfeitoCor(TEXTO_CLARO, ROXO) };
    ativarEfeitosTamanho(efeitos, len(efeitos));
    animarValor(0, max, 5, MAIOR, trem);
    desativarEfeitos();
}

// int main() {
//     limpar();
    
//      animarTrem();
//     return 0;
// }