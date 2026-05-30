#include "../practica_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

void mostrarPilaTopeABase(Pila p) {
    if (p == NULL || p_es_vacia(p)) {
        printf("Pila vacia\n");
        return;
    }
    
    Pila aux = p_crear();
    printf("Tope -> ");
    
    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        printf("%d ", te->clave);
        p_apilar(aux, te);
    }
    printf("<- Base\n");

    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
}

int main() {
    imprimir_titulo("Tests para eliminar elemento");

    Pila p = p_crear();
    
    p_apilar(p, te_crear(1));
    p_apilar(p, te_crear(6));
    p_apilar(p, te_crear(3));
    p_apilar(p, te_crear(7));
    p_apilar(p, te_crear(4));
    p_apilar(p, te_crear(8));
    p_apilar(p, te_crear(3));

    printf("1. Estado Inicial:\n");
    mostrarPilaTopeABase(p);

    printf("\n2. Ejecutando: eliminarElemento(p, 3)\n");
    eliminarElemento(p, 3);
    mostrarPilaTopeABase(p); 

    printf("\n3. Ejecutando: eliminarElemento(p, 3)\n");
    eliminarElemento(p, 3);
    mostrarPilaTopeABase(p);

    printf("\n4. Ejecutando: eliminarElemento(p, 1)\n");
    eliminarElemento(p, 1);
    mostrarPilaTopeABase(p); 

    printf("\n>>> TEST FINALIZADO <<<\n");

    return 0;
}
