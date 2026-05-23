# Correcciones — Práctica 3: TAD Lista

> **Nota importante sobre la referencia evaluada:** El equipo **no creó un tag** específico para la entrega de la práctica 3 (Listas). Se evaluó la última versión publicada en `origin/main` (commit `3e498de` — *"puntos evaluar y valores completos"*).

**Fecha de corrección:** 2026-05-23
**Referencia evaluada:** `origin/main` @ `3e498de` (detached HEAD)
**Repositorio:** `https://github.com/sanmataza14/equipo-404`

---

## Integrantes del equipo

Integrantes declarados en `README.md`:

- Simon Claudel
- Mateo Luques
- Santino Mataza

Contribuciones sobre el alcance evaluado (`practicas/3-listas/` y `tads/listas/`):

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados                                |
|---------------------|------------------------|-----------------------|----------------------|------------------------------------------------------|
| Santino Mataza      | +1199/-40              | 63.15%                | 4                    | `sanmataza14 <santinomataza@gmail.com>`, `Santino Mataza <santinomataza@gmail.com>` |
| Mateo Luques        | +355/-256              | 31.14%                | 4                    | `Luques52 <matuteluke777@gmail.com>`                 |
| Simon Claudel       | +104/-8                | 5.71%                 | 3                    | `SimonClaudel <simonclaudel2006@gmail.com>`          |

Notas sobre mapeo: el committer `sanmataza14` y `Santino Mataza` comparten el mismo email (`santinomataza@gmail.com`) y se unificaron como una sola persona.

---

## Método aplicado

- Tests del grupo: **No ejecutados** (no se compilaron en esta corrección; revisión por lectura).
- Tests de cátedra: **No ejecutados** (no se aplicaron tests externos a la entrega; el TAD entregado no compilaría completo por funciones faltantes).
- Revisión estática del código: **Sí** (lectura de los tres `.c` del TAD, del `practica_listas.c` y de los 12 tests).
- Evidencia breve: lectura de `tads/listas/listas_arreglos.c`, `listas_punteros.c`, `listas_cursores.c`, `practicas/3-listas/practica_listas.c`, todos los archivos en `practicas/3-listas/tests/`. Diff contra el primer commit (`bf8cc1c`) para verificar headers de cátedra. Conteo de líneas y commits por autor con `git log --no-merges --numstat` sobre el alcance.

---

## Verificación de headers de cátedra

- `tads/listas/listas.h`: **IDENTICO** al primer commit.
- `tads/listas/util_listas.h`: **IDENTICO** al primer commit.
- `practicas/3-listas/practica_listas.h`: **CAMBIO_REAL** — se agregó la declaración `Lista invertirListaRec(Iterador iter);` (junto con el cambio de un comentario). Es una **extensión** del header de la práctica (no de un header del TAD `tads/listas/`); se trata como ⚠️ **ADVERTENCIA**: la firma adicional es necesaria para exponer la variante recursiva del ejercicio 2, pero los headers entregados por la cátedra no deberían modificarse. Lo correcto era declararla como auxiliar en el `.c` o consultarlo con la cátedra.

No hubo modificaciones al contenido de `listas.h` ni de `util_listas.h`, que son los headers del TAD propiamente dicho.

---

## Implementación del TAD Lista (Ejercicio 1)

> Las **tres** representaciones presentan el mismo patrón: tienen implementadas `l_crear`, `l_es_vacia`, `l_es_llena`, `l_agregar`, `l_insertar`, `l_to_string`, `iterador`, `hay_siguiente`, `siguiente`, pero dejan en blanco (cuerpo vacío) las operaciones `l_longitud`, `l_borrar`, `l_buscar`, `l_eliminar`, `l_recuperar` y `l_mostrar`. En C, eso significa que esas funciones devuelven valores indefinidos (UB) cuando se las invoca; en particular, ninguno de los ejercicios del Bloque B podría apoyarse en `l_recuperar` o `l_longitud`.

### `listas_arreglos.c` — Estado: ❌ INCORRECTO

- Operaciones afectadas:
    - `l_longitud`: cuerpo vacío (no retorna nada). Comportamiento indefinido.
    - `l_borrar(Lista, int clave)`: cuerpo vacío.
    - `l_buscar(Lista, int clave)`: cuerpo vacío.
    - `l_eliminar(Lista, int pos)`: cuerpo vacío. Crítica para el TAD.
    - `l_recuperar(Lista, int pos)`: cuerpo vacío. Crítica para los ejercicios del Bloque B que pudieran usarla.
    - `l_mostrar(Lista)`: cuerpo vacío.
