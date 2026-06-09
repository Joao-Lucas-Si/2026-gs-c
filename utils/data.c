#include "data.h"
#include "array.h"
#include "array.h"
#include "tipos.h"
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
int arquivoExiste(char *filename) {
  struct stat buffer;
  return (stat(filename, &buffer) == 0);
}

// typedef struct DataStruct {
//   char *nome;
//   int idade;
// } Data;

/*while (fgetc(arquivo) != EOF) {                                            \
      printf("%d", i);                                                         \
      i++;                                                                     \
    }

*/
// // size_t result =
// void printarNome(Data data) { debug(data.nome); }

// void call(Data *data) { printf("%s", data->nome); }

// int main() {
//   char *caminho = "data.bin";
//   Data data[2] = {{.nome = "12", .idade = 12}, {.nome = "ds", .idade = 15}};
//   escrever_arquivo(data, Data, caminho);

//   Data lista[10] = {};
//   ler_arquivo(lista, Data, caminho, call);

//   forEach(lista, printarNome);
//   return 0;
// }

void removechar(char str[], char t) {
  int i, j;
  i = 0;
  while (i < strlen(str)) {
    if (str[i] == t) {
      for (j = i; j < strlen(str); j++)
        str[j] = str[j + 1];
    } else
      i++;
  }
}

typedef struct {
  String caminho;
  ArquivoResultado arquivo;
} ArquvioCache;

typedef struct {
  ArquvioCache* arquivos;
  int tamanho;
} CacheLista;

CacheLista cache;

ArquivoResultado lerLinhaALinha(char *caminho) {
  for (int i = 0; i < cache.tamanho; i++) {
    // debug(caminho);
    // debug("ca");
    // debug(cache.arquivos[i].caminho);
    if (strcmp(cache.arquivos[i].caminho, caminho) == 0) {
      return cache.arquivos[i].arquivo;
    }
  }
  FILE *arquivo = fopen(caminho, "r");
  char linha[500];
  int atual = 1;
  int tamanho = sizeof(char[500]);

  int *colunas = malloc(atual * sizeof(int));
  char **conteudo = malloc(atual * tamanho);
  int i = 0;
  ArquivoResultado resultado;
  while (fgets(linha, tamanho, arquivo)) {
    char padrao[500];
    if (i > 0) {
      atual++;
      conteudo = realloc(conteudo, atual * tamanho);
      colunas = realloc(colunas, atual * sizeof(int));
    }
    conteudo[i] = (char *)malloc(tamanho);
    conteudo[i][0] = 0;
    // removechar(linha, '\n');
    linha[strcspn(linha, "\n")] = 0;
    snprintf(conteudo[i], 500, "%s", linha);
    // conteudo[i] = linha;
    // conteudo[i] =
    // strcpy(conteudo[i], linha);

    int coluna = strlen(linha);
    colunas[i] = coluna;
    i++;
  }

  resultado.linhas = atual;
  resultado.conteudo = conteudo;

  resultado.colunas = colunas;
  fclose(arquivo);

  cache.arquivos =
      cache.tamanho == 0
          ? malloc((cache.tamanho + 1) * sizeof(ArquvioCache))
          : realloc(cache.arquivos, (cache.tamanho + 1) * sizeof(ArquvioCache));
  ArquvioCache data = {.caminho = caminho, .arquivo = resultado};
  cache.arquivos[cache.tamanho] = data;
  cache.tamanho++;
  return resultado;
}