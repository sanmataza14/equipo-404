#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {

    char *r1 = agregarSeparadorMiles("123456");
    assert(str_eq(r1, "123.456"));
    free(r1); 

    char *r2 = agregarSeparadorMiles("12345678");
    assert(str_eq(r2, "12.345.678"));
    free(r2); 

    return 0;
}
