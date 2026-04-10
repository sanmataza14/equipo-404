#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursividad.h"

bool esCapicua(int numero) {
    if (numero < 0)
    {
        numero = -numero;
    }
    if (numero < 10) 
    {
        return true;
    }
    int divisor = 1;
    while (numero / divisor >= 10) {
        divisor = divisor * 10;
    }

    int primero = numero / divisor;
    int ultimo = numero % 10;

    if (primero != ultimo)
    {
        return false;
    }
    
    int centro = (numero % divisor) / 10;
    return esCapicua(centro);
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
    if (n<0){
        return productoRecursivo(-m, -n);
    }
    else if(n==0){
        return 0;
    }
    else {
        return m + productoRecursivo(m, n-1);
    }
}

int terminoSerieDeFibonacci(int n) {
}

int restoRecursivo(int dividendo, int divisor){
    if (dividendo < 0) {
        return -restoRecursivo(-dividendo, divisor);
    }
    if (divisor < 0) {
        return -restoRecursivo(dividendo, -divisor);
    }

    if (dividendo < divisor) {
        return dividendo;
    }

    return restoRecursivo(dividendo - divisor, divisor);
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
    int n = strlen(numero); 

    if (n <= 3) {
        return strdup(numero); 
    }

    char ultimosTres[4]; 
    strcpy(ultimosTres, &numero[n - 3]);

    char restoAMedias[100]; 
    strncpy(restoAMedias, numero, n - 3);
    restoAMedias[n - 3] = '\0'; 

    char *izquierdaYaFormateada = agregarSeparadorMiles(restoAMedias); 

    char *resultado = (char *)malloc(strlen(izquierdaYaFormateada) + 1 + 3 + 1); 

    sprintf(resultado, "%s.%s", izquierdaYaFormateada, ultimosTres); 

    free(izquierdaYaFormateada); 

    return resultado;
}

char* ondaDigital(char *s) {
    
    if (s == NULL || *s == '\0') {
        return strdup(""); 
    }
    
    char simbolo = (s[0] == 'H') ? '-' : '_';

    if (s[1] == '\0') {
        char *res = malloc(2);
        res[0] = simbolo;
        res[1] = '\0';
        return res;
    }
   
    char *colaDeLaOnda = ondaDigital(s + 1);
    
    int hayTransicion = (s[0] != s[1]);
    
    char *resultado = malloc(1 + hayTransicion + strlen(colaDeLaOnda) + 1);
    
    if (hayTransicion) {
        sprintf(resultado, "%c|%s", simbolo, colaDeLaOnda);
    } else {
        sprintf(resultado, "%c%s", simbolo, colaDeLaOnda);
    }
    
    free(colaDeLaOnda);

    return resultado;
}