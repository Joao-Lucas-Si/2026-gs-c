#include "array.h"
#include <stdio.h>
#include <stdlib.h>




#define arrayForEach(array, callback) for (int i = 0; i< array.tamanho; i++) {\
 callback(array.valores[i]);\
}

void* expandir(void* lista, int* tamanho) {
    *tamanho+= 1;
    printf("%d\n", *tamanho);
    return realloc(lista, (*tamanho ) * sizeof(lista[0]));
}


// int whileLen(void ** array) {
//     int i = 0;
//     while (array[i] != NULL) {
//         i++;
//     }

//     return 0;
// }


// typedef enum {
//     FLOAT,
//     INT,
// } NumericoTipo;

// typedef union {
//     int intv;
//     float floatv;
// } Numerico;

