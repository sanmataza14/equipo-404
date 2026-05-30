#include "../practica_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para invertir pila");

    Pila p1 = p_crear();
    
    // Armamos el caso de prueba: (1, 6, 3, 7, 4, 8, 3)
    p_apilar(p1, te_crear(1));
    p_apilar(p1, te_crear(6));
    p_apilar(p1, te_crear(3));
    p_apilar(p1, te_crear(7));
    p_apilar(p1, te_crear(4));
    p_apilar(p1, te_crear(8));
    p_apilar(p1, te_crear(3));

    printf("Estado Inicial:\n");
    p_mostrar(p1); 

    printf("\nEjecutando: Pila resultado = invertirPila(p1)...\n\n");
    Pila resultado = invertirPila(p1);

    printf("Pila Resultado (Invertida):\n");
    p_mostrar(resultado); 

    printf("\nPila Original (Debe seguir intacta):\n");
    p_mostrar(p1); 

    printf("\n>>> TEST FINALIZADO <<<\n");
    
    return 0;
}
