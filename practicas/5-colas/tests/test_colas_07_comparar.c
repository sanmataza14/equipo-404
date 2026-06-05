#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para Comparar Colas");

    
    Cola c1 = c_crear();
    c_encolar(c1, te_crear(1)); c_encolar(c1, te_crear(6)); c_encolar(c1, te_crear(3));
    c_encolar(c1, te_crear(7)); c_encolar(c1, te_crear(4)); c_encolar(c1, te_crear(8)); c_encolar(c1, te_crear(3));

    
    Cola c2 = c_crear();
    c_encolar(c2, te_crear(1)); c_encolar(c2, te_crear(6)); c_encolar(c2, te_crear(3));
    c_encolar(c2, te_crear(7)); c_encolar(c2, te_crear(4)); c_encolar(c2, te_crear(8)); c_encolar(c2, te_crear(3));

    
    Cola c3 = c_crear();
    c_encolar(c3, te_crear(1)); c_encolar(c3, te_crear(6)); c_encolar(c3, te_crear(3));
    c_encolar(c3, te_crear(7)); c_encolar(c3, te_crear(4)); c_encolar(c3, te_crear(8));

    
    Cola c4 = c_crear();
    c_encolar(c4, te_crear(6)); c_encolar(c4, te_crear(1)); c_encolar(c4, te_crear(3));
    c_encolar(c4, te_crear(7)); c_encolar(c4, te_crear(4)); c_encolar(c4, te_crear(8)); c_encolar(c4, te_crear(5));

    
    bool res1 = comparar(c1, c2);
    bool res2 = comparar(c1, c3);
    bool res3 = comparar(c1, c4);

    bool todo_ok = true;

    if (!res1) { printf("\n>>> ERROR: c1 y c2 deberian dar TRUE.\n"); todo_ok = false; }
    if (res2)  { printf("\n>>> ERROR: c1 y c3 deberian dar FALSE.\n"); todo_ok = false; }
    if (res3)  { printf("\n>>> ERROR: c1 y c4 deberian dar FALSE.\n"); todo_ok = false; }

    
    int esperados[] = {1, 6, 3, 7, 4, 8, 3};
    for (int i = 0; i < 7; i++) {
        if (c_es_vacia(c1)) {
            printf("\n>>> ERROR: c1 se vacio durante la comparacion.\n");
            todo_ok = false; break;
        }
        if (c_desencolar(c1)->clave != esperados[i]) {
            printf("\n>>> ERROR: c1 se desordeno durante la comparacion.\n");
            todo_ok = false; break;
        }
    }

    if (!todo_ok) {
        printf("\n--- EL TEST FALLO ---\n");
        return 1;
    }

    printf("\n¡Todos los tests de comparar colas pasaron con exito!\n");
    return 0;
}