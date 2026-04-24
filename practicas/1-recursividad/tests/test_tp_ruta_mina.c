#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool file_eq(const char *archivo_esperado, const char *archivo_generado) {
    FILE *esperado = fopen(archivo_esperado, "r");
    FILE *generado = fopen(archivo_generado, "r");

    if (!esperado || !generado) {
        if (esperado) fclose(esperado);
        if (generado) fclose(generado);
        return false;
    }

    char linea_esperada[256];
    char linea_generada[256];
    bool son_iguales = true;

    while (fgets(linea_esperada, sizeof(linea_esperada), esperado) != NULL) {
        if (fgets(linea_generada, sizeof(linea_generada), generado) == NULL) {
            son_iguales = false;
            break;
        }

        if (strcmp(linea_esperada, linea_generada) != 0) {
            son_iguales = false;
            break;
        }
    }

    if (fgets(linea_generada, sizeof(linea_generada), generado) != NULL) {
        son_iguales = false;
    }

    fclose(esperado);
    fclose(generado);
    return son_iguales;
}

int main() {
    printf("Iniciando pruebas del TP...\n");

    // Prueba 1: Camino directo
    resolver_ruta_mina("archivos/prueba1.txt", "archivos/prueba1_salida.txt");
    assert(file_eq("archivos/prueba1_esperado.txt", "archivos/prueba1_salida.txt"));
    printf("Test 1: PASO \n");

    // Prueba 2: Sin salida posible
    resolver_ruta_mina("archivos/prueba2.txt", "archivos/prueba2_salida.txt");
    assert(file_eq("archivos/prueba2_esperado.txt", "archivos/prueba2_salida.txt"));
    printf("Test 2: PASO \n");

    // Prueba 3: Empate en puntaje, desempate por pasos
    resolver_ruta_mina("archivos/prueba3.txt", "archivos/prueba3_salida.txt");
    assert(file_eq("archivos/prueba3_esperado.txt", "archivos/prueba3_salida.txt"));
    printf("Test 3: PASO \n");

    // Prueba 4: Empate en puntaje y pasos, desempate lexicográfico (A-B-D-I)
    resolver_ruta_mina("archivos/prueba4.txt", "archivos/prueba4_salida.txt");
    assert(file_eq("archivos/prueba4_esperado.txt", "archivos/prueba4_salida.txt"));
    printf("Test 4: PASO \n");

    printf("Todos los tests pasaron con exito! \n");
    return 0;
}