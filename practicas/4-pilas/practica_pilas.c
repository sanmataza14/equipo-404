#include "practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "pilas/pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool buscarElemento(Pila p, TipoElemento e) {
    bool encontrado = false;
    Pila aux = p_crear();
    
    // Revisamos la pila sin destruirla
    while (!p_es_vacia(p)) {
        TipoElemento actual = p_desapilar(p);
        if (actual->clave == e->clave) {
            encontrado = true;
        }
        p_apilar(aux, actual);
    }
    
    // Restauramos la pila original
    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
    
    return encontrado;
}

Pila elementosEnComun(Pila p1, Pila p2) {
    Pila comunes = p_crear();
    Pila aux1 = p_crear();

    // Invertimos p1 en aux1 para poder procesarla desde el fondo hacia el tope
    while (!p_es_vacia(p1)) {
        p_apilar(aux1, p_desapilar(p1));
    }

    // Volvemos a armar p1 mientras revisamos si hay coincidencias en p2
    while (!p_es_vacia(aux1)) {
        TipoElemento actual = p_desapilar(aux1);
        
        // Usamos nuestra función buscar para ver si está en p2
        if (buscarElemento(p2, actual)) {
            // Evitamos meter repetidos en la pila de comunes
            if (!buscarElemento(comunes, actual)) {
                p_apilar(comunes, te_crear(actual->clave));
            }
        }
        
        // Restauramos p1 a su estado original
        p_apilar(p1, actual);
    }

    return comunes;
}

void elementosEnComunRec_aux(Pila p1, Pila p2, Pila comunes) {
    // Caso base: llegamos al fondo de p1
    if (p_es_vacia(p1)) return;
    
    TipoElemento tope = p_desapilar(p1);
    
    // Bajamos hasta el fondo
    elementosEnComunRec_aux(p1, p2, comunes);
    
    // Al volver subiendo, verificamos y apilamos
    if (buscarElemento(p2, tope)) {
        if (!buscarElemento(comunes, tope)) {
            p_apilar(comunes, te_crear(tope->clave));
        }
    }
    
    // Restauramos p1
    p_apilar(p1, tope);
}

Pila elementosEnComunRecursivo(Pila p1, Pila p2) {
    Pila comunes = p_crear();
    elementosEnComunRec_aux(p1, p2, comunes);
    return comunes;
}

void insertarElemento(Pila p, TipoElemento e, int pos) {
    if (pos < 1) return; 

    Pila auxiliar = p_crear();
    int actual = 1;

    
    while (actual < pos && !p_es_vacia(p)) {
        p_apilar(auxiliar, p_desapilar(p));
        actual++;
    }

    
    p_apilar(p, e);

   
    while (!p_es_vacia(auxiliar)) {
        p_apilar(p, p_desapilar(auxiliar));
    }
}



void insertarElementoRec_aux(Pila p, TipoElemento e, int pos) {
    
    if (pos == 1 || p_es_vacia(p)) {
        p_apilar(p, e);
        return;
    }
    
    
    TipoElemento tope = p_desapilar(p);
    
    
    insertarElementoRec_aux(p, e, pos - 1);
    
    
    p_apilar(p, tope);
}


void insertarElementoRecursivo(Pila p, TipoElemento e, int pos) {
    if (pos < 1) return; 
    insertarElementoRec_aux(p, e, pos);
}

void eliminarElemento(Pila p, int clave) {
    if (p == NULL || p_es_vacia(p)) {
        return;
    }

    Pila aux = p_crear();
    bool encontrado = false;

    while (!p_es_vacia(p) && !encontrado) {
        TipoElemento te = p_desapilar(p);
        
        if (te->clave == clave) {
            encontrado = true; 
        } else {
            p_apilar(aux, te); 
        }
    }

    while (!p_es_vacia(aux)) {
        TipoElemento te_aux = p_desapilar(aux);
        p_apilar(p, te_aux);
    }
}

void intercambiarElementos(Pila p, int pos1, int pos2) {
    return;
}

Pila copiar(Pila p) {
    Pila aux = p_crear();
    Pila copia = p_crear();
    
    while (!p_es_vacia(p)) {
        p_apilar(aux, p_desapilar(p));
    }
    
    while (!p_es_vacia(aux)) {
        TipoElemento te = p_desapilar(aux);
        p_apilar(p, te);
        p_apilar(copia, te_crear(te->clave));
    }
    
    return copia;
}

void copiarRec_aux(Pila original, Pila copia) {
    
    if (p_es_vacia(original)) {
        return; 
    }
    
    
    TipoElemento tope = p_desapilar(original);
    
    
    copiarRec_aux(original, copia);
    
    
    p_apilar(original, tope); 
    p_apilar(copia, te_crear(tope->clave)); 
}

 
Pila copiarRecursivo(Pila p) {
    Pila copia = p_crear();
    copiarRec_aux(p, copia);
    return copia;
}

int contarElementos(Pila p) {
    return 0;
}

bool compararPilas(Pila p1, Pila p2) {
    return false;
}

char *cambioDeBase(int numero, int base) {
    
    if (numero == 0) {
        char *resultado = (char *)malloc(2 * sizeof(char));
        strcpy(resultado, "0");
        return resultado;
    }

    Pila p = p_crear();
    int aux = numero;

    
    while (aux > 0) {
        int resto = aux % base;
        p_apilar(p, te_crear(resto));
        aux = aux / base;
    }

    
    char *resultado = (char *)malloc(33 * sizeof(char)); 
    int i = 0;

    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        int valor = te->clave;

        
        if (valor < 10) {
            resultado[i] = valor + '0'; 
        } 
        
        else {
            resultado[i] = (valor - 10) + 'A';
        }
        i++;
    }
    
    
    resultado[i] = '\0';

    return resultado;
}



Pila invertirPila(Pila p) {
    return NULL;
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {
    return NULL;
}

Pila eliminarRepetidos(Pila p) {
    return NULL;
}
