#ifndef Tipos 
#define Tipos
typedef char* String;

enum Cor {
  CINZA = 0,
  VERMELHO = 1,
  VERDE = 2,
  LARANJA = 3,
  AZUL = 4,
  ROXO = 5,
  CIANO = 6,
  BRANCO = 7
};

enum EfeitoCor { TEXTO = 30, TEXTO_CLARO = 90, FUNDO = 40, FUNDO_CLARO = 100 };


enum Efeito {
  ITALICO = 3,
  UNDERLINE = 4,
  BOLD = 1,
  REVERTER = 7,
  PISCAR_RAPIDO = 6,
  PISCAR_LENTO = 5
};

typedef enum TypesEnum {
    INT,
    FLOAT,
    CHAR,
    STRING,
    
} Type;

typedef union AnyUnion Any;


typedef struct AnyArrayStruct {
    Any* values;
    int tamanho;
} AnyArray;


typedef union AnyUnion {
    int intv;
    float floatv;
    char charv;
    String stringv;
    AnyArray array;
} Any;


typedef struct AnyVarStruct {
    Type type;
    Any value;
} AnyVar;

#define tipoAlvo(any, c) any.#c

#define acessar(any, tipo) _Generic(tipo, int: any.intv, float: any.floatv, String: any.stringv, char: any.charv);
#endif