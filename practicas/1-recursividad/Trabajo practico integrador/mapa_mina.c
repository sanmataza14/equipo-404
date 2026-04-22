#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned int fila;
    unsigned int columna;
} Posicion;

typedef struct {
    char **celdas;
    int filas;
    int columnas;
    Posicion inicio;
    Posicion salida;
} Mapa;

Mapa* cargar_mapa(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) return NULL;

    bool encontrado_inicio = false;
    bool encontrado_salida = false;

    Mapa* mapa = malloc(sizeof(Mapa));
    // 1. Leer dimensiones
    fscanf(archivo, "%d %d", &mapa->filas, &mapa->columnas);

    // 2. Reservar los "ganchos" para las filas (char**)
    mapa->celdas = malloc(mapa->filas * sizeof(char*));


    // 3. Reservar cada columna y leer los caracteres
    for (int i = 0; i < mapa->filas; i++) {
       mapa->celdas[i] = malloc((mapa->columnas + 1) * sizeof(char));

       fscanf(archivo, "%s" , mapa->celdas[i]);
    }

    for (int f = 0; f < mapa->filas; f++) {
    for (int c = 0; c < mapa->columnas; c++) {
        if (mapa->celdas[f][c] == 'I') {
        mapa->inicio.fila = f + 1;
        mapa->inicio.columna = c + 1;
        
        encontrado_inicio = true;
            }
        }
    }   

    for (int f = 0; f < mapa->filas; f++) {
    for (int c = 0; c < mapa->columnas; c++) {
        if (mapa->celdas[f][c] == 's') {
        mapa->salida.fila = f + 1;
        mapa->salida.columna = c + 1;

        encontrado_salida = true;
            }
        }
    }  

    fclose(archivo);
    return mapa;
}