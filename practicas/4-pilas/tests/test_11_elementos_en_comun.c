#include "../practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "pilas/pilas.h"

#include "cadenas.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    imprimir_titulo("Tests para Elementos en Comun");

    Pila p1 = p_crear();
    
    p_apilar(p1, te_crear(1));
    p_apilar(p1, te_crear(4));
    p_apilar(p1, te_crear(7));
    p_apilar(p1, te_crear(9));
    p_apilar(p1, te_crear(8)); 

    Pila p2 = p_crear();
    
    p_apilar(p2, te_crear(4));
    p_apilar(p2, te_crear(1));
    p_apilar(p2, te_crear(6));
    p_apilar(p2, te_crear(9));
    p_apilar(p2, te_crear(3)); 

    
    Pila comunes = elementosEnComun(p1, p2);

    bool todo_ok = true;

   
    int esperados_comunes[] = {9, 4, 1};
    for (int i = 0; i < 3; i++) {
        if (p_es_vacia(comunes)) {
            printf("\n>>> ERROR: 'comunes' se vacio antes de tiempo.\n");
            todo_ok = false; break;
        }
        TipoElemento te = p_desapilar(comunes);
        if (te->clave != esperados_comunes[i]) {
            printf("\n>>> ERROR en 'comunes': Esperaba %d pero llego %d.\n", esperados_comunes[i], te->clave);
            todo_ok = false;
        }
    }

    
    int esperados_p1[] = {8, 9, 7, 4, 1};
    for (int i = 0; i < 5; i++) {
        if (p_es_vacia(p1)) {
            printf("\n>>> ERROR: Destruiste la pila original p1.\n");
            todo_ok = false; break;
        }
        if (p_desapilar(p1)->clave != esperados_p1[i]) {
            printf("\n>>> ERROR: La pila p1 perdio su orden.\n");
            todo_ok = false; break;
        }
    }

    
    int esperados_p2[] = {3, 9, 6, 1, 4};
    for (int i = 0; i < 5; i++) {
        if (p_es_vacia(p2)) {
            printf("\n>>> ERROR: Destruiste la pila original p2.\n");
            todo_ok = false; break;
        }
        if (p_desapilar(p2)->clave != esperados_p2[i]) {
            printf("\n>>> ERROR: La pila p2 perdio su orden.\n");
            todo_ok = false; break;
        }
    }

    if (!todo_ok) {
        printf("\n--- EL TEST FALLO: Revisa los errores de arriba ---\n");
        return 1;
    }

    printf("\n¡Los tests de elementos en comun pasaron con exito!\n");
    return 0;
}
