#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para la mafia china");

    assert(strcmp(chinos(4), "(-.(-.(-.(-.-).-).-).-)") == 0);
    return 0;
}
