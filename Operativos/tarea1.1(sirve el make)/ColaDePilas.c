  /*
 * Archivo: ColaDePilas.c
 * Descripcion: Cola de pilas.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supermercado.h"

queue* create_queue(){ //initializes the queue

    queue* cola = malloc(sizeof(queue));

    cola->size = 0;
    cola->head = NULL;
    cola->tail = NULL;

    return cola;
}

void enqueue(queue* q, stack* pila){

    NODE* temp = (NODE*)malloc(sizeof(NODE)); //allocates

    if(temp == NULL) 
    {
        printf("Unable to allocate memory\n");
    }

    else if((q->size) == 0) 
    {
        temp->next = q->head;
        temp->pila = pila;
        //printf("POINTER INTERNO 1%p\n",temp->pila );
        q->head = temp;
        q->head->next = NULL;
        q->tail = temp;
        q->tail->next = NULL;
        q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
    }

    else
    {
        temp->next = q->tail;
        q->tail->prev = temp;
        temp->pila = pila;
        q->tail = temp;
        q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
    }
}

stack* dequeue(queue* q){

    int salida = 0;

    if ((q->size) == 0) 
    {
      printf("La cola esta vacia \n");
      return NULL;
    }

    else
    {
        NODE* temp;
        stack* temp2;

        temp = q->head;
        temp2 = temp->pila;
        //printf("APUUUUNTAAA %p\n",temp2);
        q->head = q->head->prev;
        //printf("%p\n", &(temp2->pila));
        //printf("----%s\n", casa.name);
        free(temp);
        q->size = (q->size) - 1; //subtracts from counter

        return temp2;
    }
}