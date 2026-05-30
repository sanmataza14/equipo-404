#include "../practica_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para contar elementos");

    Pila p = p_crear();
    
    // Armamos la pila del caso de prueba: (1, 6, 3, 7, 4, 8, 3)
    p_apilar(p, te_crear(1));
    p_apilar(p, te_crear(6));
    p_apilar(p, te_crear(3));
    p_apilar(p, te_crear(7));
    p_apilar(p, te_crear(4));
    p_apilar(p, te_crear(8));
    p_apilar(p, te_crear(3));

    printf("Pila cargada exitosamente.\n");
    printf("Ejecutando: contarElementos(p)\n\n");
    
    int cantidad = contarElementos(p);

    printf("Resultado esperado: 7\n");
    printf("Resultado de tu codigo: %d\n", cantidad);

    if (cantidad == 7) {
        printf("\n>>> ESTADO: TEST SUPERADO CON EXITO! <<<\n");
    } else {
        printf("\n>>> ESTADO: FALLO EL TEST <<<\n");
    }

    return 0;
}
