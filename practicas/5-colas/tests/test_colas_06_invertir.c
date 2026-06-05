#include <stdio.h>
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para invertir cola");
    Cola original = c_crear();
    c_encolar(original, te_crear(10));
    c_encolar(original, te_crear(20));
    c_encolar(original, te_crear(30));

    Cola resultado = invertir(original);

    assert(c_desencolar(resultado)->clave == 30);
    assert(c_desencolar(resultado)->clave == 20);
    assert(c_desencolar(resultado)->clave == 10);
    assert(c_es_vacia(resultado));

    assert(c_desencolar(original)->clave == 10);
    assert(c_desencolar(original)->clave == 20);
    assert(c_desencolar(original)->clave == 30);
    assert(c_es_vacia(original));

    return 0;
}
