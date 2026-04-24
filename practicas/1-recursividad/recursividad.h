#ifndef RECURSIVIDAD_H
#define RECURSIVIDAD_H

#include <stdbool.h>


bool esCapicua(int numero);

bool esPalindromo(char *palabra);

int productoRecursivo(int m, int n);

int terminoSerieDeFibonacci(int n);

int restoRecursivo(int dividendo, int divisor);

char *agregarSeparadorMiles(char *numero);

char *chinos(unsigned int nivel);

char *ondaDigital(char *);

bool esDivisiblePor7(int n);

int *explosion(int n, int b, int *size);


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

Mapa* cargar_mapa(const char* nombre_archivo);

void buscar_ruta(char** celdas, int filas, int columnas, Posicion pos_actual, int pasos, int puntaje, Solucion* Mejor_solucion, char* movimientos_actuales, Posicion* camino_actual);
    
void resolver_ruta_mina(const char* ruta_entrada, const char* ruta_salida);

#endif // RECURSIVIDAD_H
