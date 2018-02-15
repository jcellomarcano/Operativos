/*
 * Archivo: esbirro.c
 * Descripcion: archivo principal del programa.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supermercado.h"

/*********** Control del programa ***********/

int main(int argc, char *argv[]){

    int velocidadCajera = 1;             // velocidad de la cajera en operaciones or segundo
    int velocidadEmbolsador = 4;         // velocidad del embolsador en segundos por bolsa
    int tiempoFacturacion = 130;         // tiempo de facturacion en segundos
    int capacidadMaxAreaEmbolsado = 150; // capacidad del area de embolsado en centimetros cubicos
    int capacidadMaxBolsa = 120;         // caacidad maxima de una bolsa en centimetros cubicos
    int capacidadMaxBanda = 200;

    Producto *arrayProductos; // Apunta al inicio del arreglo
    Producto *copiaArrayProductos; // Copia de la direccion en donde comienza la lista de productos
    int lines;
    // lines contiene el numero de lineas en el archivo
    lines = countlines(argv[1]);
    printf("LINES: %d\n",lines);
    printf("Lineas \n");
    // Recibimos la direccion donde comienza el arreglo
    arrayProductos = read(lines,argv[1]);
    //printf("-----%d\n",(*arrayProductos).size );
    copiaArrayProductos = arrayProductos;
    //printf("-----%s\n",(*copiaArrayProductos).name);

    int carritos = 3;
    int CantidadMaxCarrito = 12;
    int random; // cantidad de productos que vamos a agarrar por cada carrito
    int random2; // producto a agarrar por cada iteracion
    srand(time(NULL));
    queue *cola = create_queue(); // creamos la cola donde guardamos todas las pilas de carros

    for(int i = 0; i < carritos;i++) // iteramos por cada  carrito de cada cliente
    {
        random = (rand() % CantidadMaxCarrito) + 1; // seleccionamos al azar la cantidad de productos que va a tener el carrito de cada cliente
        printf("RANDOM 1: %d\n",random );
        printf("LISTA %d------------------\n",i+1 );
        node *lista = createList();

        for (int j = 0; j < random; j++)
        {
            random2 = (rand() % lines) + 1; // escogemos de manera al azar los productos que va a tener cada carrito
            //printf("RANDOM 2 :%d\n",random2 );
            arrayProductos = copiaArrayProductos;

            for (int k = 0; k < lines; k++)
            {
                // metemos los productos en la lista ordenada
                if ((*arrayProductos).num == random2)
                {
                    insert((&lista),(*arrayProductos));
                    printf("NAME %s\n",(*arrayProductos).name );
                    break;
                }

                arrayProductos++;
            }
        }

        printf("IMPRIMOS LISTA++++++++ %d\n",i+1 );
        //printList(lista);

        // los pasamos ya ordenado de mayor a menor a la pila (el carrito)

        stack* pila = create_stack();

        while ( lista != NULL )
        {
            printf("Nombre: %s  size %d complex %d num %d\n",lista->product.name,lista->product.size,lista->product.complex,lista->product.num);
            push(pila, lista->product); // empilamos los productos al carrito
            lista = lista->next;
            //printf("SIZE %d\n", pila->size );
        }
        // ponemos al cliente a hacer la cola de la caja de acuerdo al orden de llegada

        enqueue(cola, pila); //guardamos la pila en la cola
        printf("SIZE DE LA COLA %d\n", cola->size );
    }

    // apartir de aqui se deben tomar en cuenta las modalidades (un poco mas adelante)
    //proceso completo
    /*while ((cola->size != 0) && (pilaa->size != 0)) // y embolsador termino de embolsar
    {

        stack* pilaa;
        pilaa = dequeue(c);
        int finEmpaquetado = 0; // cero representa el false

        // atendemos a cada cliente
        while ((pilaa->size != 0) && (finEmpaquetado != 1)) // y la banda transportadora este vacia
        {
            int cantidadActualBanda = 0; // Cuenta el espacio almacenado de la banda
            //int finEmpaquetado = 0; // cero representa el false

            int llenarBanda = 0;
            // Aqui se llena la banda cada ciclo antes de que la cajera tome el producto
            // se crea la cola de la banda transportadora
            colaa colax = crecreate_queue();
            int chequeo;
            Producto produ;

            while (llenarBanda != 1)
            {
                // se llena la banda transportadora hasta su maxima capacidad posible
                chequeo = top(pilaa);

                if (((colaa->ccEnBanda)+chequeo) <= capacidadMaxBanda)
                {
                    &produ = pop(pilaa);
                    enenqueue(colax,produ);
                }

                else
                {
                    llenarBanda = 1;
                }
            }

            // Aqui se pone el enter y la cajera empieza a atender y se mide el tiempo
        }

    }*/

    return 0;

}
