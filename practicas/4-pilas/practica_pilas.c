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
    if (p == NULL || p_es_vacia(p)) {
        return 0;
    }

    Pila aux = p_crear();
    int contador = 0;

    while (!p_es_vacia(p)) {
        p_apilar(aux, p_desapilar(p));
        contador++;
    }

    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }

    return contador;
}

bool compararPilas(Pila p1, Pila p2) {
}

char *cambioDeBase(int numero, int base) {
}

Pila invertirPila(Pila p) {
    Pila nueva = p_crear();
    if (p == NULL || p_es_vacia(p)) {
        return nueva;
    }

    Pila aux = p_crear();

    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        p_apilar(nueva, te);
        p_apilar(aux, te);
    }

    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }

    return nueva;
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {
}

Pila elementosEnComun(Pila p1, Pila p2) {
}

Pila eliminarRepetidos(Pila p) {
    Pila resultado = p_crear();
    if (p == NULL || p_es_vacia(p)) {
        return resultado;
    }

    Pila aux_p = p_crear();

    while (!p_es_vacia(p)) {
        TipoElemento actual = p_desapilar(p);
        p_apilar(aux_p, actual);

        Pila aux_res = p_crear();
        bool encontrado = false;

        while (!p_es_vacia(resultado)) {
            TipoElemento te_res = p_desapilar(resultado);
            if (te_res->clave == actual->clave) {
                int cantidad_actual = (int)(long)te_res->valor;
                te_res->valor = (void*)(long)(cantidad_actual + 1);
                encontrado = true;
            }
            p_apilar(aux_res, te_res);
        }

        while (!p_es_vacia(aux_res)) {
            p_apilar(resultado, p_desapilar(aux_res));
        }

        if (!encontrado) {
            TipoElemento nuevo = te_crear(actual->clave);
            nuevo->valor = (void*)(long)1; 
            p_apilar(resultado, nuevo);
        }
    }

    while (!p_es_vacia(aux_p)) {
        p_apilar(p, p_desapilar(aux_p));
    }

    return resultado;
}
