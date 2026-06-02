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
    
    while (!p_es_vacia(p)) {
        TipoElemento actual = p_desapilar(p);
        if (actual->clave == e->clave) {
            encontrado = true;
        }
        p_apilar(aux, actual);
    }
    
    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
    return encontrado;
}

Pila elementosEnComun(Pila p1, Pila p2) {
    Pila comunes = p_crear();
    Pila aux1 = p_crear();

    while (!p_es_vacia(p1)) {
        p_apilar(aux1, p_desapilar(p1));
    }

    while (!p_es_vacia(aux1)) {
        TipoElemento actual = p_desapilar(aux1);
         
        if (buscarElemento(p2, actual)) {
            
            if (!buscarElemento(comunes, actual)) {
                p_apilar(comunes, te_crear(actual->clave));
            }
        }
        p_apilar(p1, actual);
    }
    return comunes;
}

void elementosEnComunRec_aux(Pila p1, Pila p2, Pila comunes) {
    
    if (p_es_vacia(p1)) return;
    
    TipoElemento tope = p_desapilar(p1);
    
    elementosEnComunRec_aux(p1, p2, comunes);
    
    if (buscarElemento(p2, tope)) {
        if (!buscarElemento(comunes, tope)) {
            p_apilar(comunes, te_crear(tope->clave));
        }
    }
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
    if(p == NULL || p_es_vacia(p)) return;
    int cant = contarElementos(p);
    if (pos1 < 1 || pos1 > cant || pos2 < 1 || pos2 > cant) return;
    Pila aux = p_crear();
    int contador = 1;
    TipoElemento te1 = NULL;
    TipoElemento te2 = NULL;

    while (!p_es_vacia(p)) {
    TipoElemento actual = p_desapilar(p);

    if (contador == pos1) {
        te1 = actual;
        p_apilar(aux, actual);
    } else if (contador == pos2) {
        te2 = actual;
        p_apilar(aux, actual);
    } else {
        p_apilar(aux, actual);
    }
    contador++;
}
int cont_vuelta = 1;

while (!p_es_vacia(aux)) {
    if (cont_vuelta == pos1) {
        p_apilar(p, te2);
        p_desapilar(aux);
        cont_vuelta++;
    } 
    else if (cont_vuelta == pos2) {
        p_apilar(p, te1);
        p_desapilar(aux);
        cont_vuelta++; 
    }
    else {
    TipoElemento temp = p_desapilar(aux);
    p_apilar(p, temp);
    cont_vuelta++;
    }
}
    return;
}

void intercambiarAux(Pila p, int pos1, int pos2, int actual, TipoElemento *te1, TipoElemento *te2) {
    if (p_es_vacia(p)) return;
    TipoElemento elem = p_desapilar(p);

    if (actual == pos1) {
        *te1 = elem;
    } else if (actual == pos2) {
        *te2 = elem;
    }

    intercambiarAux(p, pos1, pos2, actual + 1, te1, te2);

    if (actual == pos1) {
        p_apilar(p, *te2);
    } else if (actual == pos2) {
        p_apilar(p, *te1);
    } else {
        p_apilar(p, elem);
    }
}

void intercambiarElementosRec(Pila p, int pos1, int pos2) {
    if (p == NULL || p_es_vacia(p)) return;
    if (pos1 == pos2) return; 
    int cant = contarElementos(p);
    
    if (pos1 < 1 || pos1 > cant || pos2 < 1 || pos2 > cant) return;

    TipoElemento te1 = NULL;
    TipoElemento te2 = NULL;

    intercambiarAux(p, pos1, pos2, 1, &te1, &te2);
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
    if (p == NULL || p_es_vacia(p)) {
        return 0;
    }
    Pila aux = p_crear();
    int contador = 0;

    while (!p_es_vacia(p)) {
        p_apilar(aux, p_desapilar(p));
        contador++;
    }
    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
    return contador;
}

bool compararPilas(Pila p1, Pila p2) {
    if (contarElementos(p1) != contarElementos(p2)) return false;

    Pila aux = p_crear();
    bool iguales = true;
    
    while(!p_es_vacia(p1)){
    TipoElemento e1 = p_desapilar(p1);
    TipoElemento e2 = p_desapilar(p2);
    
    if (e1->clave != e2->clave) {
        iguales = false;
    }
    p_apilar(aux, e1);
    p_apilar(aux, e2);
    }
    while (!p_es_vacia(aux)){
        TipoElemento e2 = p_desapilar(aux);
        TipoElemento e1 = p_desapilar(aux);

        p_apilar(p2, e2);
        p_apilar(p1, e1);
    }
    return iguales;
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
    Pila modif = p_crear();
    Pila aux_guardar = p_crear();
    Pila aux_filtrados = p_crear();
    
    if (p == NULL || p_es_vacia(p)) {
        return modif;
    }
    while (!p_es_vacia(p)) {
        TipoElemento actual = p_desapilar(p);
        
        p_apilar(aux_guardar, actual); 

        if (actual->clave != clave) {
            TipoElemento clon = te_crear(actual->clave); 
            p_apilar(aux_filtrados, clon);
        }
    }

    while (!p_es_vacia(aux_guardar)) {
        p_apilar(p, p_desapilar(aux_guardar));
    }

    while (!p_es_vacia(aux_filtrados)) {
        p_apilar(modif, p_desapilar(aux_filtrados));
    }
    return modif;
}

void eliminarOcurrenciasAux(Pila p, int clave, Pila modif) {
    if (p_es_vacia(p)) {
        return;
    }
    TipoElemento actual = p_desapilar(p);
    eliminarOcurrenciasAux(p, clave, modif);
    p_apilar(p, actual);

    if (actual->clave != clave) {
        p_apilar(modif, actual);
    }
}

Pila eliminarTodasOcurrenciasRec(Pila p, int clave) {
    Pila modif = p_crear();

    if (p == NULL || p_es_vacia(p)) {
        return modif;
    }
    eliminarOcurrenciasAux(p, clave, modif);
    return modif;
}

Pila eliminarRepetidos(Pila p) {
    Pila resultado = p_crear();
    if (p == NULL || p_es_vacia(p)) {
        return resultado;
    }

    Pila aux_p = p_crear();

    while (!p_es_vacia(p)) {
        TipoElemento actual = p_desapilar(p);
        p_apilar(aux_p, actual);

        Pila aux_res = p_crear();
        bool encontrado = false;

        while (!p_es_vacia(resultado)) {
            TipoElemento te_res = p_desapilar(resultado);
            if (te_res->clave == actual->clave) {
                int cantidad_actual = (int)(long)te_res->valor;
                te_res->valor = (void*)(long)(cantidad_actual + 1);
                encontrado = true;
            }
            p_apilar(aux_res, te_res);
        }

        while (!p_es_vacia(aux_res)) {
            p_apilar(resultado, p_desapilar(aux_res));
        }

        if (!encontrado) {
            TipoElemento nuevo = te_crear(actual->clave);
            nuevo->valor = (void*)(long)1; 
            p_apilar(resultado, nuevo);
        }
    }

    while (!p_es_vacia(aux_p)) {
        p_apilar(p, p_desapilar(aux_p));
    }

    return resultado;
}
