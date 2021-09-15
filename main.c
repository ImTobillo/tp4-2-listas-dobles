#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

/// estructuras

typedef struct nodoD
{
    int dato;
    struct nodoD* sig;
    struct nodoD* ant;
}nodoD;

/// funciones

void inicListaD (nodoD** listaD)
{
    *listaD = NULL;
}

nodoD* crearNodoD (int dato)
{
    nodoD* aux = (nodoD*)malloc(sizeof(nodoD));
    aux->dato = dato;
    aux->ant = NULL;
    aux->sig = NULL;
    return aux;
}

void insertarAlPrincipio (nodoD** listaD)
{
    int dato;
    printf("Ingrese un numero: ");
    scanf("%i", &dato);

    nodoD* aux = crearNodoD (dato);

    if (*listaD)
    {
        aux->sig = *listaD;
        (*listaD)->ant = aux;
        *listaD = aux;
    }
    else
    {
        *listaD = aux;
    }
}

nodoD* retUltimoNodoD (nodoD* listaD)
{
    if (!listaD)      /// condicion de corte
        return NULL;    /// solucion trivial
    if (!listaD->sig)    /// condicion de corte 2
        return listaD;    /// solucion trivial
    else
        return retUltimoNodoD(listaD->sig); /// llamada recursiva y acercamiento
}

void insertarNodoDAlFinal (nodoD** listaD)
{
    int dato;
    printf("Ingrese un dato: ");
    scanf ("%i", &dato);

    nodoD* aux = crearNodoD (dato);

    if (*listaD)
    {
        nodoD* seg = *listaD;

        while (seg->sig)
            seg = seg->sig;

        seg->sig = aux;
        aux->ant = seg;
    }
    else
        *listaD = aux;
}

void insertarNodoDAlFinal_dato (nodoD** listaD, int dato)
{
    nodoD* aux = crearNodoD (dato);

    if (*listaD)
    {
        nodoD* seg = *listaD;

        while (seg->sig)
            seg = seg->sig;

        seg->sig = aux;
        aux->ant = seg;
    }
    else
        *listaD = aux;
}

void insertarNodoDOrdenado (nodoD** listaD, int dato)
{
    nodoD* aux = crearNodoD(dato);

    if (*listaD)
    {
        if ((*listaD)->dato > dato)
        {
            aux->sig = *listaD;
            (*listaD)->ant = aux;
            *listaD = aux;
        }
        else
        {
            nodoD* nAnt = *listaD, *nAct = (*listaD)->sig;

            while (nAct && nAct->dato < dato)
            {
                nAnt = nAct;
                nAct = nAct->sig;
            }

            nAnt->sig = aux;
            aux->ant = nAnt;

            aux->sig = nAct;
            if (nAct)
                nAct->ant = aux;
        }
    }
    else
        *listaD = aux;
}

void borrarNodo (nodoD** listaD, int dato)
{
    if (*listaD)
    {
        nodoD* aux = *listaD;

        if ((*listaD)->dato == dato)
        {
            *listaD = (*listaD)->sig;
            if (*listaD)
                (*listaD)->ant = NULL;
            free(aux);
        }
        else
        {
            aux = aux->sig;

            while (aux && aux->dato != dato)
                aux = aux->sig;

            if (aux)
            {
                aux->ant->sig = aux->sig;
                if (aux->sig)
                    aux->sig->ant = aux->ant;
                free(aux);
            }
        }
    }

}

void borrarNodo_porNodo (nodoD** listaD, nodoD* borrar)
{
    if (*listaD)
    {
        nodoD* aux = *listaD;

        if (*listaD == borrar)
        {
            *listaD = (*listaD)->sig;
            if (*listaD)
                (*listaD)->ant = NULL;
            free(aux);
        }
        else
        {
            aux = aux->sig;

            while (aux && aux != borrar)
                aux = aux->sig;

            if (aux)
            {
                aux->ant->sig = aux->sig;
                if (aux->sig)
                    aux->sig->ant = aux->ant;
                free(aux);
            }
        }
    }

}

int buscarNodo (nodoD* listaD, int dato)
{
    while (listaD && listaD->dato != dato)
        listaD = listaD->sig;
    if (listaD)
        return 1;
    else
        return 0;
}

void eliminarPrimerNodoD (nodoD** listaD)
{
    if (*listaD)
    {
        nodoD* aux = *listaD;
        *listaD = (*listaD)->sig;
        if (*listaD)
            (*listaD)->ant = NULL;
        free(aux);
    }
}

void eliminarUltNodoD (nodoD** listaD)
{
    if (*listaD)
    {
        nodoD* aux = *listaD;

        if (aux->sig)  /// si la lista tuviera mas de un dato
        {
            while (aux->sig)
                aux = aux->sig;

            aux->ant->sig = NULL;
            free(aux);
        }
        else  /// si la lista tuviera un solo dato
        {
            *listaD = NULL;
            free(aux);
        }
    }
}

void mostrarListaD (nodoD* listaD)
{
    while (listaD)
    {
        printf("%i\t", listaD->dato);
        listaD = listaD->sig;
    }
}

int listaD_capicua (nodoD* prim, nodoD* ult)
{
    if (prim && prim->dato == ult->dato)
        return listaD_capicua (prim->sig, ult->ant);
    else if (!prim) /// prim == NULL
        return 1;
    else
        return 0;
}

void eliminarNodoMedio (nodoD** listaD)
{
    nodoD* ult = retUltimoNodoD(*listaD), *prim = *listaD;

    while (prim->dato < ult->dato)
    {
        prim = prim->sig;
        ult = ult->ant;
    }

    borrarNodo_porNodo(listaD, prim);
}

/// main

int main()
{
    nodoD* listaD;
    inicListaD(&listaD);

    insertarNodoDAlFinal_dato(&listaD, 1);
    insertarNodoDAlFinal_dato(&listaD, 2);
    insertarNodoDAlFinal_dato(&listaD, 2);
    insertarNodoDAlFinal_dato(&listaD, 3);
    insertarNodoDAlFinal_dato(&listaD, 5);
    insertarNodoDAlFinal_dato(&listaD, 8);
    insertarNodoDAlFinal_dato(&listaD, 9);

    printf("Lista capicua: %i\n", listaD_capicua(listaD, retUltimoNodoD(listaD)));

    eliminarNodoMedio(&listaD);
    printf("\n\n");
    mostrarListaD(listaD);


    return 0;
}
