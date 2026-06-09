#ifndef DataH
#define DataH
#include "array.h"
typedef struct {
  char **conteudo;
  int linhas;
  int *colunas;
} ArquivoResultado;

int arquivoExiste(char *filename);

ArquivoResultado lerLinhaALinha(char *caminho);

#define escreverArquivoUnico(instancia, tipo, caminho)                         \
  ({                                                                           \
    FILE *arquivo = fopen(caminho, "w");                                       \
    fwrite(instancia, sizeof(tipo), 1, arquivo);                               \
    fclose(arquivo);                                                           \
  })

#define lerArquivoUnico(instancia, tipo, caminho)                              \
  ({                                                                           \
    FILE *arquivo = fopen(caminho, "r");                                       \
    fread(instancia, sizeof(tipo), 1, arquivo);                                \
    fclose(arquivo);                                                           \
  })

#define ler_arquivo(lista, tipo, caminho)                                      \
  ({                                                                           \
    FILE *arquivo = fopen(caminho, "r");                                       \
    int ij = 0;                                                                \
    tipo instancia;                                                            \
    while (fread(&instancia, sizeof(tipo), 1, arquivo)) {                      \
      lista[ij] = instancia;                                                   \
      ij++;                                                                    \
    }                                                                          \
    fclose(arquivo);                                                           \
  })

#define escreverArquivoTamanho(lista, tamanho, tipo, caminho)                  \
  ({                                                                           \
    FILE *arquivo = fopen(caminho, "w");                                       \
    for (int i = 0; i < tamanho; i++) {                                        \
      fwrite(&lista[i], sizeof(tipo), 1, arquivo);                             \
    }                                                                          \
    fclose(arquivo);                                                           \
  })

#define escrever_arquivo(lista, tipo, caminho)                                 \
  escreverArquivoTamanho(lista, len(lista), caminho)

#endif