#include "../practica_listas.h"

#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para calcular el dato máximo y la cantidad de ocurrencias");

    Lista original = l_crear();
    l_agregar(original, te_crear(7));
    l_agregar(original, te_crear(6));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(7));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(8));
    l_agregar(original, te_crear(6));

    printf("Se cargaron los elementos en la lista.\n");
    printf("Resultado esperado -> Mayor: 8; Ocurrencias: 5\n\n");

    struct ElementoYOcurrencias resultado = mayorYOcurrencias(original);

    printf("Resultado de tu codigo -> Mayor: %d; Ocurrencias: %d\n", 
           resultado.valor, resultado.ocurrencias);

    if (resultado.valor == 8 && resultado.ocurrencias == 5) {
        printf("\n>>> ESTADO: TEST SUPERADO CON EXITO! <<<\n");
    } else {
        printf("\n>>> ESTADO: FALLO EL TEST <<<\n");
    }
    return 0;
}
