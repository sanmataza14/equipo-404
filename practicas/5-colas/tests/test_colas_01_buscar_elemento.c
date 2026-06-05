#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para buscar elemento");

    Cola c = c_crear();
    
    
    c_encolar(c, te_crear(1));
    c_encolar(c, te_crear(6));
    c_encolar(c, te_crear(3));
    c_encolar(c, te_crear(7));
    c_encolar(c, te_crear(4));
    c_encolar(c, te_crear(8));
    c_encolar(c, te_crear(3));

    
    TipoElemento e1 = te_crear(1);
    bool res1 = buscarElemento(c, e1);
    
    TipoElemento e2 = te_crear(13);
    bool res2 = buscarElemento(c, e2);

    
    assert(res1 == true);
    assert(res2 == false);

    
    int esperados[] = {1, 6, 3, 7, 4, 8, 3};
    
    for (int i = 0; i < 7; i++) {
        
        assert(c_es_vacia(c) == false); 
        
        TipoElemento actual = c_desencolar(c);
        
        
        assert(actual->clave == esperados[i]);
    }

    
    assert(c_es_vacia(c) == true);

    printf("\n¡Todos los tests de buscar elemento en cola pasaron perfecto!\n");

    return 0;
}
