#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "../practica_listas.h"
#include "cadenas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

int main() {
    imprimir_titulo("Tests para determinar si una lista es múltiplo de otra");

    
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
    l_agregar(l3, te_crear(8));
    l_agregar(l3, te_crear(21));
    l_agregar(l3, te_crear(28));
    l_agregar(l3, te_crear(12));

    
    assert(listaEsMultiplo(l1, l2) == true);
    assert(listaEsMultiplo(l1, l3) == false);

    printf("¡Los tests de listaEsMultiplo pasaron con exito!\n");

    return 0;
}
