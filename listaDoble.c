#include "listaDoble.h"

void crearLista(t_listaD *pl)
{
    *pl=NULL;
}

booleano listaVacia(const t_listaD *pl)
{
    return *pl == NULL;
}

booleano listaLlena(const t_listaD *pl, unsigned tamDato)
{
    t_nodo *aux = malloc (sizeof(t_nodo));
    void *auxInfo = malloc (tamDato);

    free(aux);
    free(auxInfo);
    return aux == NULL ||auxInfo == NULL;
}

int vaciarLista(t_listaD *pl)
{
    int cant = 0;
    t_nodo *act= *pl,
           *aux;

    if (act)
    {
        while(act->ant)
            act = act->ant;
        while (act)
        {
            aux=act->sig;

            free(act->info);
            free(act);
            act=aux;
            cant++;
        }
        *pl=NULL;
    }
    return cant;
}

booleano enlistarAlComienzo(t_listaD *pl, const void *dato, unsigned tamDato)
{
    t_nodo *act=*pl,
           *nue;

    if (act)
        while(act->ant)
            act=act->ant;

    nue= malloc (sizeof(t_nodo));
    if (!nue)
        return falso;

    nue->info=malloc(tamDato);
    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = act;
    nue->ant =NULL;

    if (act)
        act->ant = nue;
    *pl=nue;

    return verdadero;
}

booleano enlistarAlFinal(t_listaD *pl, const void *dato, unsigned tamDato)
{
    t_nodo *act = *pl,
           *nue;

    if (act)
        while (act->sig)
            act=act->sig;

    nue= malloc (sizeof(t_nodo));
    if (!nue)
        return falso;

    nue->info=malloc(tamDato);
    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = NULL;
    nue->ant=act;

    if (act)
        act->sig=nue;
    *pl=nue;

    return verdadero;
}

booleano enlistarEnOrden(t_listaD *pl, const void *dato, unsigned tamDato, Cmp cmp, Acum acum)
{
    t_nodo *act=*pl,
            *sig,
            *ant,
            *nue;
    int comparacion;

    if (!act)
    {
        ant=NULL;
        sig=NULL;
    }
    else
    {
        while (act->sig && cmp(act->info, dato)< 0)
            act=act->sig;

        while (act->ant && cmp(act->info,dato)>0)
            act=act->ant;

        comparacion = cmp(act->info, dato);

        if (comparacion == 0)
        {
            *pl=act;
            acum(act->info, dato);

            return verdadero;
        }
        else
        {
            if (comparacion < 0)
            {
                ant = act;
                sig = act->sig;
            }
            else
            {
                ant = act->ant;
                sig = act;
            }
        }
    }

    nue= malloc (sizeof(t_nodo));
    if (!nue)
        return falso;

    nue->info=malloc(tamDato);
    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig=sig;
    nue->ant=ant;

    if (sig)
        sig->ant = nue;
    if (ant)
        ant->sig = nue;
    *pl=nue;

    return verdadero;
}

booleano desenlistarPorClave (t_listaD *pl, void *dato, unsigned tamDato, Cmp cmp)
{
    t_nodo *act=*pl,
           *ant,
           *sig;
    int comparacion;

    if (!act)
        return falso;

    while (act->sig && cmp(act->info, dato) < 0)
        act=act->sig;

    while (act->ant && cmp(act->info,dato)>0)
        act=act->ant;

    comparacion = cmp(act->info, dato);

    if (comparacion == 0)
    {
        ant = act->ant;
        sig = act->sig;

        if (ant)
            ant->sig = sig;

        if (sig)
        {
            sig->ant=ant;
            *pl=sig;
        }
        else
            *pl=ant;

        memcpy(dato, act->info, MIN(act->tamInfo, tamDato));
        free(act->info);
        free(act);

        return verdadero;
    }

    return falso;
}

int mostrarListaDeIzqADer(t_listaD *pl, Mostrar mostrar)
{
    t_nodo *act=*pl;
    int cant=0;

    if (act)
    {
        while (act->ant)
            act=act->ant;

        while(act)
        {
            mostrar(act->info);
            act=act->sig;
            cant++;
        }
    }
    return cant;
}

int mostrarListaDeDerAIzq(t_listaD *pl, Mostrar mostrar)
{
    t_nodo *act=*pl;
    int cant=0;

    if (act)
    {
        while (act->sig)
            act=act->sig;

        while(act)
        {
            mostrar(act->info);
            act=act->ant;
            cant++;
        }
    }
    return cant;
}

void ordenarLista (t_listaD *pl, Cmp cmp)
{
    t_nodo *act=*pl,
           *ult=NULL,
           *pri=NULL;
    int marca = 1;
    void *info;
    unsigned tamInfo;

    if (!act)
        return ;

    while (act->ant)
        act=act->ant;

    while (marca)
    {
        marca = 0;

        while (act->sig != ult)
        {
            if (cmp(act->info, act->sig->info) > 0)
            {
                info = act->info;
                tamInfo = act->tamInfo;

                marca=1;

                act->info=act->sig->info;
                act->sig->info = info;

                act->tamInfo = act->sig->tamInfo;
                act->sig->tamInfo = tamInfo;
            }
            act = act->sig;
        }
        ult = act;

        while(act->ant != pri)
        {
            if (cmp(act->info, act->ant->info) < 0)
            {
                info = act->info;
                tamInfo = act->tamInfo;

                marca=1;

                act->info = act->ant->info;
                act->ant->info = info;

                act->tamInfo = act->ant->tamInfo;
                act->ant->tamInfo = tamInfo;
            }
            act = act->ant;
        }
        pri = act;
    }
}

void ordenarListaYAcumular (t_listaD *pl, Cmp cmp, Acum acum)
{
    t_nodo *act=*pl,
           *ult=NULL,
           *pri=NULL;
    int marca = 1;
    void *info;
    unsigned tamInfo;

    if (!act)
        return ;

    while (act->ant)
        act=act->ant;

    while (marca)
    {
        marca = 0;

        while (act->sig != ult)
        {
            if (cmp(act->info, act->sig->info) == 0)
            {
                acum(act->info, act->sig->info);
                act->sig = act->sig->sig;
                act->sig->ant = act;
            }
            else
            {
                if (cmp(act->info, act->sig->info) > 0)
                {
                    info = act->info;
                    tamInfo = act->tamInfo;

                    marca=1;

                    act->info=act->sig->info;
                    act->sig->info = info;

                    act->tamInfo = act->sig->tamInfo;
                    act->sig->tamInfo = tamInfo;
                }
                act = act->sig;
            }

        }
        ult = act;

        while(act->ant != pri)
        {
            if (cmp(act->info, act->ant->info) == 0)
            {
                acum(act->info, act->ant->info);
                act->ant = act->ant->ant;
                act->ant->sig = act;
            }
            else
            {
                if (cmp(act->info, act->ant->info) < 0)
                {
                    info = act->info;
                    tamInfo = act->tamInfo;

                    marca=1;

                    act->info = act->ant->info;
                    act->ant->info = info;

                    act->tamInfo = act->ant->tamInfo;
                    act->ant->tamInfo = tamInfo;
                }
                act = act->ant;
            }

        }
        pri = act;
    }
}
