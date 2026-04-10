#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {

    assert(restoRecursivo(10, 2) == 0);
    assert(restoRecursivo(22, 3) == 1);
    assert(restoRecursivo(-22, 3) == -1);
    assert(restoRecursivo(-22, -3) == 1);
    assert(restoRecursivo(22, -3) == -1);

    return 0;
}
