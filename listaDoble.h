#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utilitarios.h"

typedef struct s_nodo
{
    void *info;
    unsigned tamInfo;
    struct s_nodo *sig,
                  *ant;
}t_nodo;

typedef t_nodo *t_listaD;

void crearLista(t_listaD *pl);
booleano listaVacia(const t_listaD *pl);
booleano listaLlena(const t_listaD *pl, unsigned tamDato);
int vaciarLista(t_listaD *pl);
booleano enlistarAlComienzo(t_listaD *pl, const void *dato, unsigned tamDato);
booleano enlistarAlFinal(t_listaD *pl, const void *dato, unsigned tamDato);
booleano enlistarEnOrden(t_listaD *pl, const void *dato, unsigned tamDato, Cmp cmp, Acum acum);
booleano desenlistarPorClave (t_listaD *pl, void *dato, unsigned tamDato, Cmp cmp);
int mostrarListaDeIzqADer(t_listaD *pl, Mostrar mostrar);
int mostrarListaDeDerAIzq(t_listaD *pl, Mostrar mostrar);
void ordenarLista (t_listaD *pl, Cmp cmp);
void ordenarListaYAcumular (t_listaD *pl, Cmp cmp, Acum acum);

#endif // LISTADOBLE_H_INCLUDED
