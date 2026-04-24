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

Mapa* cargar_mapa(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) return NULL;

    Mapa* mapa = malloc(sizeof(Mapa));
    // Leemos dimensiones
    if (fscanf(archivo, "%d %d", &mapa->filas, &mapa->columnas) != 2) {
        free(mapa);
        fclose(archivo);
        return NULL;
    }

    mapa->celdas = malloc(mapa->filas * sizeof(char*));

    for (int i = 0; i < mapa->filas; i++) {
        mapa->celdas[i] = malloc((mapa->columnas + 1) * sizeof(char));

        for (int j = 0; j < mapa->columnas; j++) {
            // El espacio antes de %c ignora espacios y saltos de línea
            fscanf(archivo, " %c", &mapa->celdas[i][j]);

            // Buscamos Inicio y Salida en el momento
            if (mapa->celdas[i][j] == 'I') {
                mapa->inicio.fila = i + 1;
                mapa->inicio.columna = j + 1;
            } else if (mapa->celdas[i][j] == 'S') {
                mapa->salida.fila = i + 1;
                mapa->salida.columna = j + 1;
            }
        }
        // Terminador nulo (buena práctica)
        mapa->celdas[i][mapa->columnas] = '\0';
    }

    fclose(archivo);
    return mapa;
}

void buscar_ruta(char** celdas, int filas, int columnas, Posicion pos_actual, int pasos, int puntaje, Solucion* Mejor_solucion, char* movimientos_actuales, Posicion* camino_actual){

    if (pos_actual.fila < 1 || pos_actual.fila > filas || pos_actual.columna < 1 || pos_actual.columna > columnas) {
        return;
    }
    if (celdas[pos_actual.fila - 1][pos_actual.columna - 1] == '#' || celdas[pos_actual.fila - 1][pos_actual.columna - 1] == 'X') {
        return; 
    }

    camino_actual[pasos] = pos_actual;
    char celda_actual = celdas[pos_actual.fila - 1][pos_actual.columna - 1];
    if (celda_actual >= '0' && celda_actual <= '9') {
            puntaje += (celda_actual - '0');
            }

    if (celda_actual == 'S') {
        bool mejor_encontrado = false;
        if (!Mejor_solucion->encontrada || puntaje > Mejor_solucion->puntaje || puntaje == Mejor_solucion->puntaje && pasos < Mejor_solucion->pasos) {
                mejor_encontrado = true;
            }

         if (mejor_encontrado) {
            if (Mejor_solucion->encontrada) {
                free(Mejor_solucion->movimientos);
                free(Mejor_solucion->camino);
            }

        Mejor_solucion->encontrada = true;
        Mejor_solucion->puntaje = puntaje;
        Mejor_solucion->pasos = pasos;
        Mejor_solucion->largo_camino = pasos + 1;

        Mejor_solucion->movimientos = malloc((pasos + 1) * sizeof(char));
        strcpy(Mejor_solucion->movimientos, movimientos_actuales);

        Mejor_solucion->camino = malloc((pasos + 1) * sizeof(Posicion));
        memcpy(Mejor_solucion->camino, camino_actual, (pasos + 1) * sizeof(Posicion));
        }
        return;
        }
    
        char valor_original = celdas[pos_actual.fila - 1][pos_actual.columna - 1];
        celdas[pos_actual.fila - 1][pos_actual.columna - 1] = 'X';
        Posicion nueva_pos;

        movimientos_actuales[pasos] = 'A';
        movimientos_actuales[pasos + 1] = '\0';
        nueva_pos.fila = pos_actual.fila - 1;
        nueva_pos.columna = pos_actual.columna;
        buscar_ruta(celdas, filas, columnas, nueva_pos, pasos + 1, puntaje, Mejor_solucion,         movimientos_actuales, camino_actual);


        movimientos_actuales[pasos] = 'B';
        movimientos_actuales[pasos + 1] = '\0';
        nueva_pos.fila = pos_actual.fila + 1;
        nueva_pos.columna = pos_actual.columna;
        buscar_ruta(celdas, filas, columnas, nueva_pos, pasos + 1, puntaje, Mejor_solucion,         movimientos_actuales, camino_actual);


        movimientos_actuales[pasos] = 'D';
        movimientos_actuales[pasos + 1] = '\0';
        nueva_pos.fila = pos_actual.fila;
        nueva_pos.columna = pos_actual.columna + 1;
        buscar_ruta(celdas, filas, columnas, nueva_pos, pasos + 1, puntaje, Mejor_solucion,         movimientos_actuales, camino_actual);


        movimientos_actuales[pasos] = 'I';
        movimientos_actuales[pasos + 1] = '\0';
        nueva_pos.fila = pos_actual.fila;
        nueva_pos.columna = pos_actual.columna - 1;
        buscar_ruta(celdas, filas, columnas, nueva_pos, pasos + 1, puntaje, Mejor_solucion,         movimientos_actuales, camino_actual);

        celdas[pos_actual.fila - 1][pos_actual.columna - 1] = valor_original;
    return;
}

void resolver_ruta_mina(const char* ruta_entrada, const char* ruta_salida) {
    Mapa* mapa = cargar_mapa(ruta_entrada);
    if (!mapa) return;

    int capacidad = mapa->filas * mapa->columnas;
    Solucion mejor = { .encontrada = false, .puntaje = -1, .pasos = 0, .movimientos = NULL, .camino = NULL };
    
    char* mov_actuales = malloc((capacidad + 1) * sizeof(char));
    Posicion* camino_actual = malloc(capacidad * sizeof(Posicion));
    if (mov_actuales) mov_actuales[0] = '\0';

    buscar_ruta(mapa->celdas, mapa->filas, mapa->columnas, mapa->inicio, 0, 0, &mejor, mov_actuales, camino_actual);

    FILE* archivo = fopen(ruta_salida, "w");
    if (archivo) {
        if (mejor.encontrada) {
            fprintf(archivo, "PUNTAJE: %d\n", mejor.puntaje);
            fprintf(archivo, "PASOS: %d\n", mejor.pasos);
            fprintf(archivo, "MOVIMIENTOS: %s\n", mejor.movimientos);
            fprintf(archivo, "CAMINO: ");
            for (int i = 0; i < mejor.largo_camino; i++) {
                fprintf(archivo, "(%u,%u)%s", mejor.camino[i].fila, mejor.camino[i].columna, 
                                    (i == mejor.largo_camino - 1) ? "" : " -> ");
            }
            fprintf(archivo, "\n");
        } else {
            fprintf(archivo, "SIN_CAMINO\n");
        }
        fclose(archivo);
    }

    free(mov_actuales);
    free(camino_actual);
    if (mejor.encontrada) {
        free(mejor.movimientos);
        free(mejor.camino);
    }
    for (int i = 0; i < mapa->filas; i++) free(mapa->celdas[i]);
    free(mapa->celdas);
    free(mapa);
}