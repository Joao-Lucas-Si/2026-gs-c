#include "src/ascii.h"
#include "src/ascii.c"
#include "src/data.c"
#include "src/data.h"
#include "src/fun.c"
#include "src/idioma.h"
#include "src/idiomas.c"
#include "src/telas/historico.c"
#include "src/introducao.c"
#include "src/telas.c"
#include "utils/array.c"
#include "utils/ascii/fonte.c"
#include "utils/data.c"
#include "utils/i18n.c"
#include "utils/input.c"
#include "utils/numerico.c"
#include "utils/print.c"
#include "utils/sistema.c"
#include "utils/sistema.h"
#include "utils/string.c"
#include "utils/tui/animacao.c"
#include "utils/tui/cor.c"
#include "utils/tui/layout.c"
#include "utils/tui/menus.c"
#include "utils/tui/texto/multilinha.c"
#include "utils/tui/texto/tabela.c"
#include "utils/tui/ui.c"
#include "utils/utils.h"

#define DEV 1

int main() {
  limpar();
  configurarCores(ROXO, AZUL);
  iniciarFontes();
  iniciarIdiomas();
  iniciar();
  
  if (!DEV) {
    logos();
  }
  principal();

  return 0;
}