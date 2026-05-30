#include "../practica_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

void mostrarPilaConCantidades(Pila p) {
    if (p == NULL || p_es_vacia(p)) {
        printf("Pila vacia\n");
        return;
    }

    Pila aux = p_crear();
    printf("Tope -> [ ");

    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        int ocurrencias = (int)(long)te->valor;
        printf("%d:%d ", te->clave, ocurrencias);
        p_apilar(aux, te);
    }
    printf("] <- Base\n");

    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
}

int main() {
    imprimir_titulo("Tests para elementos en común");

    Pila p = p_crear();
    
    int valores[] = {1, 2, 1, 3, 4, 5, 2, 1, 3, 5, 5};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        p_apilar(p, te_crear(valores[i]));
    }

    printf("Ejecutando contarRepetidos()...\n\n");
    Pila resultado = eliminarRepetidos(p);

    printf("Pila Resultado (Clave:Apariciones):\n");
    mostrarPilaConCantidades(resultado); 

    printf("\nPila Original intacta:\n");
    p_mostrar(p); 

    printf("\n>>> TEST FINALIZADO <<<\n");

    return 0;
}
