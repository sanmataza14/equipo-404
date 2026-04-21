# Correcciones — Práctica 1: Recursividad

**Fecha de corrección:** 2026-04-20
**Tag/Branch evaluado:** `main`
**Repositorio:** `sanmataza14/equipo-404`

---

## Integrantes del equipo

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados |
|---------------------|-------------------------|-----------------------|----------------------|------------------------|
| Santino Mataza      | +2930/-0                | 93.25%                | 5                    | Santino Mataza, sanmataza14 |
| Mateo Luques        | +112/-2                 | 3.63%                 | 1                    | Luques52 |
| Simon Claudel       | +96/-2                  | 3.12%                 | 4                    | SimonClaudel |

Alias unificados por nombre/email: `sanmataza14` -> `Santino Mataza`, `Luques52` -> `Mateo Luques`, `SimonClaudel` -> `Simon Claudel`.

---

## Método aplicado

- Tests del grupo: Ejecutados
- Tests de cátedra: No ejecutados
- Revisión estática del código: Sí
- Evidencia breve: `git checkout main`; comparación de headers contra el commit base `bf8cc1c18458c27578f77f348526864fb815e351`; `cmake -S <repo> -B <build-dir>`; `cmake --build <build-dir>`; la suite completa no compiló por `test_mafia_china.c` (falta `#include <string.h>`), por lo que se ejecutaron manualmente los binarios generados: `test_capicua`, `test_divisible_por_7`, `test_explosion`, `test_fibonacci`, `test_onda_digital`, `test_palindromos`, `test_producto`, `test_resto`, `test_separador_miles`.

---

## Corrección de la práctica

### Ejercicio 1 — `esCapicua()`

**Estado: ✅ CORRECTO**

La función usa recursión real, compara correctamente primera y última cifra, y reduce el problema al centro del número. Para los casos esperados del TP el comportamiento es correcto.

### Ejercicio 2 — `esPalindromo()`

**Estado: ❌ INCORRECTO**

La idea recursiva está bien encaminada, pero la implementación modifica la cadena recibida (`palabra[largo - 1] = '\0'`). Eso vuelve peligrosa la función para el uso esperado en el enunciado, donde se muestran llamadas con strings literales. En una verificación puntual con `esPalindromo("neuquen")` la ejecución rompe por escribir sobre memoria no modificable.

### Ejercicio 3 — `productoRecursivo()`

**Estado: ✅ CORRECTO**

La solución es recursiva, contempla bien signos y caso base `n == 0`, y avanza en cada llamada hacia el caso base. Resuelve correctamente lo pedido como sumas sucesivas.

### Ejercicio 4 — `terminoSerieDeFibonacci()`

**Estado: ✅ CORRECTO**

La implementación tiene casos base correctos y paso recursivo correcto. Es una solución adecuada para el objetivo de la práctica; no se penaliza complejidad alta en este TP.

### Ejercicio 5 — `restoRecursivo()`

**Estado: ⚠️ MEJORA OPCIONAL**

Para los casos normales y con signos usados en la práctica devuelve el resultado correcto mediante restas sucesivas. Como mejora importante, falta contemplar `divisor == 0`: en ese caso la recursión no converge.

### Ejercicio 6 — `agregarSeparadorMiles()`

**Estado: ⚠️ MEJORA OPCIONAL**

La función resuelve correctamente los ejemplos del enunciado y usa recursión sobre la parte izquierda del string. La parte mejorable es la robustez: usa un buffer fijo `char restoAMedias[100]`, lo que vuelve frágil la solución para entradas más largas de lo esperado.

### Ejercicio 7 — `chinos()`

**Estado: ⚠️ MEJORA OPCIONAL**

Para niveles válidos de la práctica la construcción recursiva es correcta y genera la forma pedida. Como mejora, falta contemplar `nivel == 0`; con el tipo `unsigned int` eso provoca una llamada recursiva inválida por underflow.

### Ejercicio 8 — `ondaDigital()`

**Estado: ✅ CORRECTO**

La solución usa recursión real, conserva el orden de la señal y agrega separadores verticales cuando hay transición entre niveles. En los casos probados devuelve la representación esperada por los tests entregados.

### Ejercicio 9 — `esDivisiblePor7()`

