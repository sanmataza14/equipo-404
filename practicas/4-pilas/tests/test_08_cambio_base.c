#include "../practica_pilas.h"
#include "cadenas.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    imprimir_titulo("Tests para Cambio de Base");

    
    char* res1 = cambioDeBase(10, 2);
    char* res2 = cambioDeBase(10, 3);
    char* res3 = cambioDeBase(16, 3);
    char* res4 = cambioDeBase(567, 16);
    char* res5 = cambioDeBase(759, 16);

    bool todo_ok = true;

    
    if (strcmp(res1, "1010") != 0) { 
        printf("\n>>> ERROR Caso 1: Esperaba '1010', pero tu funcion devolvio '%s'.\n", res1); 
        todo_ok = false; 
    }
    if (strcmp(res2, "101") != 0) { 
        printf("\n>>> ERROR Caso 2: Esperaba '101', pero tu funcion devolvio '%s'.\n", res2); 
        todo_ok = false; 
    }
    if (strcmp(res3, "121") != 0) { 
        printf("\n>>> ERROR Caso 3: Esperaba '121', pero tu funcion devolvio '%s'.\n", res3); 
        todo_ok = false; 
    }
    if (strcmp(res4, "237") != 0) { 
        printf("\n>>> ERROR Caso 4: Esperaba '237', pero tu funcion devolvio '%s'.\n", res4); 
        todo_ok = false; 
    }
    if (strcmp(res5, "2F7") != 0) { 
        printf("\n>>> ERROR Caso 5: Esperaba '2F7', pero tu funcion devolvio '%s'.\n", res5); 
        todo_ok = false; 
    }

    
    free(res1); free(res2); free(res3); free(res4); free(res5);

    if (!todo_ok) {
        printf("\n--- EL TEST FALLO: Revisa los errores de arriba ---\n");
        return 1;
    }

    printf("\n¡Los tests de cambio de base pasaron con exito!\n");
    return 0;
}
