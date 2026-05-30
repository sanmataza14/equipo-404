# Correcciones — Práctica 4: TAD Pila

**Fecha de corrección:** 2026-05-30
**Referencia evaluada:** `main` @ `92ecc84` (último commit del remoto)
**Repositorio:** `https://github.com/sanmataza14/equipo-404`

> **Nota sobre la referencia evaluada:** no existe un tag específico para esta práctica en el
> repositorio (solo hay `TP-Recursividad` y `TP-Listas`). Siguiendo el criterio de corrección, se
> evaluó la última versión publicada en `origin/main`. Al momento de la corrección, el directorio
> `practicas/4-pilas/` y el TAD `tads/pilas/` **no presentan ningún cambio respecto del commit
> inicial del template** (`bf8cc1c Initial commit`): `git diff bf8cc1c HEAD -- practicas/4-pilas/
> tads/pilas/` no devuelve diferencias. La práctica está sin iniciar.

---

## Integrantes del equipo

Integrantes declarados en el `README.md` de la raíz:

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados |
|---------------------|------------------------|-----------------------|----------------------|-----------------------|
| Simon Claudel       | 0 / 0                  | —                     | 0                    | —                     |
| Mateo Luques        | 0 / 0                  | —                     | 0                    | —                     |
| Santino Mataza      | 0 / 0                  | —                     | 0                    | `sanmataza14`         |

> No hay contribuciones de ningún integrante dentro del alcance de esta práctica
> (`practicas/4-pilas/` y `tads/pilas/`). El único commit que tocó estos archivos es el commit
> inicial del template (`bf8cc1c`), realizado por `sanmataza14 <santinomataza@gmail.com>` (Santino
> Mataza), que únicamente importó el esqueleto provisto por la cátedra. No es trabajo del grupo
> sobre la práctica.

---

## Método aplicado

- Tests del grupo: **No ejecutados** (todos los `main()` de tests están vacíos; no hay nada que ejecutar).
- Tests de cátedra: **No ejecutados** (las implementaciones del TAD son stubs vacíos; el código no
  compilaría/enlazaría con resultado significativo, y no hay implementación contra la cual probar).
- Revisión estática del código: **Sí**.
- Evidencia breve: `git fetch --all --tags --prune` (no hay tag de pilas); `git checkout origin/main`;
  `git diff bf8cc1c HEAD -- practicas/4-pilas/ tads/pilas/` → sin diferencias; lectura directa de
  `tads/pilas/pilas_arreglos.c`, `tads/pilas/pilas_punteros.c`, `practicas/4-pilas/practica_pilas.c`
  y de los 12 tests.

---

## Implementación del TAD Pila

### `pilas_arreglos.c` — Estado: 🚫 NO IMPLEMENTADO

Todas las operaciones núcleo del header están vacías (sin cuerpo): `p_crear`, `p_apilar`,
`p_desapilar`, `p_tope`, `p_es_vacia`, `p_es_llena`, `p_mostrar`. Esto corresponde al esqueleto del
template, sin cambios del grupo.

- La única función con cuerpo es `p_to_string`, que también proviene del template (no es aporte del
  grupo). Además, al depender de un `p_apilar`/`p_crear` no implementados, nunca podría ejecutarse
  sobre una pila válida.
- Las funciones con tipo de retorno (`p_crear`, `p_apilar`, `p_desapilar`, `p_tope`, `p_es_vacia`,
  `p_es_llena`) no retornan ningún valor: es comportamiento indefinido y no compila de forma útil.

### `pilas_punteros.c` — Estado: 🚫 NO IMPLEMENTADO

Mismo estado que la versión de arreglos: `p_crear`, `p_apilar`, `p_desapilar`, `p_tope`,
`p_es_vacia`, `p_es_llena`, `p_mostrar` están vacías. Solo `p_longitud` (rutina interna del
template) y `p_to_string` tienen cuerpo, y ambas son del template.

---

## Resolución de ejercicios

