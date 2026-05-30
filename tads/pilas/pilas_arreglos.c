#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pilas.h"

static const int TAMANIO_MAXIMO = 1000;

struct PilaRep {
    TipoElemento *valores;
    unsigned int tope;
};

Pila p_crear() {
    Pila nueva = (Pila) malloc(sizeof(struct PilaRep));
    
    nueva->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    
    nueva->tope = 0;
    
    return nueva;
}

bool p_apilar(Pila pila, TipoElemento elemento) {
    if (p_es_llena(pila)) {
        return false;
    }
    
    pila->valores[pila->tope] = elemento;
    
    pila->tope++;
    
    return true;
}

TipoElemento p_desapilar(Pila pila) {
    if (p_es_vacia(pila)) {
        return NULL; 
    }
    
    pila->tope--;
    
    return pila->valores[pila->tope];
}

TipoElemento p_tope(Pila pila) {
    if (p_es_vacia(pila)) {
        return NULL;
    }
    
    // Solo miramos el elemento en la cima, sin modificar el tope
    return pila->valores[pila->tope - 1];
}

bool p_es_vacia(Pila pila) {
    if (pila == NULL) return true;
    return pila->tope == 0;
}

bool p_es_llena(Pila pila) {
    if (pila == NULL) return true;
    return pila->tope >= TAMANIO_MAXIMO;
}

void p_mostrar(Pila pila) {
    if (p_es_vacia(pila)) {
        printf("Pila vacia\n");
        return;
    }
    
    printf("Base -> [ ");
    for (int i = 0; i < pila->tope; i++) {
        printf("%d ", pila->valores[i]->clave);
    }
    printf("] <- Tope\n");
}

char *p_to_string(Pila pila) {
    char *resultado = (char *) malloc(sizeof(char) * (pila->tope * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < pila->tope; i++) {
        char num_str[10];
        sprintf(num_str, "%d", pila->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (pila->tope - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
