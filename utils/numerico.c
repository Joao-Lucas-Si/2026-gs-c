#include "tipos.h"
#include <stdio.h>
#include <string.h>

int potencia(int x, int y) {
    int resultado = 1;
    for (int i = 1; i <= y; i++) {
        resultado *= x;
    }

    return resultado;
}

int stringParaInteiro(String str) {
    int tamanho = strlen(str);
    int resultado = 0;
    for (int i = 1 ; i<= tamanho; i ++) {
        int numero = str[i-1] - '0';

        if (numero >= 0 && numero <= 9) {
            resultado += numero * potencia(10, tamanho - i);
        }
    }

    return resultado;
}