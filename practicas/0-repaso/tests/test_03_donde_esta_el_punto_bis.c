#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 3");
    struct Punto centro = {0, 0};
    struct Punto p1 = {1, 1};
    struct Punto p2 = {1, 0};
    // Caso 1: debería ser INTERNO
    assert(dondeEstaElPuntoBis(centro, 2, p1) == INTERNO);
    // Caso 2: deberia ser EXTERNO
    assert(dondeEstaElPuntoBis(centro, 1, p1) == EXTERNO);
    // Caso 3: deberia ser EN_CIRCUNFERENCIA
    assert(dondeEstaElPuntoBis(centro, 1, p2) == EN_CIRCUNFERENCIA);
    return 0;
}
