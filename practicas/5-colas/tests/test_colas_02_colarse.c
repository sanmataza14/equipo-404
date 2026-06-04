#include <assert.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para colarse");

    Cola c = c_crear();
    
    c_encolar(c, te_crear(1));
    c_encolar(c, te_crear(6));
    c_encolar(c, te_crear(3));
    c_encolar(c, te_crear(7));
    c_encolar(c, te_crear(4));
    c_encolar(c, te_crear(8));
    c_encolar(c, te_crear(3));

    printf("\n1. Estado Inicial:\n");
    c_mostrar(c); 

    printf("\n2. Ejecutando: insertarElemento(c, te_crear(20), pos=5)\n");
    insertarElemento(c, te_crear(20), 5);
    printf("Resultado esperado : Frente -> [ 1 6 3 7 20 4 8 3 ] <- Final\n");
    printf("Resultado obtenido : ");
    c_mostrar(c);

    printf("\n3. Ejecutando: insertarElemento(c, te_crear(30), pos=1)\n");
    insertarElemento(c, te_crear(30), 1);
    printf("Resultado esperado : Frente -> [ 30 1 6 3 7 20 4 8 3 ] <- Final\n");
    printf("Resultado obtenido : ");
    c_mostrar(c);

    printf("\n>>> TEST FINALIZADO <<<\n");

    return 0;
}
