#include "../practica_pilas.h"

#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para intercambiar elementos");
    Pila p1 = p_crear();

    p_apilar(p1, te_crear(1));
    p_apilar(p1, te_crear(6));
    p_apilar(p1, te_crear(3));
    p_apilar(p1, te_crear(7));
    p_apilar(p1, te_crear(4));
    p_apilar(p1, te_crear(8));
    p_apilar(p1, te_crear(3));

    printf("Pila original\n");
    p_mostrar(p1);

    intercambiarElementos(p1, 2, 6);

    printf("Pila modificada\n");
    p_mostrar(p1);
    
    return 0;
}
