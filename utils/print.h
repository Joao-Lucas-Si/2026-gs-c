#ifndef PrintH
#define PrintH
typedef struct {
    void (*depois)();
    int* efeitos;
    char* nome;
    int efeitosTamanho;
    char* conteudo;
    void (*antes)();
} PrintConfig;
void print(const char *__restrict __format, ...);
void resetarConfig();
void aplicarEfeitos(int* const efeitos, int tamanho);
void ativarAntes( void (*antes)());
void nomear(char* nome);
char* obterNome();
char* obterConteudo();
void cederConteudo(char* conteudo);
void ativarDepois( void (*depois)());
#endif