#include "practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "pilas/pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool buscarElemento(Pila p, TipoElemento e) {
}

void insertarElemento(Pila p, TipoElemento e, int pos) {
}

void eliminarElemento(Pila p, int clave) {
    if (p == NULL || p_es_vacia(p)) {
        return;
    }

    Pila aux = p_crear();
    bool encontrado = false;

    while (!p_es_vacia(p) && !encontrado) {
        TipoElemento te = p_desapilar(p);
        
        if (te->clave == clave) {
            encontrado = true; 
        } else {
            p_apilar(aux, te); 
        }
    }

    while (!p_es_vacia(aux)) {
        TipoElemento te_aux = p_desapilar(aux);
        p_apilar(p, te_aux);
    }
}

void intercambiarElementos(Pila p, int pos1, int pos2) {
}

Pila copiar(Pila p) {
}

int contarElementos(Pila p) {
}

bool compararPilas(Pila p1, Pila p2) {
}

char *cambioDeBase(int numero, int base) {
}

Pila invertirPila(Pila p) {
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {
}

Pila elementosEnComun(Pila p1, Pila p2) {
}

Pila eliminarRepetidos(Pila p) {
}
