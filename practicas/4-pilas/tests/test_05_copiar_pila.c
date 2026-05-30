#include "../practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h" 
#include "pilas/pilas.h"                 

#include "cadenas.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    imprimir_titulo("Tests para copiar pila");

    Pila p = p_crear();
    
    // Apilamos según el ejemplo de la cátedra: (1, 6, 3, 7, 4, 8, 3)
    p_apilar(p, te_crear(1));
    p_apilar(p, te_crear(6));
    p_apilar(p, te_crear(3));
    p_apilar(p, te_crear(7));
    p_apilar(p, te_crear(4));
    p_apilar(p, te_crear(8));
    p_apilar(p, te_crear(3)); // <- Tope original

    // Ejecutamos tu función
    Pila copia = copiar(p);

    // Variables temporales para desarmar la macro del assert de forma segura
    TipoElemento te_orig;
    TipoElemento te_copia;

    // Verificamos desapilando ambas pilas paso a paso.
    // El orden esperado desde el tope hacia abajo es: 3, 8, 4, 7, 3, 6, 1
    
    // Posición 1 (Tope)
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 3);
    assert(te_copia->clave == 3);

    // Posición 2
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 8);
    assert(te_copia->clave == 8);

    // Posición 3
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 4);
    assert(te_copia->clave == 4);

    // Posición 4
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 7);
    assert(te_copia->clave == 7);

    // Posición 5
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 3);
    assert(te_copia->clave == 3);

    // Posición 6
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 6);
    assert(te_copia->clave == 6);

    // Posición 7 (Fondo de la pila)
    te_orig = p_desapilar(p);
    te_copia = p_desapilar(copia);
    assert(te_orig->clave == 1);
    assert(te_copia->clave == 1);

    // Nos aseguramos de que ambas hayan quedado vacías y no sobren datos
    assert(p_es_vacia(p) == true);
    assert(p_es_vacia(copia) == true);

    printf("\n¡Los tests de copiar pila pasaron con exito!\n");

    return 0;
}