- Operaciones que sí funcionan: `l_crear`, `l_es_vacia`, `l_es_llena`, `l_agregar`, `l_insertar`, `l_to_string`, `iterador`, `hay_siguiente`, `siguiente`. El recorrido por iterador es correcto y soporta el resto de los ejercicios.
- Sugerencias:
    - Definir `TAMANIO_MAXIMO` como `#define` o documentarlo, ya que limita la lista a 1000 elementos sin posibilidad de redimensionar.
    - `l_to_string` accede a `lista->valores[i]->clave` asumiendo que `TipoElemento` es un puntero a struct con `clave` int. Eso ya rompe la abstracción del `TipoElemento`, pero al ser provisto por la cátedra es aceptable.

### `listas_punteros.c` — Estado: ❌ INCORRECTO

- Operaciones afectadas (mismo patrón que arreglos):
    - `l_longitud`, `l_borrar`, `l_buscar`, `l_eliminar`, `l_recuperar`, `l_mostrar`: todas con cuerpo vacío.
- Operaciones que sí funcionan: `l_crear`, `l_es_vacia`, `l_es_llena`, `l_agregar` (con recorrido O(n) hasta el final, correcto), `l_insertar`, `l_to_string`, `iterador`, `hay_siguiente`, `siguiente`.
- Sugerencias:
    - `l_es_llena` no protege contra `lista == NULL`; los otros sí.
    - El `l_to_string` no libera el iterador interno (no usa iterador, recorre `lista->inicio` directamente, lo cual es válido al ser implementación interna).
    - Mantener una referencia al último nodo en `ListaRep` permitiría que `l_agregar` sea O(1), sin romper la abstracción.

### `listas_cursores.c` — Estado: ❌ INCORRECTO

- Operaciones afectadas (mismo patrón):
    - `l_longitud`, `l_borrar`, `l_buscar`, `l_eliminar`, `l_recuperar`, `l_mostrar`: todas con cuerpo vacío.
- Operaciones que sí funcionan: `l_crear` (inicializa correctamente la lista de slots libres encadenando `siguiente = i+1`), `l_es_vacia`, `l_es_llena` (chequea `libre == NULO`, válido), `l_agregar`, `l_insertar`, `l_to_string`, `iterador`, `hay_siguiente`, `siguiente`.
- Sugerencias:
    - `l_agregar` recorre toda la lista lógica para encontrar el último cursor. Mantener un cursor `fin` en `ListaRep` lo haría O(1).
    - La inicialización de los slots libres en `l_crear` es prolija y respeta la convención de cursores.
    - Al **no implementar** `l_eliminar`/`l_borrar`, los slots nunca se devuelven a la lista de libres en uso real: el TAD nunca podría reciclar memoria.

> **Conclusión del Bloque A:** las tres implementaciones del TAD están **incompletas en operaciones núcleo** (`l_eliminar`, `l_recuperar`, `l_longitud`, `l_borrar`, `l_buscar`, `l_mostrar`). Las partes implementadas son correctas y permiten **construir** listas y **recorrerlas por iterador**, que es lo que el código del Bloque B termina necesitando en la práctica — por eso los ejercicios funcionan parcialmente a pesar del estado del TAD. Pero como entrega del Ejercicio 1 del TP, las tres representaciones quedan ❌ INCORRECTO porque no completan el contrato del header.

---

## Resolución de ejercicios

### Ejercicio 2 — `invertirLista`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **ambas** (iterativa `invertirLista` y recursiva `invertirListaRec`).
- Implementación revisada:
    - Iterativa: crea una nueva lista y va insertando cada elemento en la posición 1, lo cual efectivamente invierte el orden. Correcto.
    - Recursiva: consume el iterador, llama recursivamente y luego agrega el elemento al final de la lista resultante. El resultado queda invertido correctamente.
- Análisis de complejidad (TAD ideal): el grupo **no presenta análisis escrito**. Asumiendo `l_insertar` O(1), la iterativa es O(n); la recursiva es O(n) en llamadas y O(n) en `l_agregar` ideal.
- Análisis de complejidad (TAD real): para la versión iterativa, `l_insertar(nueva, te, 1)` en punteros y cursores es O(1) (insertar al inicio), por lo que queda O(n). En arreglos `l_insertar(.., 1)` requiere correr todos los elementos: O(n²) en arreglos. La versión recursiva con `l_agregar` al final cuesta O(n²) en punteros y cursores tal como están implementados (recorren hasta el final cada vez).
- Casos borde: lista vacía (devuelve una lista vacía) y un único elemento están cubiertos.
- Sugerencias: incluir el análisis de complejidad escrito y diferenciar costo en arreglos vs. punteros/cursores. La declaración de `invertirListaRec` se agregó en `practica_listas.h` (ver advertencia arriba).

