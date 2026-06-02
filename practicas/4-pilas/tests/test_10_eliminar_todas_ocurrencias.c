#include "../practica_pilas.h"
#include <assert.h>

#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para eliminar todas las ocurrencias");
    Pila p1 = p_crear();
    p_apilar(p1, te_crear(1));
    p_apilar(p1, te_crear(6));
    p_apilar(p1, te_crear(3));
    p_apilar(p1, te_crear(7));
    p_apilar(p1, te_crear(4));
    p_apilar(p1, te_crear(8));
    p_apilar(p1, te_crear(3));

    Pila resultado = eliminarTodasOcurrencias(p1, 3);

    assert(!p_es_vacia(resultado));
    assert(contarElementos(resultado) == 5);

    Pila espejo_test = p_crear();
    Pila aux_test = p_crear();
    
    while (!p_es_vacia(resultado)) {
        TipoElemento actual = p_desapilar(resultado);
        p_apilar(aux_test, actual);
    }
    while (!p_es_vacia(aux_test)) {
        TipoElemento actual = p_desapilar(aux_test);
        p_apilar(resultado, actual);
        p_apilar(espejo_test, actual);
    }
    
    TipoElemento te;
    te = p_desapilar(espejo_test); assert(te->clave == 8);
    te = p_desapilar(espejo_test); assert(te->clave == 4);
    te = p_desapilar(espejo_test); assert(te->clave == 7);
    te = p_desapilar(espejo_test); assert(te->clave == 6);
    te = p_desapilar(espejo_test); assert(te->clave == 1);
    
    assert(p_es_vacia(espejo_test) == true);

    return 0;
}
