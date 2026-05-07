# Correcciones — TP Integrador de Recursividad: Ruta de Rescate en Mina

**Fecha de corrección:** 2026-05-06
**Referencia evaluada:** `main` (commit `a40627f` — "correciones"). El tag original `TP-Recursividad` (commit `524de61`) contenía errores de compilación en el test del integrador, corregidos en el commit posterior incluido en `main`.
**Repositorio:** https://github.com/sanmataza14/equipo-404

> Este reporte corrige exclusivamente el TP integrador "Ruta de Rescate en Mina". La práctica general de recursividad se evalúa en un reporte separado (ver `CORRECCIONES.md`).

---

## Integrantes del equipo

Integrantes declarados en `README.md`:

- Simon Claudel
- Mateo Luques
- Santino Mataza

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados |
|---------------------|-------------------------|-----------------------|----------------------|------------------------|
| Santino Mataza      | +550 / -199             | 52.60 %               | 5                    | `Santino Mataza <santinomataza@gmail.com>`, `sanmataza14 <santinomataza@gmail.com>` |
| Simon Claudel       | +269 / -61              | 23.17 %               | 7                    | `SimonClaudel <simonclaudel2006@gmail.com>` |
| Mateo Luques        | +202 / -2               | 14.33 %               | 2                    | `Luques52 <matuteluke777@gmail.com>` |
| *(committer no-integrante)* Mariano Goldman | +141 / -0 | 9.90 % | 1 | `Mariano Goldman <mariano.goldman@puntodev.com.ar>` (corresponde al docente; no es integrante del equipo) |

Notas:

- El alcance de medición es `practicas/1-recursividad/` y mezcla líneas de la práctica general y del TP integrador (ambos viven en la misma carpeta y los mismos archivos `recursividad.c`/`recursividad.h`). Los porcentajes son **estimados aproximados**, no atribuibles solo al TP integrador.
- Mapeo aplicado: `sanmataza14` se unificó con `Santino Mataza` por mismo email; `SimonClaudel` y `Luques52` se unificaron por handle/apellido evidente. `Mariano Goldman` no se mapea a ningún integrante: se reporta como observación (committer del docente, fuera del equipo).

---

## Método aplicado

- Tests del grupo: **Ejecutados**.
- Tests de cátedra: **No ejecutados** como suite (la cátedra usa otra estructura de tests con structs distintos), pero **se corrió la implementación del grupo contra una entrada de cátedra** (`ruta_mina_prueba1_entrada.txt`) para comparar la salida.
- Revisión estática del código: **Sí**.
- Comparación de formato de salida del grupo vs enunciado/cátedra: **Sí**.
- Evidencia breve:
  - `cmake --build cmake-build-debug --target test_tp_ruta_mina` → compila sin errores en `main`. En el tag original había errores por `#include` faltantes (`<string.h>`, `recursividad.h`); el commit `a40627f` los corrigió y agregó normalización de `\r\n` línea a línea en `file_eq`.
  - `./test_tp_ruta_mina` → los 4 tests del grupo pasan (`Test 1: PASO`, `Test 2: PASO`, `Test 3: PASO`, `Test 4: PASO`).
  - Se ejecutó `resolver_ruta_mina` sobre la entrada de cátedra `ruta_mina_prueba1_entrada.txt` y se comparó con `ruta_mina_prueba1_salida_esperada.txt`. La lógica produce los mismos `PUNTAJE`, `PASOS`, `MOVIMIENTOS` y `CAMINO`, pero **falta la línea inicial `RESULTADO: ENCONTRADO`** que pide el enunciado.
  - Enunciado leído por `WebFetch` desde `https://unlu-prog-2.github.io/practicas/TP_ruta_de_rescate.html`.

---

## Corrección de la práctica

### `cargar_mapa(const char* nombre_archivo)`

**Estado: ⚠️ ADVERTENCIA**

Implementa la carga: lee dimensiones, asigna celdas y detecta `I`/`S` durante la lectura. El uso de `fscanf(archivo, " %c", ...)` con espacio inicial permite leer indistintamente formatos con y sin separadores entre celdas.

Faltan validaciones de entrada inválida que los criterios de corrección del integrador exigen:

- No valida `filas` y `columnas` `<= 0` ni que las líneas leídas tengan exactamente `columnas` caracteres.
- No valida que existan exactamente un `I` y exactamente una `S`. Si el archivo tiene 0 o múltiples instancias, la función no lo detecta.
- No valida el alfabeto de celdas (acepta cualquier carácter, no solo `I`, `S`, `#`, `.`, `0-9`).
- Si `malloc` falla en `mapa->celdas` o en alguna fila, no libera lo ya reservado.

Cómo mejorar: validar dimensiones; verificar conteo de `I`/`S` al final de la lectura; rechazar caracteres no pertenecientes al alfabeto definido; en error, `fclose` + `free` parcial y devolver `NULL`.

### `buscar_ruta(...)`

**Estado: ✅ CORRECTO**

La recursión está bien estructurada y respeta el orden lexicográfico de movimientos (`A`, `B`, `D`, `I`) en las llamadas. Maneja correctamente:

- el corte por celda fuera de la grilla (`fila/columna` fuera de rango),
- el bloqueo en celdas `#`,
- el "no repetir celda" mediante marca temporal `'X'` y restauración con `valor_original` al volver de la recursión — es una solución limpia y muy alineada con el espíritu de backtracking de la práctica,
- la suma de puntaje al pasar por dígitos `0-9`,
- la copia profunda de `movimientos` y `camino` cuando se mejora la solución.

El criterio de "mejor ruta" se cumple en los tres niveles (puntaje > pasos > lexicográfico) en los casos probados, incluido `prueba4` con empate por puntaje y pasos.

Sugerencias (no degradan el estado):

- El desempate lexicográfico está implementado de forma implícita: el DFS en orden `A, B, D, I` encuentra primero la secuencia lexicográficamente menor y la condición `pasos <` (no `<=`) la conserva. Funciona, pero deja la corrección dependiente del orden de exploración. Hacer explícito el desempate (`puntaje == best && pasos == best && strcmp(movimientos, best.movimientos) < 0`) lo vuelve robusto frente a cambios futuros del recorrido.
- La condición compuesta `!encontrada || puntaje > best.puntaje || puntaje == best.puntaje && pasos < best.pasos` no usa paréntesis explícitos. La precedencia de `&&` sobre `||` da el comportamiento esperado, pero por legibilidad conviene escribir `... || (puntaje == best && pasos < best.pasos)`.
- La firma de la función tiene 9 parámetros; la legibilidad y mantenimiento se beneficiarían de empaquetar el contexto de búsqueda en un struct.

### `resolver_ruta_mina(const char* ruta_entrada, const char* ruta_salida)`

**Estado: ❌ INCORRECTO**

Motivo principal (formato de salida):

El enunciado oficial y los archivos de cátedra exigen que la salida comience con la línea:

```
RESULTADO: ENCONTRADO
```

cuando hay camino, o exclusivamente:

```
RESULTADO: SIN_CAMINO
```

cuando no hay camino. La implementación del grupo **omite la línea `RESULTADO:` en ambos casos** y emite directamente `PUNTAJE:` / `PASOS:` / etc., o `SIN_CAMINO\n` (sin el prefijo `RESULTADO: `). Esto incumple el formato exacto pedido por la cátedra.

Verificación concreta: corriendo `resolver_ruta_mina` con la entrada de cátedra `ruta_mina_prueba1_entrada.txt`, el grupo produce los mismos `PUNTAJE: 3`, `PASOS: 4`, `MOVIMIENTOS: DDBD`, `CAMINO: ...` que `ruta_mina_prueba1_salida_esperada.txt`, pero falta la línea `RESULTADO: ENCONTRADO`. Una verificación con `file_eq` línea a línea contra los archivos de cátedra falla por esa razón.

Los archivos `archivos/prueba*_esperado.txt` del propio grupo replican este formato incompleto, por lo que sus assertions **pasan contra su propio formato erróneo** pero fallarían contra cualquier verificación de cátedra. Por los criterios de corrección, este punto cae directamente en *"No genera el formato de salida esperado (líneas, etiquetas o coordenadas en base 1 incorrectas)"* → **ERROR / INCORRECTO**.

Otras observaciones (manejo de memoria y errores):