### Ejercicio 3 — `menorYPosicion`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **iterativa**.
- Implementación revisada: usa el iterador, toma el primer elemento como mínimo inicial (posición 1) y recorre el resto comparando. Devuelve `{0, 0}` si la lista está vacía, lo cual es razonable como sentinela.
- Análisis de complejidad (TAD ideal): no presentado. Es O(n).
- Análisis de complejidad (TAD real): O(n) usando iterador, en las tres representaciones.
- Casos borde: lista vacía (devuelve `{0,0}`) y un solo elemento están cubiertos.
- Sugerencias: documentar el análisis. Considerar si `{0,0}` es un sentinela válido cuando la lista contiene un 0 con ordinal 0; podría devolverse `{0, -1}` o documentarlo.

### Ejercicio 4 — `mayorYOcurrencias`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **iterativa**.
- Implementación revisada: toma el primer elemento como máximo (ocurrencias=1) y recorre actualizando el máximo y el contador. Correcto en lista no vacía. Devuelve `{0,0}` si vacía.
- Análisis de complejidad (TAD ideal): no presentado. Es O(n).
- Análisis de complejidad (TAD real): O(n) en las tres representaciones (uso correcto del iterador).
- Casos borde: lista vacía (manejada con `l_es_vacia`), un solo elemento (correcto), todos iguales (cubierto: contador suma).
- Sugerencias: documentar el análisis.

### Ejercicio 5 — `promedio`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **recursiva** (a través de la auxiliar `promedioRecAux`, invocada desde la función pública iterativa que solo prepara el iterador).
- Implementación revisada: la auxiliar recibe el iterador y dos punteros (`suma` y `contador`) y avanza recursivamente. Correcto. Lista vacía devuelve 0.0 (evita división por cero).
- Análisis de complejidad (TAD ideal): no presentado. Es O(n) en llamadas recursivas.
- Análisis de complejidad (TAD real): O(n) usando iterador.
- Casos borde: lista vacía manejada explícitamente.
- Sugerencias: documentar el análisis. La recursión consume pila O(n); si se quisiera procesar listas muy grandes podría desbordar.

### Ejercicio 6 — `multiplos`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **iterativa**.
- Implementación revisada: itera sobre `l`, multiplica cada `clave` por `n` y agrega un nuevo `TipoElemento` a la lista resultado. Maneja `l` vacía y `n=0`.
- Análisis de complejidad (TAD ideal): no presentado. Es O(n).
- Análisis de complejidad (TAD real): O(n) en punteros y cursores depende de cómo se implemente `l_agregar`: en esta entrega `l_agregar` de punteros/cursores recorre hasta el final → cada `l_agregar` es O(n), total O(n²). En arreglos, O(n).
- Casos borde: vacía y `n=0` cubiertos. Si `n=0`, el código corta antes de iterar y devuelve lista vacía — eso difiere de "lista de tantos ceros como elementos tenga `l`"; cuál de las dos es la interpretación correcta depende del enunciado. Marcamos esto como observación, no como error.
- Sugerencias: documentar el análisis; explicar la decisión de cortocircuitar con `n=0`.

### Ejercicio 7 — `numerosAlAzar`

**Estado: 🚫 NO IMPLEMENTADO**

- Modalidad entregada: ninguna. La función no aparece en `practica_listas.c` (sí está declarada en el header).
- Test `test_lista_azar.c`: solo imprime el título, no ejerce ninguna función.
- Comentarios: el ejercicio pide una lista de `cantidad` números al azar **únicos**. No hay implementación.

### Ejercicio 8 — `reflejarLista`

**Estado: ✅ CORRECTO**

