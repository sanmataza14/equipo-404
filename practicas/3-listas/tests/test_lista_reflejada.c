#include "../practica_listas.h"

#include "cadenas.h"
#include <stdio.h>

void mostrarLista(Lista l) {
    Iterador it = iterador(l);
    printf("[ ");
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        printf("%d ", te->clave);
    }
    printf("]\n");
}

int main() {
    imprimir_titulo("Tests para reflejar o espejar una lista");

    Lista original = l_crear();
    l_agregar(original, te_crear(6));
    l_agregar(original, te_crear(7));
    l_agregar(original, te_crear(8));

    printf("Lista Original: ");
    mostrarLista(original);

    Lista espejo_simple = reflejarLista(original, false);
    printf("Reflejo Simple (false): ");
    mostrarLista(espejo_simple); 
    // Esperado: [ 6 7 8 7 6 ]

    Lista espejo_doble = reflejarLista(original, true);
    printf("Reflejo Doble (true):   ");
    mostrarLista(espejo_doble);  
    // Esperado: [ 6 7 8 8 7 6 ]

    return 0;
}
