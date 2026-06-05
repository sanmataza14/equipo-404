#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "practica_colas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "colas/colas.h"

void insertarElemento(Cola c, TipoElemento e, int pos) {
    if (c == NULL) return;
    if (pos < 1) pos = 1; 

    Cola aux = c_crear();
    int actual = 1;
    bool insertado = false;

    while (!c_es_vacia(c)) {
        if (actual == pos && !insertado) {
            c_encolar(aux, e);
            insertado = true;
        }
        c_encolar(aux, c_desencolar(c));
        actual++;
    }
    if (!insertado) {
        c_encolar(aux, e);
    }
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
}

void eliminarElemento(Cola c, int clave){
    if(c == NULL) return;
    Cola aux = c_crear();

    while(!c_es_vacia(c)){
        TipoElemento actual = c_desencolar(c);
        if(actual->clave != clave){
            c_encolar(aux, actual);
        }
    }
    while(!c_es_vacia(aux)){
        c_encolar(c, c_desencolar(aux));
    }
}

void eliminarElementoAux(Cola c, int clave) {
    if (c_es_vacia(c)) return;

    TipoElemento actual = c_desencolar(c);
    eliminarElementoAux(c, clave);

    if (actual->clave != clave) {
        c_encolar(c, actual);
    }
}

void invertir_colaAux(Cola c) {
    if (c_es_vacia(c)) return;

    TipoElemento actual = c_desencolar(c);
    invertir_colaAux(c); 
    
    c_encolar(c, actual);
}

void eliminarElementoRec(Cola c, int clave) {
    if (c == NULL) return;
    
    eliminarElementoAux(c, clave);
    invertir_colaAux(c);
}

Cola copia(Cola c) {
    Cola nueva = c_crear();
    
    if (c == NULL || c_es_vacia(c)) {
        return nueva;
    }

    Cola aux = c_crear();

    while (!c_es_vacia(c)) {
        TipoElemento te = c_desencolar(c);
        c_encolar(nueva, te);
        c_encolar(aux, te);   
    }

    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }

    return nueva;
}

// Función auxiliar para ejercicio 8
bool pertenece_a_cola(Cola c, int clave) {
    if (c == NULL || c_es_vacia(c)) return false;
    
    bool encontrado = false;
    Cola aux = c_crear();
    
    // 1. Recorremos buscando la clave
    while (!c_es_vacia(c)) {
        TipoElemento te = c_desencolar(c);
        if (te->clave == clave) {
            encontrado = true; 
        }
        c_encolar(aux, te);
    }
    
    // 2. Restauramos la cola original
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
    
    return encontrado;
}

bool mismosElementos(Cola c1, Cola c2) {
    if (c1 == NULL || c2 == NULL) return false;

    bool todos_c1_en_c2 = true;
    bool todos_c2_en_c1 = true;
    
    Cola aux1 = c_crear();
    Cola aux2 = c_crear();

    while (!c_es_vacia(c1)) {
        TipoElemento te1 = c_desencolar(c1);
        
        if (todos_c1_en_c2 && !pertenece_a_cola(c2, te1->clave)) {
            todos_c1_en_c2 = false;
        }
        c_encolar(aux1, te1);
    }
    while (!c_es_vacia(aux1)) c_encolar(c1, c_desencolar(aux1));

    while (!c_es_vacia(c2)) {
        TipoElemento te2 = c_desencolar(c2);
        
        if (todos_c2_en_c1 && !pertenece_a_cola(c1, te2->clave)) {
            todos_c2_en_c1 = false;
        }
        c_encolar(aux2, te2);
    }
    while (!c_es_vacia(aux2)) c_encolar(c2, c_desencolar(aux2));

    return (todos_c1_en_c2 && todos_c2_en_c1);
}

Lista buscaRepetidos(Pila p, Cola c) {
    Lista l = l_crear();
    if (p == NULL || c == NULL || p_es_vacia(p) || c_es_vacia(c)) {
        return l;
    }

    Pila aux_p = p_crear();
    int pos_pila = 1;

    while (!p_es_vacia(p)) {
        TipoElemento te_pila = p_desapilar(p);
        p_apilar(aux_p, te_pila);

        Cola aux_c = c_crear();
        int pos_cola = 1;
        bool encontrado = false;
        int pos_match_cola = -1;

        while (!c_es_vacia(c)) {
            TipoElemento te_cola = c_desencolar(c);
            
            if (te_cola->clave == te_pila->clave && !encontrado) {
                pos_match_cola = pos_cola;
                encontrado = true;
            }
            
            c_encolar(aux_c, te_cola);
            pos_cola++;
        }

        while (!c_es_vacia(aux_c)) {
            c_encolar(c, c_desencolar(aux_c));
        }

        if (encontrado) {
            struct Repetido *rep = (struct Repetido *) malloc(sizeof(struct Repetido));
            rep->clave = te_pila->clave;
            rep->posicionEnPila = pos_pila;
            rep->posicionEnCola = pos_match_cola;

            TipoElemento nuevo = te_crear(te_pila->clave);
            nuevo->valor = rep; 
            
            l_agregar(l, nuevo);
        }
        
        pos_pila++;
    }

    while (!p_es_vacia(aux_p)) {
        p_apilar(p, p_desapilar(aux_p));
    }

    return l;
}