- Modalidad entregada: **iterativa**.
- Implementación revisada: copia los elementos de `l` a `nueva`, invierte `l` con `invertirLista`, y agrega los elementos invertidos. Si `ultimoDoble == false`, descarta el primero del invertido (que es el último del original) para no duplicarlo. Correcto.
- Análisis de complejidad (TAD ideal): no presentado. Es O(n).
- Análisis de complejidad (TAD real): O(n) por las dos iteraciones, más el costo de `invertirLista` (ver Ej. 2) y de cada `l_agregar`. En punteros/cursores con `l_agregar` actual, queda O(n²).
- Casos borde: lista vacía → devuelve lista vacía. Un solo elemento con `ultimoDoble=false`: agrega el elemento, salta el invertido (también un elemento) → queda `[x]`. Con `ultimoDoble=true` → `[x, x]`. Coherente.
- Sugerencias: la lista intermedia `invertida` queda sin destruir (memory leak menor). Podría destruirse con `destruir_lista` después de copiar.

### Ejercicio 9 — `listaEsMultiplo`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: **recursiva** (auxiliar `listaEsMultiploRec`).
- Implementación revisada: la función pública toma el primer par de elementos, calcula el escalar `te2/te1` y delega a la recursiva, que verifica el resto. La recursiva valida que ambas listas tengan la misma longitud (ambas se vacíen al mismo tiempo) y que cada par cumpla `te2 = te1 * escalar`. Es correcto en el caso general.
- Problema (origen de la advertencia): la verificación del primer par solo chequea `te2 % te1 == 0`, **pero no** que `te1 != 0` previamente (sí lo chequea en la recursiva). Si la primera componente de `l1` es 0, se hace módulo por cero → comportamiento indefinido. Caso borde no cubierto.
- Casos borde: listas de distinta longitud → la recursiva devuelve `false` correctamente. Lista vacía: devuelve `false` (razonable). Primera componente cero: bug.
- Análisis de complejidad (TAD ideal): no presentado. Es O(n).
- Análisis de complejidad (TAD real): O(n) en cantidad de operaciones del iterador.
- Sugerencias: mover la verificación `te1->clave != 0` antes de la operación módulo en la función pública (ya está hecha en la recursiva). Documentar el análisis.

### Ejercicio 10 — `compararListas`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: **recursiva** (auxiliar `compararRec`).
- Implementación revisada: cuenta cuántas posiciones de `l1` son mayores menos cuántas son menores. Si la suma final es positiva, MAYOR; negativa, MENOR; cero, IGUAL.
- Problema 1: el corte recursivo es `if (!hay_siguiente(i1) || !hay_siguiente(i2)) return 0;`. Esto significa que **si las listas tienen distinta longitud, se ignora la cola** del lado más largo. Para el enunciado típico de "lista mayor/menor lexicográficamente", esto es incorrecto; las listas de distinta longitud deberían tratarse según la convención (la más corta es menor si todos los elementos coinciden hasta ahí).
- Problema 2: la métrica "suma de diferencias positivas/negativas" no es el orden lexicográfico estándar. Por ejemplo, `l1=[5,1]` y `l2=[3,2]`: en lexicográfico `l1 > l2` (porque 5>3). Acá: `+1 -1 = 0` → IGUAL. Esto contradice la noción usual de comparación de listas.
- Los tests del grupo casualmente pasan porque las listas elegidas tienen mayoría de un signo, pero la lógica no representa una comparación lexicográfica correcta.
- Casos borde: dos listas vacías → IGUAL (correcto). Listas de distinta longitud: pierde información.
- Análisis de complejidad (TAD ideal/real): no presentado. Es O(n) en cantidad de elementos.
- Sugerencias: reconsiderar el algoritmo: comparar elemento a elemento en orden y devolver el signo de la **primera diferencia**; si todos iguales hasta agotar la más corta, la más larga es MAYOR. Documentar el análisis.

### Ejercicio 11 — `evaluar` y `valores` (TAD Polinomio)

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada (`evaluar`): **iterativa**, recorre los coeficientes con el iterador, acumulando `coef * x^grado`. Correcto, tratando la lista como coeficientes ordenados de menor a mayor grado.
- Modalidad entregada (`valores`): **iterativa**, evalúa el polinomio en `x = desde, desde+paso, ..., hasta` y agrega cada resultado (casteado a `int`) a una lista. Devuelve la lista.
- Problemas:
    1. En `valores`, `x` se declara `int` y `paso` es `double`. La operación `x += paso` trunca a `int`, así que si `paso = 0.5`, queda `x += 0` y el bucle es **infinito** o no avanza. Cualquier `paso` con parte fraccionaria pierde precisión.
    2. La función `valores` debería retornar una `Lista` de `PuntoXY` según las firmas/structs del header (`struct PuntoXY {double x, y;}` y `toStringPuntoXY` en el test), pero la implementación entregada agrega solo el valor `y` truncado a `int` con `te_crear((int)res)`. El test (`test_polinomio.c`) lo asume así también (chequea solo `te->clave == 10`, `27`), por lo que la implementación pasa el test del grupo, pero **no cumple** con la intención del struct `PuntoXY` declarado en el header.
    3. No hay protección contra `paso <= 0` (que sería un caso patológico de bucle infinito o no entrada en el bucle).
