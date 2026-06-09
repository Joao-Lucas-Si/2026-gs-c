#include "../utils/utils.h"
#include <stdlib.h>



// Lingua ingles() {
//     Lingua idioma;
//     idioma.nome = stringf(100, "ingles");
//     String* textos = malloc(17 * sizeof(String));
//     textos[0] =  "Exit";
//     textos[1] = "Insert Data";
//     textos[2] = "View Status";
//     textos[3] = "History";
//     textos[4] = "Test";
//     textos[5] = "Credits";
//     textos[6] = "Control Panel";
//     textos[7] = "Exit";
//     textos[8] = "Insert Batery";
//     textos[9] = "Insert Temperature";
//     textos[10] = "Insert Communication";
//     textos[11] = "SAFE";
//     textos[12] = "ALERT";
//     textos[13] = "CRITICAL";
//     textos[14] = "Test Batery";
//     textos[15] = "Test Temperature";
//     textos[16] = "Test Communication";
//     idioma.textos = textos;
//     return idioma;
// }

Lingua portugues() {
    Lingua idioma;
    idioma.nome = stringf(100, "portugues");
    String* textos = malloc(17 * sizeof(String));
    textos[0] = "Encerrar Sistema";
    textos[1] = "Inserir Dados";
    textos[2] = "Visualizar Status";
    textos[3] = "Historico";
    textos[4] = "Testar";
    textos[5] = "Creditos";
    textos[6] = "Painel de Controle";
    textos[7] = "Sair";
    textos[8] = "Inserir Energia";
    textos[9] = "Inserir Temperatura";
    textos[10] = "Inserir Comunicacao";
    textos[11] = "SEGURO";
    textos[12] = "ATENCAO";
    textos[13] = "CRITICO";
    textos[14] = "Testar Energia";
    textos[15] = "Testar Temperatura";
    textos[16] = "Testar Comunicacao";
    idioma.textos = textos;
    return idioma;
}

void iniciarIdiomas() {
    adicionarLingua(portugues());
    // adicionarLingua(ingles());
    mudarIdioma("portugues");
}