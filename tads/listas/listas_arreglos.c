#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct ListaRep {
    TipoElemento *valores;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva = (Lista) malloc(sizeof(struct ListaRep));
    
    nueva->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    
    nueva->cantidad = 0;
    return nueva;
}

bool l_es_vacia(Lista lista) {
    if (lista == NULL) return true;
    return lista->cantidad == 0;
}

bool l_es_llena(Lista lista) {
    if (lista == NULL) return true;
    return lista->cantidad >= TAMANIO_MAXIMO;
}

int l_longitud(Lista lista) {
    if (lista == NULL) return 0;
    return lista->cantidad;
}

bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) return false;

    lista->valores[lista->cantidad] = elemento;
    lista->cantidad++;
    
    return true;
}

bool l_borrar(Lista lista, int clave) {
    if (lista == NULL) return false;
    

    for (int i = 0; i < lista->cantidad; i++) {
        if (lista->valores[i]->clave == clave) {
            for (int j = i; j < lista->cantidad - 1; j++) {
                lista->valores[j] = lista->valores[j + 1];
            }
            lista->cantidad--;
            return true;
        }
    }
    return false;
}

TipoElemento l_buscar(Lista lista, int clave) {
    if (lista == NULL) return NULL;
    for (int i = 0; i < lista->cantidad; i++) {
        if (lista->valores[i]->clave == clave) {
            return lista->valores[i];
        }
    }
    return NULL;
}

bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista) || pos < 1 || pos > lista->cantidad + 1) return false;

    int indice = pos - 1;

    for (int i = lista->cantidad; i > indice; i--) {
        lista->valores[i] = lista->valores[i - 1];
    }

    lista->valores[indice] = elemento;
    lista->cantidad++;
    
    return true;
}

bool l_eliminar(Lista lista, int pos) {
    if (lista == NULL) return false;
    if (pos < 1 || pos > lista->cantidad) return false; 

    int indice = pos - 1;

    for (int i = indice; i < lista->cantidad - 1; i++) {
        lista->valores[i] = lista->valores[i + 1];
    }
    lista->cantidad--;
    return true;
}

TipoElemento l_recuperar(Lista lista, int pos) {
    if (lista == NULL) return NULL;
    if (pos < 1 || pos > lista->cantidad) return NULL;

    return lista->valores[pos - 1];
}

void l_mostrar(Lista lista) {
}

char *l_to_string(Lista lista) {
    char *resultado = (char *) malloc(sizeof(char) * (lista->cantidad * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < lista->cantidad; i++) {
        char num_str[10];
        sprintf(num_str, "%d", lista->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (lista->cantidad - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
    Iterador it = (Iterador) malloc(sizeof(struct IteradorRep));
    it->lista = lista;
    it->posicionActual = 0;
    return it;
}

bool hay_siguiente(Iterador iterador) {
    if (iterador == NULL || iterador->lista == NULL) return false;
    return iterador->posicionActual < iterador->lista->cantidad;
}

TipoElemento siguiente(Iterador iterador) {
    if (iterador == NULL || !hay_siguiente(iterador)) return NULL;
    
    TipoElemento actual = iterador->lista->valores[iterador->posicionActual];
    
    iterador->posicionActual++;
    
    return actual;
}