- Casos borde: polinomio con un único coeficiente → `evaluar` devuelve ese coeficiente (correcto). `paso=0` → bucle infinito (no manejado).
- Análisis de complejidad (TAD ideal/real): no presentado. `evaluar` es O(n) en coeficientes. `valores` es O(((hasta-desde)/paso) * n).
- Sugerencias: declarar `x` como `double`, contemplar `paso <= 0`, y decidir si se almacenan `PuntoXY` (lo que sugiere el header) o solo `y`. Documentar el análisis.

### Ejercicio 12 — `subLista`

**Estado: 🚫 NO IMPLEMENTADO**

- Ejercicio opcional, pero declarado en el header. No hay cuerpo en `practica_listas.c` y el test `test_sublistas.c` solo imprime el título.
- Si se interpreta como **opcional no entregado**, el estado equivalente sería 😏 NO ENTREGADO. Dado que el header lo declara y hay un archivo de test vacío esperando, se marca como 🚫 NO IMPLEMENTADO.

### Ejercicio 13 — `subConjuntosQueSumanN`

**Estado: 🚫 NO IMPLEMENTADO**

- Ejercicio opcional. No hay implementación en `practica_listas.c` y el test `test_subconjuntos_suman_n.c` solo imprime el título.
- Aplica la misma observación que el Ejercicio 12.

---

## Revisión de tests

| Test                                | Estado          | Observaciones                                                                                                  |
|-------------------------------------|-----------------|----------------------------------------------------------------------------------------------------------------|
| `test_invertir_lista.c`             | ⚠️ Incompleto  | Imprime resultados pero **no usa `assert`**; no valida automáticamente. Falta lista vacía y de 1 elemento.     |
| `test_menor_datos.c`                | ⚠️ Incompleto  | Solo `printf`, sin `assert`. Falta lista vacía y caso con mínimo en posición 1.                                |
| `test_dato_maximo.c`                | ✅ Completo     | Usa comparación explícita con `if` y reporta éxito/fallo. Cubre todos iguales parcialmente. Falta lista vacía. |
| `test_promedio_lista.c`             | 🚫 No entregado | El `main` agrega elementos pero **nunca invoca** `promedio()`. No valida nada.                                 |
| `test_lista_multiplo_escalar.c`     | ✅ Completo     | Usa `assert` para verificar cada elemento del resultado. Falta lista vacía y escalar 0.                        |
| `test_lista_azar.c`                 | 🚫 No entregado | Solo imprime el título; el ejercicio 7 no está implementado.                                                   |
| `test_lista_reflejada.c`            | ⚠️ Incompleto  | Solo `printf`, sin `assert`. Cubre los dos modos (`true`/`false`). Falta lista vacía y de 1 elemento.          |
| `test_lista_es_multiplo.c`          | ⚠️ Incompleto  | Usa `assert` y cubre caso positivo/negativo. Falta listas de distinta longitud y caso con `te1->clave == 0`.   |
| `test_comparacion_de_listas.c`      | ✅ Completo     | Usa `assert` para MENOR, IGUAL, MAYOR. Pero el test pasa solo por la lógica acumulativa del algoritmo (que es discutible — ver Ej. 10). Falta listas de distinta longitud. |
| `test_polinomio.c`                  | ✅ Completo     | Cubre `evaluar` y `valores` con `assert`. Falta polinomio de un coeficiente y `paso` fraccionario.             |
| `test_sublistas.c`                  | 🚫 No entregado | Solo imprime el título; el ejercicio 12 no está implementado.                                                  |
| `test_subconjuntos_suman_n.c`       | 🚫 No entregado | Solo imprime el título; el ejercicio 13 no está implementado.                                                  |

### Tests con casos de borde faltantes

- `test_invertir_lista.c`, `test_menor_datos.c`, `test_dato_maximo.c`, `test_lista_reflejada.c`: no prueban con lista vacía ni de un solo elemento.
- `test_lista_multiplo_escalar.c`: no prueba con `n=0` ni con lista vacía.
- `test_lista_es_multiplo.c`: no prueba con listas de distinta longitud ni con primer elemento de `l1` igual a cero.
- `test_comparacion_de_listas.c`: no prueba con listas de distinta longitud.
- `test_polinomio.c`: no prueba con un único coeficiente ni con `paso` no entero.

