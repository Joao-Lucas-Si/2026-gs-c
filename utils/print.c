#include "print.h"
#include "tui/cor.h"
#include <stdarg.h>
#include <stdio.h>


PrintConfig printConfig;

void resetarConfig() {
    printConfig.depois = NULL;
    printConfig.efeitos = NULL;
    printConfig.antes = NULL;
    printConfig.efeitosTamanho = 0;
}

void aplicarEfeitos(int* const efeitos, int tamanho) {
    printConfig.efeitos = efeitos;
    printConfig.efeitosTamanho = tamanho;
}

void ativarDepois( void (*depois)()) {
    printConfig.depois = depois;
}

void ativarAntes( void (*antes)()) {
    printConfig.antes = antes;
}

void nomear(char* nome) {
    printConfig.nome = nome;
}

void cederConteudo(char *conteudo) {
    printConfig.conteudo = conteudo;
}

char* obterConteudo() {
    return printConfig.conteudo;
}

char* obterNome() {
    return printConfig.nome;
}
  
void print(const char *__restrict __format, ...) {
    va_list args;
    va_start(args, __format);
    if (printConfig.antes) {
        printConfig.antes();
    }
    if (printConfig.efeitos) {
        ativarEfeitosTamanho(printConfig.efeitos, printConfig.efeitosTamanho);
    }  
    vprintf(__format, args);
    if (printConfig.efeitos) {
        desativarEfeitos();
    }
    if (printConfig.depois) {
        printConfig.depois();
    }
    va_end(args);
}
