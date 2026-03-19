#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 1");

    // Test 1: Punto adentro
    int_eq(dondeEstaElPunto(0, 0, 2, 1, 1), INTERNO);
    // Test 2: Punto esta fuera
    int_eq(dondeEstaElPunto(0, 0, 1, 1, 1), EXTERNO);
    // Test 3: Punto en la circunferencia
    int_eq(dondeEstaElPunto(0, 0, 1, 1, 0), EN_CIRCUNFERENCIA);

    return 0;
}