### Tests del TAD

No hay tests específicos del TAD Lista en `tads/listas/tests/` (la carpeta no existe). El grupo no entregó tests para `l_crear` + `l_agregar` + `l_eliminar` + `l_recuperar`, etc. — congruente con que esas operaciones núcleo del TAD están sin implementar.

---

## Resumen

| Categoría                                   | Estado                                                                                          |
|---------------------------------------------|-------------------------------------------------------------------------------------------------|
| Archivos `.h` sin modificar (contenido)     | ⚠️ Advertencia (`practica_listas.h` extendido con `invertirListaRec`)                          |
| TAD Lista — `listas_arreglos.c`             | ❌ Incorrecto (faltan `l_longitud`, `l_borrar`, `l_buscar`, `l_eliminar`, `l_recuperar`, `l_mostrar`) |
| TAD Lista — `listas_punteros.c`             | ❌ Incorrecto (mismas funciones faltantes)                                                      |
| TAD Lista — `listas_cursores.c`             | ❌ Incorrecto (mismas funciones faltantes)                                                      |
| Ejercicio 2 — `invertirLista`               | ✅ Correcto (iterativa + recursiva)                                                             |
| Ejercicio 3 — `menorYPosicion`              | ✅ Correcto                                                                                     |
| Ejercicio 4 — `mayorYOcurrencias`           | ✅ Correcto                                                                                     |
| Ejercicio 5 — `promedio`                    | ✅ Correcto                                                                                     |
| Ejercicio 6 — `multiplos`                   | ✅ Correcto                                                                                     |
| Ejercicio 7 — `numerosAlAzar`               | 🚫 No implementado                                                                              |
| Ejercicio 8 — `reflejarLista`               | ✅ Correcto                                                                                     |
| Ejercicio 9 — `listaEsMultiplo`             | ⚠️ Advertencia (división por cero si `l1[0]==0`)                                               |
| Ejercicio 10 — `compararListas`             | ⚠️ Advertencia (semántica de comparación discutible; ignora colas de listas desiguales)        |
| Ejercicio 11 — `evaluar` y `valores`        | ⚠️ Advertencia (en `valores`: `x` int trunca el `paso`; struct `PuntoXY` no se usa)            |
| Ejercicio 12 — `subLista`                   | 🚫 No implementado                                                                              |
| Ejercicio 13 — `subConjuntosQueSumanN`      | 🚫 No implementado                                                                              |
| Ejercicios correctos                        | 5 de 12 correctos; 3 con advertencias; 0 incorrectos lógicos; 3 sin implementar; el Ejercicio 1 (TAD) queda incorrecto en sus tres representaciones por operaciones faltantes |
| Tests entregados (no vacíos)                | 8 de 12 (4 no entregados: promedio, lista_azar, sublistas, subconjuntos_suman_n)               |
| Tests con buena cobertura (assert + bordes) | 4 de 12 (`test_dato_maximo`, `test_lista_multiplo_escalar`, `test_comparacion_de_listas`, `test_polinomio`), todos con bordes faltantes pero al menos validan automáticamente |

### Observaciones globales

- **Falta análisis de complejidad escrito** para todos los ejercicios que lo piden (2, 3, 4, 5, 6, 7, 8, 9, 10, 12). Esto es un requisito explícito de la práctica y no aparece en ningún archivo entregado. Cada ejercicio tiene una nota recordándolo, pero la ausencia se observa también de manera transversal.
- **Operaciones núcleo del TAD sin implementar**: `l_longitud`, `l_borrar`, `l_buscar`, `l_eliminar`, `l_recuperar`, `l_mostrar` están vacías en las **tres** representaciones. El TAD entregado solo soporta el ciclo *crear → agregar/insertar → iterar*, lo que casualmente alcanza para que los ejercicios del Bloque B funcionen (todos están escritos usando solo el iterador), pero el Ejercicio 1 de la práctica no está completo.
- **Casos borde sistemáticamente débiles** en los tests: muchos usan `printf` sin `assert`, dejando la validación al ojo humano. Para futuras entregas conviene cubrir lista vacía y de un solo elemento de manera explícita en cada test.
- **Cobertura del enunciado**: 3 de los 12 ejercicios (7, 12, 13) no se entregaron. 12 y 13 son opcionales en el enunciado; 7 (`numerosAlAzar`) es obligatorio.
