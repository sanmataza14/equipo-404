#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct ColaRep {
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};

// Función interna que hace avanzar el frente y el final hacia adelante
unsigned int paso(unsigned int posicion);

Cola c_crear() {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    if (nueva_cola == NULL) return NULL;

    nueva_cola->valores = (TipoElemento *) calloc((TAMANIO_MAXIMO + 1), sizeof(TipoElemento));
    nueva_cola->frente = 1;
    nueva_cola->final = 1;
    return nueva_cola;
}

bool c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)) {
        return false;
    }
    cola->valores[cola->final] = elemento;
    cola->final = paso(cola->final);
    return true;
}

TipoElemento c_desencolar(Cola cola) {
    if (c_es_vacia(cola)) {
        return NULL;
    }
    TipoElemento elemento_extraido = cola->valores[cola->frente];
    cola->frente = paso(cola->frente);
    return elemento_extraido;
}

bool c_es_vacia(Cola cola) {
    return cola->frente == cola->final;
}

TipoElemento c_recuperar(Cola cola) {
    if (c_es_vacia(cola)) {
        return NULL;
    }
    return cola->valores[cola->frente];
}

bool c_es_llena(Cola cola) {
    return paso(cola->final) == cola->frente;
}

void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    unsigned int i = cola->frente;
    while (i != cola->final) {
        printf("%d", cola->valores[i]->clave);
        
        unsigned int siguiente = paso(i);
        if (siguiente != cola->final) {
            printf(", ");
        }
        i = siguiente;
    }
    printf("]\n");
}


//-----------------
// Rutinas internas
//-----------------
unsigned int paso(unsigned int posicion) {
    return posicion % TAMANIO_MAXIMO + 1;
}

unsigned int c_longitud(Cola cola) {
    unsigned i = 0;
    unsigned pos = cola->frente;
    while (pos != cola->final) {
        i++;
        pos = paso(pos);
    }
    return i;
}

char *c_to_string(Cola cola) {
    char *resultado = (char *) malloc(sizeof(char) * (c_longitud(cola) * 10 + 3));
    if (resultado == NULL) return NULL;
    strcpy(resultado, "[");

    if (!c_es_vacia(cola)) {
        unsigned int i = cola->frente;
        while (i != cola->final) {
            char num_str[10];
            sprintf(num_str, "%d", cola->valores[i]->clave);
            strcat(resultado, num_str);
            
            unsigned int siguiente = paso(i);
            if (siguiente != cola->final) {
                strcat(resultado, ", ");
            }
            i = siguiente;
        }
    }
    strcat(resultado, "]");

    return resultado;
}
