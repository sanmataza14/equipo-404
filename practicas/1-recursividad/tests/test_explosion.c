#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests del Ejercicio de Explosión saraza");
    int size;
    int* resultado1 = explosion(10, 3, &size);

    assert(size == 5);

    assert(resultado1 != NULL);

    assert(resultado1[0] == 3);
    assert(resultado1[1] == 2);
    assert(resultado1[2] == 1);
    assert(resultado1[3] == 1);
    assert(resultado1[4] == 3);

    free(resultado1);

    int size2;
    int *resultado2 = explosion(20, 5, &size2);

    assert(size2 == 9);

    assert(resultado2[0] == 4);
    assert(resultado2[1] == 3);
    assert(resultado2[2] == 2);
    assert(resultado2[3] == 2);
    assert(resultado2[4] == 1);
    assert(resultado2[5] == 1);
    assert(resultado2[6] == 1);
    assert(resultado2[7] == 1);
    assert(resultado2[8] == 5);

    free(resultado2);
    return 0;
}
