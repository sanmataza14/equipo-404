#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursividad.h"

bool esCapicua(int numero) {
}

bool esPalindromo(char *palabra) {
    int largo = strlen(palabra);
    if (largo == 0 || largo == 1)
    {
        return true;
    } else if (palabra[0] != palabra[largo - 1])
    {
        return false;
    } else {
        palabra[largo - 1] = '\0';
        return esPalindromo(palabra + 1);
    }
}

int productoRecursivo(int m, int n) {
}

int terminoSerieDeFibonacci(int n) {
}

bool esDivisiblePor7(int n) {
}

void explosionRecursiva(int n, int b, int *result, int *size) {
}

int *explosion(int n, int b, int *size) {
}

char *chinos(unsigned int nivel) {
}

char *agregarSeparadoresRecursivo(char *numero, int indice, int contador) {
}

char *agregarSeparadorMiles(char *numero) {
}
