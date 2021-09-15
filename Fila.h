#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>

typedef struct nodoF
{
    int dato;
    struct nodoF* prim;
    struct nodoF* ult;
}nodoF;

void inicListaF (nodoF**);
void agregar (nodoF**);
void extraer (nodoF**);
void mostrar (nodoF*);
void leer (nodoF**);
void primero (nodoF*);
void filavacia (nodoF*);

#endif // FILA_H_INCLUDED
