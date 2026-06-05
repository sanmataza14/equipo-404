#include <stdio.h>
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para eliminar elemento");
    Cola c = c_crear();
    
    c_encolar(c, te_crear(1));
    c_encolar(c, te_crear(6));
    c_encolar(c, te_crear(3));
    c_encolar(c, te_crear(7));
    c_encolar(c, te_crear(4));
    c_encolar(c, te_crear(8));
    c_encolar(c, te_crear(3));

    eliminarElemento(c, 3);

    assert(c_desencolar(c)->clave == 1);
    assert(c_desencolar(c)->clave == 6);
    assert(c_desencolar(c)->clave == 7);
    assert(c_desencolar(c)->clave == 4);
    assert(c_desencolar(c)->clave == 8);
    
    assert(c_es_vacia(c));

    printf("¡Todos los asserts pasaron con éxito!\n");
    return 0;
}
