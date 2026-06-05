#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "practica_colas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "colas/colas.h"

bool buscarElemento(Cola c, TipoElemento e) {
    if (c == NULL || c_es_vacia(c)) return false;
    
    bool encontrado = false;
    Cola aux = c_crear();
    
    
    while (!c_es_vacia(c)) {
        TipoElemento actual = c_desencolar(c);
        if (actual->clave == e->clave) {
            encontrado = true;
        }
        c_encolar(aux, actual);
    }
    
    
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
    
    return encontrado;
}

void buscarElementoRec_aux(Cola c, Cola aux, int clave, bool *encontrado) {
    
    if (c_es_vacia(c)) return;
    
    TipoElemento actual = c_desencolar(c);
    if (actual->clave == clave) {
        *encontrado = true;
    }
    
    c_encolar(aux, actual);
    
    
    buscarElementoRec_aux(c, aux, clave, encontrado);
}

void restaurarColaRec(Cola c, Cola aux) {
    
    if (c_es_vacia(aux)) return;
    
    c_encolar(c, c_desencolar(aux));
    restaurarColaRec(c, aux);
}

bool buscarElementoRecursivo(Cola c, TipoElemento e) {
    if (c == NULL || c_es_vacia(c)) return false;
    
    bool encontrado = false;
    Cola aux = c_crear();
    
    
    buscarElementoRec_aux(c, aux, e->clave, &encontrado);
    
    
    restaurarColaRec(c, aux);
    
    return encontrado;
}

int tamanoCola(Cola c) {
    if (c == NULL || c_es_vacia(c)) {
        return 0;
    }

    int contador = 0;
    Cola aux = c_crear();

    
    while (!c_es_vacia(c)) {
        c_encolar(aux, c_desencolar(c));
        contador++;
    }

    
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }

    return contador;
}

void tamanoColaRec_aux(Cola c, Cola aux, int *contador) {
    
    if (c_es_vacia(c)) {
        return;
    }

    c_encolar(aux, c_desencolar(c));
    (*contador)++;
    
    
    tamanoColaRec_aux(c, aux, contador);
}


void restaurarCola_tamanoRec(Cola c, Cola aux) {
    if (c_es_vacia(aux)) {
        return;
    }
    c_encolar(c, c_desencolar(aux));
    restaurarCola_tamanoRec(c, aux);
}

int tamanoColaRecursivo(Cola c) {
    if (c == NULL || c_es_vacia(c)) {
        return 0;
    }

    int contador = 0;
    Cola aux = c_crear();

    
    tamanoColaRec_aux(c, aux, &contador);
    
   
    restaurarCola_tamanoRec(c, aux);

    return contador;
}

bool comparar(Cola c1, Cola c2) {
    if (c1 == NULL || c2 == NULL) return false;

    int len1 = 0;
    int len2 = 0;
    
    
    Cola aux = c_crear();

    
    while (!c_es_vacia(c1)) {
        c_encolar(aux, c_desencolar(c1));
        len1++;
    }
    while (!c_es_vacia(aux)) c_encolar(c1, c_desencolar(aux));

    
    while (!c_es_vacia(c2)) {
        c_encolar(aux, c_desencolar(c2));
        len2++;
    }
    while (!c_es_vacia(aux)) c_encolar(c2, c_desencolar(aux));

    
    if (len1 != len2) return false;

    bool iguales = true;

   
    for (int i = 0; i < len1; i++) {
        TipoElemento te1 = c_desencolar(c1);
        TipoElemento te2 = c_desencolar(c2);

        
        if (te1->clave != te2->clave) {
            iguales = false;
        }

        
        c_encolar(c1, te1);
        c_encolar(c2, te2);
    }

    return iguales;
}

void compararRec_aux(Cola c1, Cola c2, int rotaciones_restantes, bool *iguales) {
    
    if (rotaciones_restantes == 0) return;
    
    TipoElemento te1 = c_desencolar(c1);
    TipoElemento te2 = c_desencolar(c2);
    
    if (te1->clave != te2->clave) {
        *iguales = false;
    }
    
    
    c_encolar(c1, te1);
    c_encolar(c2, te2);
    
    
    compararRec_aux(c1, c2, rotaciones_restantes - 1, iguales);
}

bool compararRecursivo(Cola c1, Cola c2) {
    if (c1 == NULL || c2 == NULL) return false;
    
    
    int len1 = tamanoCola(c1);
    int len2 = tamanoCola(c2);
    
    if (len1 != len2) return false;
    
    bool iguales = true;
    compararRec_aux(c1, c2, len1, &iguales);
    
    return iguales;
}

Cola unicos(Cola c) {
    Cola resultado = c_crear();
    if (c == NULL || c_es_vacia(c)) return resultado;

    
    int len = tamanoCola(c);

    for (int i = 0; i < len; i++) {
        TipoElemento actual = c_desencolar(c);
        int ocurrencias = 1; 
        
        
        for (int j = 0; j < len - 1; j++) {
            TipoElemento temp = c_desencolar(c);
            if (temp->clave == actual->clave) {
                ocurrencias++;
            }
            c_encolar(c, temp); 
        }

        
        if (ocurrencias == 1) {
            c_encolar(resultado, te_crear(actual->clave));
        }

       
        c_encolar(c, actual);
    }

    return resultado;
}

void contarRepetidosRec_aux(Cola c, int clave, int rotaciones_restantes, int *ocurrencias) {
    if (rotaciones_restantes == 0) return;
    
    TipoElemento temp = c_desencolar(c);
    if (temp->clave == clave) {
        (*ocurrencias)++;
    }
    c_encolar(c, temp); 
    
    contarRepetidosRec_aux(c, clave, rotaciones_restantes - 1, ocurrencias);
}

void unicosRec_aux(Cola c, Cola resultado, int rotaciones_restantes, int len) {
    if (rotaciones_restantes == 0) return;

    TipoElemento actual = c_desencolar(c);
    int ocurrencias = 1;

    
    contarRepetidosRec_aux(c, actual->clave, len - 1, &ocurrencias);

    if (ocurrencias == 1) {
        c_encolar(resultado, te_crear(actual->clave));
    }

    c_encolar(c, actual);

    
    unicosRec_aux(c, resultado, rotaciones_restantes - 1, len);
}

Cola unicosRecursivo(Cola c) {
    Cola resultado = c_crear();
    if (c == NULL || c_es_vacia(c)) return resultado;

    int len = tamanoCola(c);
    unicosRec_aux(c, resultado, len, len);

    return resultado;
}

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
    if(c == NULL || c_es_vacia(c)) return;
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

Cola invertir(Cola c){
    if (c == NULL || c_es_vacia(c)) return NULL;
    Cola nueva_cola = c_crear();
    Cola cola_aux= c_crear();
    Pila pila_aux = p_crear();

    while(!c_es_vacia(c)) {
        TipoElemento actual = c_desencolar(c);
        c_encolar(cola_aux, actual);
        p_apilar(pila_aux, actual);
    }
    while (!c_es_vacia(cola_aux)) {
    c_encolar(c, c_desencolar(cola_aux));
    }
    while (!p_es_vacia(pila_aux)) {
    c_encolar(nueva_cola, p_desapilar(pila_aux));
    }
    return nueva_cola;
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