#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep {
    struct Nodo *frente;
    struct Nodo *final;
};

int c_longitud(Cola cola);

Cola c_crear(void) {
    Cola nueva = (Cola) malloc(sizeof(struct ColaRep));
    nueva->frente = NULL;
    nueva->final = NULL;
    return nueva;
}

bool c_encolar(Cola cola, TipoElemento elemento) {
    struct Nodo *nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return false;
    
    nuevo->datos = elemento;
    nuevo->siguiente = NULL;

    if (c_es_vacia(cola)) {
        cola->frente = nuevo;
    } else {
        cola->final->siguiente = nuevo;
    }
    
    cola->final = nuevo;
    
    return true;
}

TipoElemento c_desencolar(Cola cola) {
    if (c_es_vacia(cola)) {
        return NULL;
    }

    struct Nodo *nodo_a_borrar = cola->frente;
    TipoElemento dato_salvado = nodo_a_borrar->datos;
    
    cola->frente = cola->frente->siguiente;
    
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(nodo_a_borrar);
    
    return dato_salvado;
}

bool c_es_vacia(Cola cola) {
    if (cola == NULL) return true;
    return cola->frente == NULL;
}

bool c_es_llena(Cola cola) {
    return false;
}

TipoElemento c_recuperar(Cola cola) {
    if (c_es_vacia(cola)) {
        return NULL;
    }
    
    return cola->frente->datos;
}

void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)) {
        printf("Cola vacia\n");
        return;
    }
    
    struct Nodo *aux = cola->frente;
    printf("Frente -> [ ");
    while (aux != NULL) {
        printf("%d ", aux->datos->clave);
        aux = aux->siguiente;
    }
    printf("] <- Final\n");
}

//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la pila
//-----------------------------------------------------------
int c_longitud(Cola cola) {
    int i = 0;
    struct Nodo *nodo = cola->frente;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

char *c_to_string(Cola cola) {
    const int cantidad = c_longitud(cola);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = cola->frente;
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
