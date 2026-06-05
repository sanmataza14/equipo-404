#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "colas.h"

static const int TAMANIO_MAXIMO = 1000;

struct ColaRep {
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};

Cola c_crear() {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    if (nueva_cola == NULL) return NULL;

    nueva_cola->valores = (TipoElemento *) calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    nueva_cola->frente = 0;
    nueva_cola->final = 0;
    
    return nueva_cola;
}

bool c_es_llena(Cola cola) {
    return cola->final == TAMANIO_MAXIMO;
}

bool c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)) return false;
    
    cola->valores[cola->final] = elemento;
    cola->final++;
    return true;
}

TipoElemento c_desencolar(Cola cola) {
    if (c_es_vacia(cola)) return NULL;
    
    TipoElemento extraido = cola->valores[cola->frente];
    cola->frente++;

    return extraido;
}

bool c_es_vacia(Cola cola) {
    return cola->frente == cola->final;
}

TipoElemento c_recuperar(Cola cola) {
    if (c_es_vacia(cola)) return NULL;
    
    return cola->valores[cola->frente];
}

void c_mostrar(Cola cola) {
    printf("Cola: [");

    for (unsigned int i = cola->frente; i < cola->final; i++) {
        printf("%d", cola->valores[i]->clave);
        
        if (i < (cola->final - 1)) {
            printf(", ");
        }
    }
    printf("]\n");
}

char *c_to_string(Cola cola) {
    char *resultado = (char *) malloc(sizeof(char) * (cola->final * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < cola->final; i++) {
        char num_str[10];
        sprintf(num_str, "%d", cola->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (cola->final - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
