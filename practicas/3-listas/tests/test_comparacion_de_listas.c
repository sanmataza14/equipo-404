#include <assert.h>
#include <stdio.h>
#include "../practica_listas.h"
#include "cadenas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

int main() {
    imprimir_titulo("Tests para comparar dos listas");

    
    Lista l1 = l_crear();
    l_agregar(l1, te_crear(2));
    l_agregar(l1, te_crear(5));
    l_agregar(l1, te_crear(7));
    l_agregar(l1, te_crear(3));

    
    Lista l2 = l_crear();
    l_agregar(l2, te_crear(8));
    l_agregar(l2, te_crear(20));
    l_agregar(l2, te_crear(28));
    l_agregar(l2, te_crear(12));

    
    Lista l3 = l_crear();
    l_agregar(l3, te_crear(1));
    l_agregar(l3, te_crear(6));
    l_agregar(l3, te_crear(28));
    l_agregar(l3, te_crear(2));

    
    assert(compararListas(l1, l2) == MENOR);
    
    
    assert(compararListas(l1, l3) == IGUAL);
    
    
    assert(compararListas(l2, l3) == MAYOR);

    printf("¡Los tests de comparacion pasaron con exito!\n");

    return 0;
}
