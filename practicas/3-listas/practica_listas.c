#include <stdlib.h>
#include <math.h>

#include "practica_listas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

double promedio(Lista l) {
    
    if (l_es_vacia(l)) {
        return 0.0;
    }

    double suma = 0;
    int contador = 0;
    
    
    Iterador iter = iterador(l);

    
    while (hay_siguiente(iter)) {
        
        TipoElemento te = siguiente(iter);
        
        
        suma += te->clave; 
        contador++;
    }

    return suma / contador;
}

struct ElementoYPosicion menorYPosicion(Lista l) {
    struct ElementoYPosicion resultado;
    
    
    if (l_es_vacia(l)) {
        resultado.valor = 0;
        resultado.ordinal = 0;
        return resultado;
    }

    Iterador iter = iterador(l);
    
    
    TipoElemento te = siguiente(iter);
    
    resultado.valor = te->clave; 
    resultado.ordinal = 1;
    
    int posicion_actual = 2; 
    
    
    while (hay_siguiente(iter)) {
        te = siguiente(iter);
        
        if (te->clave < resultado.valor) {
            resultado.valor = te->clave;
            resultado.ordinal = posicion_actual;
        }
        
        posicion_actual++;
    }
    
    return resultado;
}

Lista multiplos(Lista l, int n) {
    
    Lista resultado = l_crear();
    
    
    if (l_es_vacia(l) || n == 0) {
        return resultado;
    }

    
    Iterador iter = iterador(l);

    
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        
        
        if (te->clave % n == 0) {
            
            l_agregar(resultado, te);
        }
    }

    
    return resultado;
}

Lista invertirListaRec(Iterador iter) {
    
    if (!hay_siguiente(iter)) {
        return l_crear();
    }

    TipoElemento te = siguiente(iter);
    Lista lista_invertida = invertirListaRec(iter);
    l_agregar(lista_invertida, te);

    return lista_invertida;
}

Lista invertirLista(Lista l) {
    
    Iterador iter = iterador(l);
    return invertirListaRec(iter);
}

enum Comparacion compararListas(Lista l1, Lista l2) {
    int puntos_l1 = 0;
    int puntos_l2 = 0;

    
    Iterador i1 = iterador(l1);
    Iterador i2 = iterador(l2);

    
    while (hay_siguiente(i1) && hay_siguiente(i2)) {
        TipoElemento te1 = siguiente(i1);
        TipoElemento te2 = siguiente(i2);

        
        if (te1->clave > te2->clave) {
            puntos_l1++;
        } else if (te1->clave < te2->clave) {
            puntos_l2++;
        }
    }

    
    if (puntos_l1 > puntos_l2) {
        return MAYOR;
    } else if (puntos_l1 < puntos_l2) {
        return MENOR;
    } else {
        return IGUAL;
    }
}


double evaluar(struct Polinomio p, double x) {
}


Lista valores(struct Polinomio p, int desde, int hasta, double paso) {
}