- Si `cargar_mapa` retorna `NULL`, `resolver_ruta_mina` retorna sin abrir el archivo de salida. Por los criterios de corrección, el caso de "entrada inválida" debería igualmente generar `RESULTADO: SIN_CAMINO` (o equivalente) en el archivo de salida, no quedarse mudo.
- No verifica que `malloc` de `mov_actuales` o `camino_actual` haya tenido éxito antes de pasarlos a `buscar_ruta` (solo `if (mov_actuales) mov_actuales[0] = '\0';` — no hay early-return).
- El tamaño de `mov_actuales` es `capacidad + 1`, lo que tolera la peor secuencia, pero el cálculo no aparece comentado y la relación `largo_camino = pasos + 1` y `pasos <= filas*columnas - 1` queda implícita.
- La liberación de memoria al final está completa para el caso donde `cargar_mapa` no falla; cubre `mov_actuales`, `camino_actual`, `mejor.movimientos`, `mejor.camino`, `mapa->celdas[i]`, `mapa->celdas`, `mapa`. Bien.

Cómo arreglar (mínimo):

1. Reemplazar la rama de salida en `resolver_ruta_mina` por:
   ```c
   if (mejor.encontrada) {
       fprintf(archivo, "RESULTADO: ENCONTRADO\n");
       fprintf(archivo, "PUNTAJE: %d\n", mejor.puntaje);
       /* ... resto igual ... */
   } else {
       fprintf(archivo, "RESULTADO: SIN_CAMINO\n");
   }
   ```
2. Cuando `cargar_mapa` falla, abrir `ruta_salida` y escribir `RESULTADO: SIN_CAMINO\n`.
3. Regenerar todos los `archivos/prueba*_esperado.txt` para que reflejen el formato correcto.

---

## Revisión de tests

| Test                          | Estado          | Observaciones                                                                                                                                              |
|-------------------------------|-----------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `test_tp_ruta_mina.c`         | ⚠️ Incompleto   | Compila y los 4 tests pasan en `main`. Cubre los 4 casos clave (camino válido, sin camino, empate por pasos, empate lex). El problema es que los `_esperado.txt` no reflejan el formato pedido por el enunciado: los tests del grupo verifican una salida sin línea `RESULTADO:`. Adicionalmente, `file_eq` ahora normaliza `\r\n` línea a línea, lo que tolera diferencias de fin de línea pero no detecta otras desviaciones de formato. |

### Cobertura por tipo de caso (criterios del integrador)

- ✅ caso con camino válido (`prueba1.txt`)
- ✅ caso sin camino (`prueba2.txt`)
- ✅ empate por puntaje resuelto por pasos (`prueba3.txt`)
- ✅ empate por puntaje y pasos resuelto lexicográficamente (`prueba4.txt`)
- ✅ comparación de salida por archivo completo (`file_eq` línea a línea)

La cobertura conceptual es buena. El problema real es que los `_esperado.txt` están escritos contra un formato que no es el de cátedra/enunciado.

---

## Resumen

| Categoría                                  | Estado |
|--------------------------------------------|--------|
| Archivos `.h` sin modificar (contenido)    | ⚠️ Modificado: se agregaron tipos (`Posicion`, `Mapa`, `Solucion`) y funciones (`cargar_mapa`, `buscar_ruta`, `resolver_ruta_mina`) requeridos por el TP. Las firmas de la práctica general no se tocaron. Los criterios del integrador no exigen no modificar el `.h`; se registra como observación, no como error crítico. |
| `cargar_mapa()`                            | ⚠️ Advertencia (validaciones de entrada incompletas) |
| `buscar_ruta()`                            | ✅ Correcto (sugerencias: hacer explícito el desempate lex; paréntesis en la condición compuesta; reducir la cantidad de parámetros) |
| `resolver_ruta_mina()`                     | ❌ Incorrecto (omite línea `RESULTADO:` exigida por enunciado; no escribe en salida cuando `cargar_mapa` falla) |
| Tests entregados (caso válido / sin camino / empate por pasos / empate lex / `file_eq`) | 4 de 4 entregados; los 4 pasan en `main`, pero contra `_esperado.txt` con formato incorrecto |
| Tests con buena cobertura de casos         | ⚠️ Cobertura conceptual buena; formato de los esperados no concuerda con el pedido |
| Compilación de los tests del grupo         | ✅ Compila y corre en `main` (corregido post-tag con los `#include` faltantes y normalización de `\r\n`) |
