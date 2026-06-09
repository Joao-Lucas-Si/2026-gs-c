#ifndef CorH
#define CorH
#include "../tipos.h"

#define ativarEfeitos(efeitos) ativarEfeitosTamanho(efeitos, len(efeitos))

void desativarEfeitos();
void ativarEfeitosTamanho(int efeitos[], int tamanho) ;
int aplicarEfeitoCor(enum EfeitoCor efeito, enum Cor cor);

typedef struct {
    enum Cor primaria;
    enum Cor secundaria;
    int ativacao;
} CorConfig;

enum Cor obterPrimario();

enum Cor obterSecundario();

void desativarCores();

void ativarCores();

void configurarCores(enum Cor primario, enum Cor secundario);

#endif