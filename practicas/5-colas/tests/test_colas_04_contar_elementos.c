#include <assert.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para contar elementos (Tamano Cola)");

    Cola c = c_crear();
    
    
    int cantidad_vacia = tamanoCola(c);
    assert(cantidad_vacia == 0);

    
    c_encolar(c, te_crear(1));
    c_encolar(c, te_crear(6));
    c_encolar(c, te_crear(3));
    c_encolar(c, te_crear(7));
    c_encolar(c, te_crear(4));
    c_encolar(c, te_crear(8));
    c_encolar(c, te_crear(3));

    
    int cantidad = tamanoCola(c);
    
    if (cantidad != 7) {
        printf("\n>>> ERROR: La cola tiene 7 elementos pero tu funcion devolvio %d.\n", cantidad);
        return 1;
    }

    
    int esperados[] = {1, 6, 3, 7, 4, 8, 3};
    for (int i = 0; i < 7; i++) {
        if (c_es_vacia(c)) {
            printf("\n>>> ERROR: La cola se vacio durante el conteo.\n");
            return 1;
        }
        
        TipoElemento actual = c_desencolar(c);
        if (actual->clave != esperados[i]) {
            printf("\n>>> ERROR: El orden se rompio. Esperaba %d pero llego %d.\n", esperados[i], actual->clave);
            return 1;
        }
    }

    
    assert(c_es_vacia(c) == true);

    printf("\n¡Los tests de contar elementos en cola pasaron perfecto!\n");

    return 0;
}