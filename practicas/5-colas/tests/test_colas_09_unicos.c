#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para Unicos en Colas");

    bool todo_ok = true;

    
    Cola c1 = c_crear();
    c_encolar(c1, te_crear(1)); c_encolar(c1, te_crear(6)); c_encolar(c1, te_crear(3));
    c_encolar(c1, te_crear(7)); c_encolar(c1, te_crear(4)); c_encolar(c1, te_crear(8));
    c_encolar(c1, te_crear(3));

    Cola res1 = unicos(c1);
    int esp1[] = {1, 6, 7, 4, 8};

    for (int i = 0; i < 5; i++) {
        if (c_es_vacia(res1)) {
            printf("\n>>> ERROR: 'res1' tiene menos elementos de los esperados.\n");
            todo_ok = false; break;
        }
        int val = c_desencolar(res1)->clave;
        if (val != esp1[i]) {
            printf("\n>>> ERROR en Caso 1: Esperaba %d, llego %d.\n", esp1[i], val);
            todo_ok = false;
        }
    }

    
    Cola c2 = c_crear();
    c_encolar(c2, te_crear(12)); c_encolar(c2, te_crear(6)); c_encolar(c2, te_crear(8));
    c_encolar(c2, te_crear(5));  c_encolar(c2, te_crear(8)); c_encolar(c2, te_crear(12));
    c_encolar(c2, te_crear(12));

    Cola res2 = unicos(c2);
    int esp2[] = {6, 5};

    for (int i = 0; i < 2; i++) {
        if (c_es_vacia(res2)) {
            printf("\n>>> ERROR: 'res2' tiene menos elementos de los esperados.\n");
            todo_ok = false; break;
        }
        int val = c_desencolar(res2)->clave;
        if (val != esp2[i]) {
            printf("\n>>> ERROR en Caso 2: Esperaba %d, llego %d.\n", esp2[i], val);
            todo_ok = false;
        }
    }

    
    int original_c2[] = {12, 6, 8, 5, 8, 12, 12};
    for (int i = 0; i < 7; i++) {
        if (c_desencolar(c2)->clave != original_c2[i]) {
            printf("\n>>> ERROR: La cola original fue alterada.\n");
            todo_ok = false; break;
        }
    }

    if (!todo_ok) {
        printf("\n--- EL TEST FALLO ---\n");
        return 1;
    }

    printf("\n¡Todos los tests de colas unicas pasaron con exito!\n");
    return 0;
}