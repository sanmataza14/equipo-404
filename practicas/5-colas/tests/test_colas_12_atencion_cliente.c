#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void test_consigna() {
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();

    c_encolar(c1, te_crear(40));
    c_encolar(c1, te_crear(20));
    c_encolar(c1, te_crear(30));

    c_encolar(c2, te_crear(20));
    c_encolar(c2, te_crear(10));

    c_encolar(c3, te_crear(10));
    c_encolar(c3, te_crear(10));
    c_encolar(c3, te_crear(10));

    Lista resultado = procesar(10, c1, c2, c3);

    int esperados[] = {13, 12, 23, 22, 33, 11, 21, 31};
    int cant_esperados = 8;

    assert(l_longitud(resultado) == cant_esperados);

    for (int i = 0; i < cant_esperados; i++) {
        TipoElemento te = l_recuperar(resultado, i + 1);
        assert(te->clave == esperados[i]);
    }
}

void test_colas_vacias() {
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();

    c_encolar(c2, te_crear(15));
    c_encolar(c2, te_crear(5));

    Lista resultado = procesar(10, c1, c2, c3);

    int esperados[] = {12, 22};
    int cant_esperados = 2;

    assert(l_longitud(resultado) == cant_esperados);

    for (int i = 0; i < cant_esperados; i++) {
        TipoElemento te = l_recuperar(resultado, i + 1);
        assert(te->clave == esperados[i]);
    }
}

void test_mayor_a_tiempos() {
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();

    c_encolar(c1, te_crear(10));
    c_encolar(c1, te_crear(20));
    c_encolar(c2, te_crear(30));
    c_encolar(c3, te_crear(5));
    c_encolar(c3, te_crear(15));

    Lista resultado = procesar(100, c1, c2, c3);

    int esperados[] = {11, 12, 13, 21, 23};
    int cant_esperados = 5;

    assert(l_longitud(resultado) == cant_esperados);

    for (int i = 0; i < cant_esperados; i++) {
        TipoElemento te = l_recuperar(resultado, i + 1);
        assert(te->clave == esperados[i]);
    }
}

int main() {
    imprimir_titulo("Tests para atención al cliente");

    test_consigna();
    test_colas_vacias();
    test_mayor_a_tiempos();

    return 0;
}
