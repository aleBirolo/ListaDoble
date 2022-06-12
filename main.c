#include "main.h"

#define TAM 10

int main()
{
    t_listaD lista;
    int i,
        num;

    crearLista(&lista);

    /*
    for (i=0 ; i<TAM; i++, num=rand()%TAM)
        enlistarAlComienzo(&lista, &num,sizeof(int));
    */


    for (i=0 ; i<TAM; i++, num=rand()%TAM)
        enlistarAlFinal(&lista, &num,sizeof(int));


    /*
    for (i=0 ; i<TAM; i++, num=rand()%TAM)
        enlistarEnOrden(&lista, &num,sizeof(int),compararEnteros, acumularEntero    );
    */

    mostrarListaDeIzqADer(&lista, mostrarEntero);
    //mostrarListaDeDerAIzq(&lista, mostrarEntero);

    printf ("\n");
    /*
    num=0;
    desenlistarPorClave(&lista, &num, sizeof(int), compararEnteros);

    mostrarListaDeIzqADer(&lista, mostrarEntero);
    */

    ordenarLista(&lista, compararEnteros);
    ordenarListaYAcumular(&lista,compararEnteros,acumularEntero);
    mostrarListaDeIzqADer(&lista, mostrarEntero);
    return 0;
}


int compararEnteros (const void *d1, const void *d2)
{
    int *n1=(int *)d1,
        *n2=(int *)d2;

    return (*n1) - (*n2);
}

int acumularEntero (void *d1, const void *d2)
{
    int *n1=(int *)d1,
        *n2=(int *)d2;

    (*n1)+= (*n2);

    return verdadero;
}

void mostrarEntero (const void *d)
{
    int *n = (int *)d;

    printf (" |%d|", *n);
}
