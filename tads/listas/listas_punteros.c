#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ListaRep {
    struct Nodo *inicio;
    int cantidad;
};

struct IteradorRep {
    struct Nodo *posicionActual;
};

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva = (Lista) malloc(sizeof(struct ListaRep));
    nueva->inicio = NULL;
    nueva->cantidad = 0;
    return nueva;
}

bool l_es_vacia(Lista lista) {
    if (lista == NULL) return true;
    return lista->cantidad == 0;
}

bool l_es_llena(Lista lista) {
    return lista->cantidad == TAMANIO_MAXIMO;
}

int l_longitud(Lista lista) {
}

bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) return false;

    struct Nodo *nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevo->datos = elemento;
    nuevo->siguiente = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = nuevo;
    } else {
        struct Nodo *aux = lista->inicio;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    
    lista->cantidad++;
    return true;
}

bool l_borrar(Lista lista, int clave) {
}

TipoElemento l_buscar(Lista lista, int clave) {
}

bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista) || pos < 1 || pos > lista->cantidad + 1) return false;

    struct Nodo *nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nuevo->datos = elemento;

    if (pos == 1) {
        nuevo->siguiente = lista->inicio;
        lista->inicio = nuevo;
    } else {
        struct Nodo *aux = lista->inicio;
        for (int i = 1; i < pos - 1; i++) {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    
    lista->cantidad++;
    return true;
}

bool l_eliminar(Lista lista, int pos) {
}

TipoElemento l_recuperar(Lista lista, int pos) {
}

void l_mostrar(Lista lista) {
}

char *l_to_string(Lista lista) {
    char *resultado = (char *) malloc(sizeof(char) * (lista->cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = lista->inicio;
    int i = 0;
    while (temp != NULL) {
        char num_str[10];
        sprintf(num_str, "%d", temp->datos->clave);
        strcat(resultado, num_str);
        if (i < (lista->cantidad - 1)) {
            strcat(resultado, ", ");
        }
        temp = temp->siguiente;
        i++;
    }
    strcat(resultado, "]");

    return resultado;
}

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
    Iterador it = (Iterador) malloc(sizeof(struct IteradorRep));
    if (lista != NULL) {
        it->posicionActual = lista->inicio;
    } else {
        it->posicionActual = NULL;
    }
    return it;
}

bool hay_siguiente(Iterador iterador) {
    if (iterador == NULL) return false;
    return iterador->posicionActual != NULL;
}

TipoElemento siguiente(Iterador iterador) {
    if (iterador == NULL || iterador->posicionActual == NULL) return NULL;

    TipoElemento actual = iterador->posicionActual->datos;
    iterador->posicionActual = iterador->posicionActual->siguiente;
    
    return actual;
}
