#include <assert.h>
#include <stdio.h>
#include "../practica_listas.h"
#include "cadenas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

int main() {
    imprimir_titulo("Tests para retornar una lista con números múltiplos de un escalar");

    
    Lista original = l_crear();
    l_agregar(original, te_crear(7));
    l_agregar(original, te_crear(6));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(1));

    
    Lista resultado = multiplos(original, 3);

    
    Iterador iter = iterador(resultado);
    
    assert(hay_siguiente(iter));
    assert(siguiente(iter)->clave == 21);
    
    assert(hay_siguiente(iter));
    assert(siguiente(iter)->clave == 18);
    
    assert(hay_siguiente(iter));
    assert(siguiente(iter)->clave == 24);
    
    assert(hay_siguiente(iter));
    assert(siguiente(iter)->clave == 3);

    printf("¡El test del multiplo escalar (x3) paso perfecto!\n");

    return 0;
}