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
    if(n<1){
    return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    else {
    return terminoSerieDeFibonacci(n - 1) + terminoSerieDeFibonacci(n - 2);
}
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
    while (n >= 70){
        int cifra = n % 10;
        int resto = n / 10;
        n = resto - (cifra * 2);
    }
    if(n % 7 == 0){
        return true;
    }
    else {
        return false;
    }
}

void explosionRecursiva(int n, int b, int *result, int *size) {
}

int *explosion(int n, int b, int *size) {
    if (n <= b){
        int* unicopedazo = (int*) malloc(1* sizeof(int));
        unicopedazo[0] = n;
        *size = 1;

        return unicopedazo;
    }
    int n1 = n / b;
    int n2 = n - n1;
    int size1, size2;

    int* pedazos1 = explosion(n1, b, &size1);
    int* pedazos2 = explosion(n2, b, &size2);

    *size = size1 + size2;
    int* resultado = (int*) malloc((*size) * sizeof(int));

    for(int i=0; i < size1; i++){
        resultado[i] = pedazos1[i];
    }
    for(int i=0; i < size2; i++){
        resultado[size1 + i] = pedazos2[i];
    }

    free(pedazos1);
    free(pedazos2);
    
    return resultado;
}

char *chinos(unsigned int nivel) {
    unsigned int bytes_necesarios = 6 * nivel;
    char* resultado = (char*)malloc(bytes_necesarios * sizeof(char));

    if (nivel == 1) {
        strcpy(resultado, "(-.-)");
    } 
    else {
        char* interior = chinos(nivel - 1); 
        
        sprintf(resultado, "(-.%s.-)", interior); 
        
        free(interior); 
    }

    return resultado;
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