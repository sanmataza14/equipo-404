#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 1");
    //test 1: punto dentro de circunferencia
    assert(dondeEstaElPunto(0, 0, 2, 1, 1 ) == INTERNO);
    //test 2; punto fuera circurferencia
    assert(dondeEstaElPunto(0, 0, 1, 1, 1 ) == EXTERNO);
    //test 3: punto sobre circunferencia
    assert(dondeEstaElPunto(0, 0, 1, 1, 0 ) == EN_CIRCUNFERENCIA);
}
