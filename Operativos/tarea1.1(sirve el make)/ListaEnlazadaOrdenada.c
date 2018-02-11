/*
 * Archivo: ListaEnlazadaOrdenada.c
 * Descripcion: Lista enlazada ordenada.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supermercado.h"

node* createList(){

    node *l = NULL;
    return l;
}

/* Pone nodo en list según el orden alfabetico del campo dato.name */
/* PELUCHE */
void put(node** list, node* nod){

    if(*list == NULL || ( nod->product.size - (*list)->product.size ) >= 0)
    {
        nod->next = *list;
        *list = nod;
    }

    else 
    {
        node* p = *list;

        while(p->next != NULL && (nod->product.size - p->next->product.size) < 0)
        {
            p = p->next;
        }

        nod->next = p->next;
        p->next = nod;
    }
}

/* Crea un nodo con nodo->dato == e y lo ponee en list *
 * en orden alfabetico según el campo dato.name.    *
 * Retorna 1 si se insert con éxito y 0 si no.       */
int insert(node** list, Producto p){

    int r; /* valor de retorno */

    /* crear nuevo nodo */
    node* pNuevo = malloc(sizeof(*pNuevo));

    /* puntero en la lista */
    if(r = pNuevo != NULL) 
    {
        pNuevo->product = p;
        put( list, pNuevo );
    }

    return r;
}

void printList(node* pActual){

   /* Mientras no sea el final de la lista */
   while ( pActual != NULL ) 
   {
        printf("Nombre: %s  size %d complex %d num %d\n",pActual->product.name,pActual->product.size,pActual->product.complex,pActual->product.num);
        pActual = pActual->next;
   }
}