Las 12 funciones de `practica_pilas.c` están vacías (sin cuerpo). Ninguna implementa lo pedido ni
usa el TAD. Todas se reportan como 🚫 **NO IMPLEMENTADO**.

### Ejercicio 1 — `buscarElemento`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 2 — `insertarElemento`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 3 — `eliminarElemento`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 4 — `intercambiarElementos`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 5 — `copiar`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 6 — `contarElementos`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 7 — `compararPilas`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 8 — `cambioDeBase`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 9 — `invertirPila`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 10 — `eliminarTodasOcurrencias`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 11 — `elementosEnComun`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 12 — `eliminarRepetidos`

**Estado: 🚫 NO IMPLEMENTADO** — función con cuerpo vacío.

### Ejercicio 13 — Mazo de cartas españolas (opcional)

**Estado: 😏 NO ENTREGADO** — no hay archivos ni código relacionados con el ejercicio opcional.

---

## Revisión de tests

Los 12 archivos de test contienen únicamente la llamada `imprimir_titulo(...)` y `return 0;`. No
declaran pilas, no invocan ninguna función de la práctica ni del TAD, y no contienen aserciones.

| Test                                  | Estado          | Observaciones                                  |
|---------------------------------------|-----------------|------------------------------------------------|
| `test_01_buscar_elemento.c`           | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_02_insertar_elemento.c`         | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_03_eliminar_elemento.c`         | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_04_intercambiar_elementos.c`    | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_05_copiar_pila.c`               | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_06_contar_elementos.c`          | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_07_comparar_pilas.c`            | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_08_cambio_base.c`               | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_09_invertir_pila.c`             | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_10_eliminar_todas_ocurrencias.c`| 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_11_elementos_en_comun.c`        | 🚫 No entregado | `main` vacío, solo imprime título              |
| `test_12_eliminar_repetidos.c`        | 🚫 No entregado | `main` vacío; además el título dice "elementos en común" (copiado del test 11) |

---

## Resumen

| Categoría | Estado |
|-----------|--------|
| Archivos `.h` sin modificar (contenido) | ✅ (idénticos al commit base; solo el template los tocó) |
| TAD Pila — `pilas_arreglos.c` | 🚫 No implementado |
| TAD Pila — `pilas_punteros.c` | 🚫 No implementado |
| Ejercicio 1 — `buscarElemento` | 🚫 No implementado |
| Ejercicio 2 — `insertarElemento` | 🚫 No implementado |
| Ejercicio 3 — `eliminarElemento` | 🚫 No implementado |
| Ejercicio 4 — `intercambiarElementos` | 🚫 No implementado |
| Ejercicio 5 — `copiar` | 🚫 No implementado |
| Ejercicio 6 — `contarElementos` | 🚫 No implementado |
| Ejercicio 7 — `compararPilas` | 🚫 No implementado |
| Ejercicio 8 — `cambioDeBase` | 🚫 No implementado |
| Ejercicio 9 — `invertirPila` | 🚫 No implementado |
| Ejercicio 10 — `eliminarTodasOcurrencias` | 🚫 No implementado |
| Ejercicio 11 — `elementosEnComun` | 🚫 No implementado |
| Ejercicio 12 — `eliminarRepetidos` | 🚫 No implementado |
| Ejercicio 13 — Mazo de cartas (opcional) | 😏 No entregado |
| Ejercicios correctos | 0 de 12 correctos; 0 con advertencias; 12 no implementados |
| Tests entregados | 0 de 12 |
| Tests con buena cobertura | 0 de 12 |

**Conclusión:** la práctica de pilas no fue iniciada. No hay implementación del TAD en ninguna de
sus dos representaciones, ninguno de los 12 ejercicios obligatorios fue resuelto, y los tests están
vacíos. El directorio se encuentra exactamente igual al template provisto por la cátedra. Para una
nueva instancia de corrección, el grupo debería primero implementar el TAD (`pilas_arreglos.c` y
`pilas_punteros.c`) y luego resolver los ejercicios usando el TAD como caja negra.
