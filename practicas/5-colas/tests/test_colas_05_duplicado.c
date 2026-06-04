#include <stdio.h>
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para duplicar cola");

    Cola c = c_crear();
    
    c_encolar(c, te_crear(1));
    c_encolar(c, te_crear(6));
    c_encolar(c, te_crear(3));
    c_encolar(c, te_crear(7));
    c_encolar(c, te_crear(4));
    c_encolar(c, te_crear(8));
    c_encolar(c, te_crear(3));

    printf("\n1. Cola Original (Antes de copiar):\n");
    c_mostrar(c); 

    printf("\n2. Ejecutando: Cola copia_c = copia(c)\n");
    Cola copia_c = copia(c);
    
    printf("\nResultado - Cola Copia:\n");
    c_mostrar(copia_c); 

    printf("\nResultado - Cola Original (Debe seguir intacta):\n");
    c_mostrar(c);       

    printf("\n>>> TEST FINALIZADO <<<\n");

    return 0;
}
