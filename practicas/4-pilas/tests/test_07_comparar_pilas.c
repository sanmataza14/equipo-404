#include <assert.h>
#include "../practica_pilas.h"

#include "aserciones.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"

int main() {
    imprimir_titulo("Tests para comparar pilas");
    Pila p1 = p_crear();
    p_apilar(p1, te_crear(1));
    p_apilar(p1, te_crear(6));
    p_apilar(p1, te_crear(3));
    p_apilar(p1, te_crear(7));
    p_apilar(p1, te_crear(4));
    p_apilar(p1, te_crear(8));
    p_apilar(p1, te_crear(3));

    Pila p2 = p_crear();
    p_apilar(p2, te_crear(1));
    p_apilar(p2, te_crear(6));
    p_apilar(p2, te_crear(3));
    p_apilar(p2, te_crear(7));
    p_apilar(p2, te_crear(4));
    p_apilar(p2, te_crear(8));
    p_apilar(p2, te_crear(3));

    Pila p3 = p_crear();
    p_apilar(p3, te_crear(6));
    p_apilar(p3, te_crear(1));
    p_apilar(p3, te_crear(3));
    p_apilar(p3, te_crear(7));
    p_apilar(p3, te_crear(4));
    p_apilar(p3, te_crear(8));
    p_apilar(p3, te_crear(3));

    Pila p4 = p_crear();
    p_apilar(p4, te_crear(5));
    p_apilar(p4, te_crear(6));
    p_apilar(p4, te_crear(3));
    p_apilar(p4, te_crear(7));
    p_apilar(p4, te_crear(4));
    p_apilar(p4, te_crear(8));
    p_apilar(p4, te_crear(3));

    assert(compararPilas(p1, p2) == true);
    assert(compararPilas(p1, p3) == false);
    assert(compararPilas(p1, p4) == false);
    return 0;
}
