#ifndef Sistema
#define Sistema

#if defined(_WIN32) || defined(_WIN32)
#define eWindows 1
#else
#define eWindows 0
#endif


void limpar();
int obterLargura();
int obterAltura();

void esperar(int microSegundos);
void pausar();
int tamanhoColuna(int colunas);
#endif