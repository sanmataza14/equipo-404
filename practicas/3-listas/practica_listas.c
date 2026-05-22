#include <stdlib.h>
#include <math.h>

#include "practica_listas.h"
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

void promedioRecAux(Lista l, Iterador p, double *suma, int *contador){
    if(p == fin(l)){
        return;
    }
    TipoElemento te = recuperar(l, p);
    *suma += te_recuperar(te);
    *contador += 1;
    promedioRecAux(l, siguiente(p), suma, contador);
}

double promedio(Lista l){
    if(primero(l) == fin(l)){
        return 0.0;
    }
double suma = 0;
int contador = 0;
Iterador p = primero(l);

promedioRecAux(l, p, &suma, &contador);

return suma / contador;
}

Lista invertirListaRec(Iterador iter) {
}

Lista invertirLista(Lista l) {
}

double evaluar(struct Polinomio p, double x) {
}


Lista valores(struct Polinomio p, int desde, int hasta, double paso) {
}
