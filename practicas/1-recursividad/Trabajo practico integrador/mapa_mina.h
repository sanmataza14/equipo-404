#ifndef mapa_mina_h
#define mapa_mina_h

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

Mapa* cargar_mapa(const char* nombre_archivo);
    
#endif 