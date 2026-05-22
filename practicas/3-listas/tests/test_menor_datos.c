#include <stdio.h>
#include "../practica_listas.h"
#include "cadenas.h"
#include "listas/listas.h"
#include "tipo_elemento/tipo_elemento.h"

int main() {
    imprimir_titulo("Tests para calcular el menor de los datos");

    // 1. Creamos una lista vacía para la prueba
    Lista lista_prueba = l_crear();

    // 2. Le agregamos datos inventados 
    // (OJO: fijate cómo se llama la función de tu cátedra para crear un TipoElemento, 
    // a veces es te_crear(numero) o algo similar)
    l_agregar(lista_prueba, te_crear(15));
    l_agregar(lista_prueba, te_crear(4));  // <-- Este debería ser el menor (Posición 2)
    l_agregar(lista_prueba, te_crear(22));
    l_agregar(lista_prueba, te_crear(9));

    // 3. Llamamos a la función espectacular que armaste
    struct ElementoYPosicion resultado = menorYPosicion(lista_prueba);

    // 4. Mostramos por consola para verificar
    printf("El numero menor encontrado es: %d\n", resultado.valor);
    printf("Se encontro en la posicion (ordinal): %d\n", resultado.ordinal);

    // Si todo sale bien, recién ahí terminamos el programa
    return 0;
}
