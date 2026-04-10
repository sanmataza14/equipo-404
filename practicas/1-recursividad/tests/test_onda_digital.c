#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    
    char *r1 = ondaDigital("HL");
    assert(str_eq(r1, "-|_")); 
    free(r1); 

    char *r2 = ondaDigital("LH");
    assert(str_eq(r2, "_|-"));
    free(r2);

    char *r3 = ondaDigital("HLHL");
    assert(str_eq(r3, "-|_|-|_"));
    free(r3);

    char *r4 = ondaDigital("HLLHHL");
    assert(str_eq(r4, "-|__|--|_")); 
    free(r4);

    return 0;
}