**Estado: ❌ INCORRECTO**

Aunque el cálculo implementado devuelve resultados correctos en los casos básicos, el ejercicio pedía resolverlo de forma recursiva y acá se usa un `while`. En esta práctica la presencia real de recursión es un criterio central, por lo que así no cumple el objetivo pedagógico del ejercicio.

### Ejercicio 10 — `explosion()`

**Estado: ❌ INCORRECTO**

La función funciona para los ejemplos entregados, pero el paso recursivo no siempre converge. Con `b = 1`, por ejemplo, `n1 = n / b` vuelve a ser `n` y la llamada recursiva entra en un ciclo que termina rompiendo la ejecución. En esta práctica eso es un defecto importante porque el avance hacia el caso base debe quedar garantizado.

---

## Revisión de tests

| Test | Estado | Observaciones |
|------|--------|---------------|
| `test_capicua.c` | ⚠️ Incompleto | Llama a la función correcta y cubre casos nominales, pero falta borde como una cifra o número negativo. |
| `test_palindromos.c` | ⚠️ Incompleto | Verifica un caso verdadero y uno falso, pero no cubre string vacío, longitud 1 ni el uso con literal como en el enunciado. |
| `test_producto.c` | ⚠️ Incompleto | Cubre signos positivos y negativos, pero falta el caso borde `n == 0`. |
| `test_fibonacci.c` | ⚠️ Incompleto | Tiene un caso base y uno recursivo, pero falta borde con `n <= 0`. |
| `test_resto.c` | ⚠️ Incompleto | Cubre signos, pero falta el caso `dividendo < divisor` y no prueba `divisor == 0`. |
| `test_separador_miles.c` | ⚠️ Incompleto | Solo cubre dos casos nominales; falta string corto (sin separadores) y longitudes más variadas. |
| `test_mafia_china.c` | ⚠️ Incompleto | No compila por faltar `#include <string.h>` para `strcmp`; además solo cubre un caso nominal. |
| `test_onda_digital.c` | ⚠️ Incompleto | Tiene buena variedad de transiciones, pero falta string vacío y señal de un solo carácter. |
| `test_divisible_por_7.c` | ⚠️ Incompleto | Prueba un múltiplo y un no múltiplo, pero no cubre negativos ni valores menores a 70. |
| `test_explosion.c` | ⚠️ Incompleto | Verifica dos casos recursivos útiles, pero falta el caso base `n <= b` y un borde como `b == 1`. |

### Tests con casos de borde faltantes

- `test_capicua.c`: no prueba una sola cifra ni valores negativos.
- `test_palindromos.c`: no prueba string vacío, longitud 1 ni literal de solo lectura.
- `test_producto.c`: no prueba multiplicación por cero.
- `test_fibonacci.c`: no prueba `n == 0` ni valores negativos.
- `test_resto.c`: no prueba `dividendo < divisor` ni `divisor == 0`.
- `test_separador_miles.c`: no prueba strings de hasta 3 dígitos.
- `test_mafia_china.c`: no prueba `nivel == 1` y además no compila.
- `test_onda_digital.c`: no prueba string vacío ni una sola señal.
- `test_divisible_por_7.c`: no prueba negativos ni múltiplos chicos como `14`.
- `test_explosion.c`: no prueba el caso base ni el borde `b == 1`.

---

## Resumen

| Categoría | Estado |
|-----------|--------|
| Archivos `.h` sin modificar (contenido) | ✅ |
| `esCapicua` | ✅ Correcto |
| `esPalindromo` | ❌ Incorrecto |
| `productoRecursivo` | ✅ Correcto |
| `terminoSerieDeFibonacci` | ✅ Correcto |
| `restoRecursivo` | ⚠️ Mejora opcional |
| `agregarSeparadorMiles` | ⚠️ Mejora opcional |
| `chinos` | ⚠️ Mejora opcional |
| `ondaDigital` | ✅ Correcto |
| `esDivisiblePor7` | ❌ Incorrecto |
| `explosion` | ❌ Incorrecto |
| Ejercicios correctos | 4 de 10 correctos; 3 con mejoras opcionales; 3 incorrectos |
| Tests entregados | 10 de 10 |
| Tests con buena cobertura | 0 de 10 |
