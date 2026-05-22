#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../practica_listas.h"
#include "cadenas.h"
#include "aserciones.h"
#include "listas/util_listas.h"
#include "listas/aserciones_listas.h"


bool compararPuntoXY(TipoElemento este, TipoElemento otro) {
    struct PuntoXY *estePunto = (struct PuntoXY *) este->valor;
    struct PuntoXY *otroPunto = (struct PuntoXY *) otro->valor;
    return estePunto->x == otroPunto->x && estePunto->y == otroPunto->y;
}

char *toStringPuntoXY(TipoElemento te) {
    struct PuntoXY *punto = (struct PuntoXY *) te->valor;
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "P(%f, %f)", punto->x, punto->y);
    return str;
}

Lista crear_lista_puntos_desde_array(struct PuntoXY puntos[], int tamano) {
    Lista lista = l_crear();
    for (int i = 0; i < tamano; i++) {
        l_agregar(lista, te_crear_con_valor(0, &puntos[i]));
    }

    return lista;
}

void test_evaluar_polinomio() {
    struct Polinomio p_test;
    p_test.coeficientes = l_crear();

    l_agregar(p_test.coeficientes, te_crear(3)); // Grado 0
    l_agregar(p_test.coeficientes, te_crear(2)); // Grado 1
    l_agregar(p_test.coeficientes, te_crear(5)); // Grado 2

    double resultado = evaluar(p_test, 2.0);

    assert(resultado == 27.0);
}

void test_valores_polinomio() {
    struct Polinomio p_test;
    p_test.coeficientes = l_crear();

    l_agregar(p_test.coeficientes, te_crear(3));
    l_agregar(p_test.coeficientes, te_crear(2));
    l_agregar(p_test.coeficientes, te_crear(5));

    Lista res_lista = valores(p_test, 1, 2, 1.0);
    
    Iterador it = iterador(res_lista);
    
    TipoElemento te1 = siguiente(it);
    assert(te1->clave == 10);
    
    TipoElemento te2 = siguiente(it);
    assert(te2->clave == 27);
}

int main() {
    imprimir_titulo("Tests para polinomio");

    test_evaluar_polinomio();
    test_valores_polinomio();

    return 0;
}
