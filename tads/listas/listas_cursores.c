#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;
static const int NULO = -1;

struct Nodo {
    TipoElemento datos;
    int siguiente;
};

struct ListaRep {
    struct Nodo *cursor;
    int inicio;
    int libre;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del TAD de Lista
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva = (Lista) malloc(sizeof(struct ListaRep));
    
    nueva->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo));
    
    nueva->inicio = NULO; 
    nueva->libre = 0;     
    nueva->cantidad = 0;

    for (int i = 0; i < TAMANIO_MAXIMO - 1; i++) {
        nueva->cursor[i].siguiente = i + 1;
    }
    nueva->cursor[TAMANIO_MAXIMO - 1].siguiente = NULO;

    return nueva;
}

bool l_es_vacia(Lista lista) {
    if (lista == NULL) return true;
    return lista->cantidad == 0;
}

bool l_es_llena(Lista lista) {
    if (lista == NULL) return true;
    return lista->libre == NULO;
}

int l_longitud(Lista lista) {
}

bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) return false;

    int nuevo = lista->libre;
    lista->libre = lista->cursor[nuevo].siguiente;

    lista->cursor[nuevo].datos = elemento;
    lista->cursor[nuevo].siguiente = NULO;

    if (lista->inicio == NULO) {
        lista->inicio = nuevo;
    } else {
        int aux = lista->inicio;
        while (lista->cursor[aux].siguiente != NULO) {
            aux = lista->cursor[aux].siguiente;
        }
        lista->cursor[aux].siguiente = nuevo;
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

    int nuevo = lista->libre;
    lista->libre = lista->cursor[nuevo].siguiente;

    lista->cursor[nuevo].datos = elemento;

    if (pos == 1) {
        lista->cursor[nuevo].siguiente = lista->inicio;
        lista->inicio = nuevo;
    } else {
        int aux = lista->inicio;
        for (int i = 1; i < pos - 1; i++) {
            aux = lista->cursor[aux].siguiente;
        }
        lista->cursor[nuevo].siguiente = lista->cursor[aux].siguiente;
        lista->cursor[aux].siguiente = nuevo;
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
    int temp = lista->inicio;
    int i = 0;
    while (temp != NULO) {
        char num_str[10];
        sprintf(num_str, "%d", lista->cursor[temp].datos->clave);
        strcat(resultado, num_str);
        if (i < (lista->cantidad - 1)) {
            strcat(resultado, ", ");
        }
        temp = lista->cursor[temp].siguiente;
        i++;
    }
    strcat(resultado, "]");

    return resultado;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
// Rutinas del ITERADOR
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

Iterador iterador(Lista lista) {
    Iterador it = (Iterador) malloc(sizeof(struct IteradorRep));
    it->lista = lista;
    if (lista != NULL) {
        it->posicionActual = lista->inicio;
    } else {
        it->posicionActual = NULO;
    }
    return it;
}

bool hay_siguiente(Iterador iterador) {
    if (iterador == NULL) return false;
    return iterador->posicionActual != NULO;
}

TipoElemento siguiente(Iterador iterador) {
    if (iterador == NULL || !hay_siguiente(iterador)) return NULL;

    TipoElemento actual = iterador->lista->cursor[iterador->posicionActual].datos;
    
    iterador->posicionActual = iterador->lista->cursor[iterador->posicionActual].siguiente;

    return actual;
}
