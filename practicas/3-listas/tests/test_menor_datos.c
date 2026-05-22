#include <stdio.h>
#include "../practica_listas.h"
#include "cadenas.h"
#include "listas/listas.h"
#include "tipo_elemento/tipo_elemento.h"

int main() {
    imprimir_titulo("Tests para calcular el menor de los datos");

    
    Lista lista_prueba = l_crear();

    
    l_agregar(lista_prueba, te_crear(15));
    l_agregar(lista_prueba, te_crear(4));  
    l_agregar(lista_prueba, te_crear(22));
    l_agregar(lista_prueba, te_crear(9));

    
    struct ElementoYPosicion resultado = menorYPosicion(lista_prueba);

    
    printf("El numero menor encontrado es: %d\n", resultado.valor);
    printf("Se encontro en la posicion (ordinal): %d\n", resultado.ordinal);

    
    return 0;
}
