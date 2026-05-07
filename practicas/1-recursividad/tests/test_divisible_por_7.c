#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


int main() {
    imprimir_titulo("Tests para divisiblePor7");
    assert(esDivisiblePor7(32291) == true);
    assert(esDivisiblePor7(110) == false);
    assert(esDivisiblePor7(-700) == true);
    assert(esDivisiblePor7(20) == false);
    return 0;
}
