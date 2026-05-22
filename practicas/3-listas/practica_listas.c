#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "practica_listas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

// --- FUNCIONES AUXILIARES ---

void promedioRecAux(Iterador iter, double *suma, int *contador) {
    if (!hay_siguiente(iter)) {
        return;
    }
    *suma += siguiente(iter)->clave;
    *contador += 1;
    promedioRecAux(iter, suma, contador);
}

int compararRec(Iterador i1, Iterador i2) {
    if (!hay_siguiente(i1) || !hay_siguiente(i2)) {
        return 0;
    }
    TipoElemento te1 = siguiente(i1);
    TipoElemento te2 = siguiente(i2);
    int resto = compararRec(i1, i2);
    
    if (te1->clave > te2->clave) return resto + 1;
    else if (te1->clave < te2->clave) return resto - 1;
    else return resto;
}

Lista invertirListaRec(Iterador iter) {
    if (iter == NULL || !hay_siguiente(iter)) return l_crear();
    TipoElemento te = siguiente(iter);
    Lista nueva = invertirListaRec(iter);
    l_agregar(nueva, te);
    return nueva;
}

bool listaEsMultiploRec(Iterador i1, Iterador i2, int escalar) {
    if (!hay_siguiente(i1) && !hay_siguiente(i2)) return true;
    if (!hay_siguiente(i1) || !hay_siguiente(i2)) return false;

    TipoElemento te1 = siguiente(i1);
    TipoElemento te2 = siguiente(i2);

    if (te1->clave == 0 || te2->clave % te1->clave != 0 || (te2->clave / te1->clave) != escalar) {
        return false;
    }
    return listaEsMultiploRec(i1, i2, escalar);
}

// --- FUNCIONES PRINCIPALES ---
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
    if (l_es_vacia(l)) return 0.0;
    double suma = 0;
    int contador = 0;
    Iterador iter = iterador(l);
    promedioRecAux(iter, &suma, &contador);
    return suma / contador;
}

struct ElementoYPosicion menorYPosicion(Lista l) {
    struct ElementoYPosicion resultado = {0, 0};
    if (l_es_vacia(l)) return resultado;

    Iterador iter = iterador(l);
    TipoElemento te = siguiente(iter);
    resultado.valor = te->clave; 
    resultado.ordinal = 1;
    int posicion_actual = 2; 
    
    while (hay_siguiente(iter)) {
        te = siguiente(iter);
        if (te->clave < resultado.valor) {
            resultado.valor = te->clave;
            resultado.ordinal = posicion_actual;
        }
        posicion_actual++;
    }
    return resultado;
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

// ESTA ES LA ÚNICA COMPARARLISTAS QUE QUEDA (LA RECURSIVA)
enum Comparacion compararListas(Lista l1, Lista l2) {
    Iterador i1 = iterador(l1);
    Iterador i2 = iterador(l2);
    int diferencia = compararRec(i1, i2);

    if (diferencia > 0) return MAYOR;
    else if (diferencia < 0) return MENOR;
    else return IGUAL;
}

struct ElementoYOcurrencias mayorYOcurrencias(Lista l) {
    struct ElementoYOcurrencias maximo = {0, 0};
    if (l == NULL || l_es_vacia(l)) return maximo;

    Iterador it = iterador(l);
    if (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        maximo.valor = te->clave;
        maximo.ocurrencias = 1;
    }

    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        if (te->clave > maximo.valor) {
            maximo.valor = te->clave;
            maximo.ocurrencias = 1;
        } else if (te->clave == maximo.valor) {
            maximo.ocurrencias++;
        }
    }
    return maximo;
}

Lista reflejarLista(Lista l, bool ultimoDoble) {
    Lista nueva = l_crear();
    if (l == NULL || l_es_vacia(l)) return nueva;

    Iterador it_orig = iterador(l);
    while (hay_siguiente(it_orig)) {
        l_agregar(nueva, siguiente(it_orig));
    }

    Lista invertida = invertirLista(l);
    Iterador it_inv = iterador(invertida);

    if (!ultimoDoble && hay_siguiente(it_inv)) {
        siguiente(it_inv); 
    }

    while (hay_siguiente(it_inv)) {
        l_agregar(nueva, siguiente(it_inv));
    }
    return nueva;
}

bool listaEsMultiplo(Lista l1, Lista l2) {
    if (l_es_vacia(l1) || l_es_vacia(l2)) return false;
    Iterador i1 = iterador(l1);
    Iterador i2 = iterador(l2);
    TipoElemento te1 = siguiente(i1);
    TipoElemento te2 = siguiente(i2);

    if (te1->clave == 0 || te2->clave % te1->clave != 0) return false;
    int escalar = te2->clave / te1->clave;
    return listaEsMultiploRec(i1, i2, escalar);
}

double evaluar(struct Polinomio p, double x) {
    if (l_es_vacia(p.coeficientes)) return 0.0;

    Iterador i1 = iterador(p.coeficientes);
    double resultado = 0.0;
    int grado = 0;

    while(hay_siguiente(i1)){
    TipoElemento te = siguiente(i1);
    resultado += te->clave * pow(x, grado);
    grado ++;
    }
    return resultado; 
    }

Lista valores(struct Polinomio p, int desde, int hasta, double paso) {
    Lista nueva = l_crear();
    int x = desde;
    while (x <= hasta){
        double res = evaluar(p, x);
        TipoElemento nuevo_te = te_crear((int)res);
        l_agregar(nueva, nuevo_te);
        x += paso;
    }
    return nueva; 
}