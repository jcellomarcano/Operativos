/*
 * Archivo: Pila.c
 * Descripcion: Pila.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supermercado.h"

stack* create_stack(){ //initializes the stack

    stack* pila = malloc (sizeof(stack));

    pila->size = 0;
    pila->head = NULL;

    return pila;
}

void push(stack* s, Producto pro){

    node* temp = (node*)malloc(sizeof(node)); //allocates

    if ( temp == NULL ) 
    {
        printf("No se puede asignar el espacio de memoria solicitado\n");
    }

    else
    {
        temp->next = s->head;
        temp->product = pro;
        s->head = temp;
        s->size = (s->size) + 1; //bumps the counter for how many elements are in the stack
    }

}

Producto* pop(stack* s){

    if ((s->size) == 0) 
    {
        printf("La pila esta vacia \n");
        return NULL;
    }

    else
    {
        node* temp;
        node* temp2;

        temp = s->head;
        s->head = temp->next;
        s->size = (s->size) - 1; //subtracts from counter
        temp2 = temp;
        //printf("%p\n", &(temp2->product));
        //printf("%s\n", casa.name);
        free(temp);
        //printf("%s\n", casa.name);
        //printf("%p\n",&(temp2->product) );

        return &(temp2->product);
    }

}

int top(stack* s){

    if ((s->size) == 0) 
    {
        printf("La pila esta vacia \n");

        return 0;
    }

    else
    {
        node* temp = s->head;
        Producto value = temp->product;
        printf("%s\n",value.name );

        return value.size;
    }
}