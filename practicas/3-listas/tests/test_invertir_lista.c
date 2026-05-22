#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../practica_listas.h"

#include "listas/listas.h"
#include "listas/util_listas.h"
#include "listas/aserciones_listas.h"
#include "cadenas.h"

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
    imprimir_titulo("Tests para invertir listas");

    imprimir_titulo("Tests para invertir listas");

    Lista original = l_crear();
    l_agregar(original, te_crear(6));
    l_agregar(original, te_crear(7));
    l_agregar(original, te_crear(8));

    printf("Lista Original: ");
    mostrarLista(original);

    Lista invertida_iter = invertirLista(original);
    printf("Invertida (Iterativa): ");
    mostrarLista(invertida_iter);

    Iterador it_original = iterador(original);
    Lista invertida_rec = invertirListaRec(it_original);
    printf("Invertida (Recursiva): ");
    mostrarLista(invertida_rec);
    
    return 0;
}
