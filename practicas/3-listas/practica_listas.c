#include <stdlib.h>
#include <math.h>

#include "practica_listas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"


struct ElementoYPosicion menorYPosicionRec(Iterador iter, struct ElementoYPosicion min_actual, int pos_actual) {
    if (!hay_siguiente(iter)) {
        return min_actual;
    }
    TipoElemento te = siguiente(iter);
    if (te->clave < min_actual.valor) {
        min_actual.valor = te->clave;
        min_actual.ordinal = pos_actual;
    }
    return menorYPosicionRec(iter, min_actual, pos_actual + 1);
}

Lista invertirListaRec(Iterador iter) {
    if (!hay_siguiente(iter)) {
        return l_crear();
    }
    TipoElemento te = siguiente(iter);
    Lista lista_invertida = invertirListaRec(iter);
    l_agregar(lista_invertida, te);
    return lista_invertida;
}


Lista multiplos(Lista l, int n) {
    Lista resultado = l_crear();
    if (l_es_vacia(l) || n == 0) return resultado;
    
    Iterador iter = iterador(l);
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        TipoElemento nuevo_te = te_crear(te->clave * n);
        l_agregar(resultado, nuevo_te);
    }
    
    return resultado;
}

double promedio(Lista l) {
    if (l_es_vacia(l)) {
        return 0.0;
    }
    double suma = 0;
    int contador = 0;
    Iterador iter = iterador(l);
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        suma += te->clave; 
        contador++;
    }
    return suma / contador;
}

struct ElementoYPosicion menorYPosicion(Lista l) {
    struct ElementoYPosicion resultado = {0, 0};
    if (l_es_vacia(l)) return resultado;
    
    Iterador iter = iterador(l);
    TipoElemento te = siguiente(iter);
    resultado.valor = te->clave;
    resultado.ordinal = 1;
    return menorYPosicionRec(iter, resultado, 2);
}

Lista invertirLista(Lista l) {
    Lista nueva = l_crear();
    Iterador iter = iterador(l);
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        l_insertar(nueva, te, 1);
    }
    return nueva;
}

enum Comparacion compararListas(Lista l1, Lista l2) {
    int puntos_l1 = 0;
    int puntos_l2 = 0;
    Iterador i1 = iterador(l1);
    Iterador i2 = iterador(l2);
    while (hay_siguiente(i1) && hay_siguiente(i2)) {
        TipoElemento te1 = siguiente(i1);
        TipoElemento te2 = siguiente(i2);
        if (te1->clave > te2->clave) {
            puntos_l1++;
        } else if (te1->clave < te2->clave) {
            puntos_l2++;
        }
    }
    if (puntos_l1 > puntos_l2) {
        return MAYOR;
    } else if (puntos_l1 < puntos_l2) {
        return MENOR;
    } else {
        return IGUAL;
    }
}

double evaluar(struct Polinomio p, double x) {
    return 0.0;
}

Lista valores(struct Polinomio p, int desde, int hasta, double paso) {
    return l_crear();
}