#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para palíndromos");

    char p1[] = "neuquen";
    char p2[] = "palindromo";

    assert(esPalindromo(p1) == true);
    assert(esPalindromo(p2) == false);

    return 0;
}
