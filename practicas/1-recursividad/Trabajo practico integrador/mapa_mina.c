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

typedef struct {
    bool encontrada;
    int puntaje;
    int pasos;
    char *movimientos;
    Posicion *camino;
    int largo_camino;
}Solucion;

Mapa* cargar_mapa(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) return NULL;

    bool encontrado_inicio = false;
    bool encontrado_salida = false;

    Mapa* mapa = malloc(sizeof(Mapa));
    fscanf(archivo, "%d %d", &mapa->filas, &mapa->columnas);

    mapa->celdas = malloc(mapa->filas * sizeof(char*));

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
        if (mapa->celdas[f][c] == 'S') {
        mapa->salida.fila = f + 1;
        mapa->salida.columna = c + 1;

        encontrado_salida = true;
            }
        }
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

int main(){
    Mapa* mapa = cargar_mapa("mapa.txt");
    if (mapa == NULL) return 1;

    int capacidad = mapa->filas * mapa->columnas;

    Solucion mejor = { .encontrada = false, .puntaje = -1 };
    mejor.movimientos = NULL;
    mejor.camino = NULL;

    char* mov_actuales = malloc((capacidad + 1) * sizeof(char));
    Posicion* camino_actual = malloc(capacidad * sizeof(Posicion));
    mov_actuales[0] = '\0';
    
    buscar_ruta(mapa->celdas, mapa->filas, mapa->columnas, mapa->inicio, 0, 0, &mejor, mov_actuales, camino_actual);

    free(mov_actuales);
    free(camino_actual);

    for(int i=0; i < mapa->filas; i++){
        free(mapa->celdas[i]);
    }
    free(mapa->celdas);
    free(mapa);

    if(mejor.encontrada){
        free(mejor.movimientos);
        free(mejor.camino);
    }

    return 0;   
}