#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "pilas.h"

static const int TAMANIO_MAXIMO = 1000;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct PilaRep {
    struct Nodo *tope;
};

Pila p_crear() {
    Pila nueva = (Pila) malloc(sizeof(struct PilaRep));
    nueva->tope = NULL; 
    return nueva;
}

bool p_apilar(Pila pila, TipoElemento elemento) {
    struct Nodo *nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return false; // Por si falla la RAM
    
    nuevo->datos = elemento;
    
    nuevo->siguiente = pila->tope;
    
    pila->tope = nuevo;
    
    return true;
}


TipoElemento p_desapilar(Pila pila) {
    if (p_es_vacia(pila)) {
        return NULL;
    }
    
    struct Nodo *nodo_a_borrar = pila->tope;
    
    TipoElemento dato_salvado = nodo_a_borrar->datos;
    
    pila->tope = pila->tope->siguiente;
    
    free(nodo_a_borrar);
    
    return dato_salvado;
}

TipoElemento p_tope(Pila pila) {
    if (p_es_vacia(pila)) {
        return NULL;
    }

    return pila->tope->datos;
}

bool p_es_vacia(Pila pila) {
    if (pila == NULL) return true;
    return pila->tope == NULL;
}

//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la pila
//-----------------------------------------------------------
int p_longitud(Pila pila) {
    int i = 0;
    struct Nodo *nodo = pila->tope;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

bool p_es_llena(Pila pila) {
    return false;
}

void p_mostrar(Pila pila) {
    if (p_es_vacia(pila)) {
        printf("Pila vacia\n");
        return;
    }
    
    printf("Tope -> [ ");
    
    struct Nodo *aux = pila->tope;
    while (aux != NULL) {
        printf("%d ", aux->datos->clave);
        aux = aux->siguiente;
    }
    
    printf("] <- Base\n");
}

char *p_to_string(Pila pila) {
    int cantidad = p_longitud(pila);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = pila->tope;
    int i = 0;
    while (temp != NULL) {
        char num_str[10];
        sprintf(num_str, "%d", temp->datos->clave);
        strcat(resultado, num_str);
        if (i < (cantidad - 1)) {
            strcat(resultado, ", ");
        }
        temp = temp->siguiente;
        i++;
    }
    strcat(resultado, "]");

    return resultado;
}
