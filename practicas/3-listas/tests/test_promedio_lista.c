#include "../practica_listas.h"

#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para calcular el promedio de los datos de una lista");
    Lista mi_lista = l_crear();
    l_agregar(mi_lista, te_crear(6));
    l_agregar(mi_lista, te_crear(9));
    l_agregar(mi_lista, te_crear(2));
    l_agregar(mi_lista, te_crear(6));
    l_agregar(mi_lista, te_crear(7));
    l_agregar(mi_lista, te_crear(1));
    l_agregar(mi_lista, te_crear(4));
    l_agregar(mi_lista, te_crear(8));
    return 0;
}
