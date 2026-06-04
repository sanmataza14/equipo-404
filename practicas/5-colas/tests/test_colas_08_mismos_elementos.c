#include <stdio.h>
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

Cola armar_cola(int valores[], int n) {
    Cola c = c_crear();
    for (int i = 0; i < n; i++) {
        c_encolar(c, te_crear(valores[i]));
    }
    return c;
}

int main() {
    imprimir_titulo("Tests para mismos elementos");

    int v1[] = {1, 6, 3, 7, 4, 8, 3};
    int v2[] = {6, 6, 3, 6, 1, 7, 4, 8, 3};
    int v3[] = {6, 3, 7, 4, 8};

    Cola c1 = armar_cola(v1, 7);
    Cola c2 = armar_cola(v2, 9);
    Cola c3 = armar_cola(v3, 5);

    printf("\nEstado de las colas:\n");
    printf("c1 -> "); c_mostrar(c1);
    printf("c2 -> "); c_mostrar(c2);
    printf("c3 -> "); c_mostrar(c3);

    printf("\nResultados de las comparaciones:\n\n");
    
    printf("1. mismosElementos(c1, c2)  | Esperado: 1 | Obtenido: %d\n", mismosElementos(c1, c2));
    printf("2. mismosElementos(c2, c1)  | Esperado: 1 | Obtenido: %d\n", mismosElementos(c2, c1));
    printf("3. mismosElementos(c1, c3)  | Esperado: 0 | Obtenido: %d\n", mismosElementos(c1, c3));
    printf("4. mismosElementos(c3, c1)  | Esperado: 0 | Obtenido: %d\n", mismosElementos(c3, c1));

    printf("\n>>> TEST FINALIZADO <<<\n");

    return 0;
}
