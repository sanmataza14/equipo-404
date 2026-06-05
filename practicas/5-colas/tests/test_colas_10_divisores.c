#include <assert.h>

#include "colas/util_colas.h"
#include "listas/util_listas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola real, int totalesEsperados, Lista parcialesEsperados) {
    struct Divisores *divisores = buscaDivisores(real);
    assert(divisores->total == totalesEsperados);
    assert(l_longitud(divisores->parciales) == l_longitud(parcialesEsperados));
}

int main() {
    imprimir_titulo("Tests para divisores");
    Cola c1 = crear_cola_desde_array((int[]) {8, 12, 2, 6, 4}, 5);
    Lista parciales1 = crear_lista_desde_array((int[]) {4}, 1);
    
    probar(c1, 2, parciales1);
    destruir_lista(parciales1);
    destruir_cola(c1);

    Cola c2 = crear_cola_desde_array((int[]) {8, 12, 2, 24, 6, 4}, 6);
    Lista parciales2 = crear_lista_desde_array((int[]) {6, 4}, 2);
    
    probar(c2, 2, parciales2);
    destruir_lista(parciales2);
    destruir_cola(c2);
    return 0;
}
