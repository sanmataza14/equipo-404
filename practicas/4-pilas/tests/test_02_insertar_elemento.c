#include "../practica_pilas.h"
#include "tipo_elemento/tipo_elemento.h" 
#include "pilas/pilas.h"                 

#include "cadenas.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    imprimir_titulo("Tests para insertar elemento");

    Pila p = p_crear();
    
    
    p_apilar(p, te_crear(1));
    p_apilar(p, te_crear(6));
    p_apilar(p, te_crear(13));
    p_apilar(p, te_crear(3));
    p_apilar(p, te_crear(7));
    p_apilar(p, te_crear(4));
    p_apilar(p, te_crear(8));
    p_apilar(p, te_crear(3)); 

    
    insertarElemento(p, te_crear(20), 5); 

    
    insertarElemento(p, te_crear(30), 1); 

    
    int esperados[] = {30, 3, 8, 4, 7, 20, 3, 13, 6, 1};
    bool todo_ok = true;

    
    for (int i = 0; i < 10; i++) {
        if (p_es_vacia(p)) {
            printf("\n>>> ERROR: La pila se vacio antes de tiempo buscando la posicion %d.\n", i + 1);
            todo_ok = false;
            break;
        }

        TipoElemento te = p_desapilar(p);

        if (te->clave != esperados[i]) {
            printf("\n>>> ERROR en la posicion de la pila %d: Se esperaba un %d pero tu funcion dejo un %d.\n", i + 1, esperados[i], te->clave);
            todo_ok = false;
        }
    }

    if (!todo_ok) {
        printf("\n--- EL TEST FALLO: Revisa los errores de arriba ---\n");
        return 1; 
    }

    printf("\n¡Los tests de insertar elemento pasaron con exito!\n");
    return 0;
}