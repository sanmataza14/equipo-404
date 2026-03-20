#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "repaso.h"

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp) {
    int dx, dy, distanciaAlcuadrado, radioAlcuadrado;
    dx = xp - xc;
    dy= yp - yc;
    distanciaAlcuadrado = (dx * dx) + (dy * dy);
    radioAlcuadrado = (rc * rc);

    if(radioAlcuadrado > distanciaAlcuadrado){
        return INTERNO;
    }
    else if(radioAlcuadrado == distanciaAlcuadrado){
        return EN_CIRCUNFERENCIA;
    }
    else{
        return EXTERNO;
    }
}

bool digitoEnNumero(long n, short d) {
}

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p) {
    int dx, dy, distanciaAlcuadrado, radioAlcuadrado;
    dx = p.x - centroC.x;
    dy = p.y - centroC.y;
    distanciaAlcuadrado = (dx * dx) + (dy * dy);
    radioAlcuadrado = (rc * rc);
    if(radioAlcuadrado > distanciaAlcuadrado){
        return INTERNO;
    }
    else if(radioAlcuadrado == distanciaAlcuadrado){
        return EN_CIRCUNFERENCIA;
    }
    else{
        return EXTERNO;
    }
}

// Función para ordenar jugadores por cantidad de partidos jugados
struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[CANT_JUGADORES]) {
    for (int i = 0; i < CANT_JUGADORES - 1; i++) {
        for (int j = 0; j < CANT_JUGADORES - 1 - i; j++) {
        if (equipo[j].partidosJugados < equipo[j+1].partidosJugados) {
                struct Jugador aux = equipo[j];
                equipo[j] = equipo[j+1];
                equipo[j+1] = aux;
            }
        }
    }
}

// Función para ordenar jugadores por edad
struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[CANT_JUGADORES]) {
    for(int i = 0; i < CANT_JUGADORES - 1; i++){
        for(int j = 0; j < CANT_JUGADORES - 1 - i; j++){
            if(equipo[j].edad > equipo[j+1].edad){
                struct Jugador aux = equipo[j];
                equipo[j] = equipo[j+1];
                equipo[j+1] = aux;
            }
        }
    }
    return equipo;
}

// Función para calcular el promedio de partidos jugados dada una edad
float promedioDePartidosJugados(struct Jugador equipo[CANT_JUGADORES], int edad) {
    int suma_partidos = 0;
    int cant_jugadores = 0;
    int promedio;
    for(int i = 0; i < CANT_JUGADORES; i++){
        if(equipo[i].edad == edad){
            suma_partidos += equipo[i].partidosJugados;
            cant_jugadores += 1;
        }
    }
    if(cant_jugadores > 0){
    promedio = suma_partidos / cant_jugadores;
    return promedio;
    }
    else{
        return 0;
    }
}

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el piso con más habitantes
int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el número de departamentos vacíos
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el promedio de habitantes por departamento
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

void cantidadDeViviendasVaciasPorPiso(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS], int vaciasPorPiso[CANT_PISOS]) {
}

void viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS],
                     Vivienda viviendasVacias[CANT_PISOS * CANT_DEPARTAMENTOS]) {
}

void procesarArchivo(const char *nombreArchivo) {
}
