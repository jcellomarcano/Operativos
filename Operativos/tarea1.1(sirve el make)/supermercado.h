/*
 * Archivo: supermercado.h
 * Descripcion: Prototipos de funciones y estructuras.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

/**************************************************************************/
/****************************** Estructuras *******************************/
/**************************************************************************/

/* Articulos de la tienda */
typedef struct prod{

    int num; // El numero del producto
    char name[15]; // Nombre del Producto
    int size; // tamano del producto
    int complex; // complejidad

}Producto;

/* nodo de la lista */
typedef struct node_{

    Producto product;
    struct node_ *next;

}node;

/* MARVADA PILA */
typedef struct stack_{

    unsigned int size;
    node* head;

}stack;

/* Nodo de la cola de pilas */
typedef struct NODE_{

    stack* pila;
    struct NODE_ *next;
    struct NODE_ *prev;

}NODE;

/* Cola de marvadas pilas */
typedef struct queue_{

    unsigned int size;
    NODE* head;
    NODE* tail;

}queue;

/* Nodo de la cola de productos */
typedef struct Node_{

    Producto product;
    struct Node_ *next;
    struct Node_ *prev;

}Node;

/* Cola de productos */
typedef struct Queue_{

    unsigned int size;
    int ccEnBanda; // cuenta la cantidad de cc que hay en la banda transportadora
    Node* head;
    Node* tail;

}colaa;

/*****************************************************************************/
/************************* Prototipos de funciones ***************************/
/*****************************************************************************/

void Menu(int *carritos, int *cantidadMaxCarrito, int *capacidadMaxBanda,
	    int *velocidadCajera, int *velocidadEmbolsador, int *tiempoFacturacion,
	    int *capacidadMaxAreaEmbolsado, int *capacidadMaxBolsa, 
	    char *modalidad);

/* Menu de configuracion de la simulacion */
void Menu2(int **carritos, int **cantidadMaxCarrito, int **capacidadMaxBanda,
	    int **velocidadCajera, int **velocidadEmbolsador, int **tiempoFacturacion,
	    int **capacidadMaxAreaEmbolsado, int **capacidadMaxBolsa, 
	    char **modalidad);

/* Menu para cambiar algun valor de la configuracion */
void Menu3(int ***carritos, int ***cantidadMaxCarrito, int ***capacidadMaxBanda,
	    int ***velocidadCajera, int ***velocidadEmbolsador, 
	    int ***tiempoFacturacion, int ***capacidadMaxAreaEmbolsado, 
	    int ***capacidadMaxBolsa, char ***modalidad);

void Modal(char ****modalidad);

void CanCarritos(int ****carritos);

void ProducMaxCarrito(int ****cantidadMaxCarrito);

void CapMaxBanda(int ****capacidadMaxBanda);

void VeloCajera(int ****velocidadCajera);

void VeloEmbolsador(int ****velocidadEmbolsador);

void TempFacturacion(int ****tiempoFacturacion);

void CapMaxAreaEmbolsado(int ****capacidadMaxAreaEmbolsado);

void CapMaxBolsa(int ****capacidadMaxBolsa);

int countlines(char *filename);

Producto* read(int numLines, char *filename);

node* createList();

void put(node** list, node* nod);

int insert(node** list, Producto p);

void printList(node* pActual);

stack* create_stack();

void push(stack* s, Producto pro);

Producto* pop(stack* s);

int top(stack* s);

queue* create_queue();

void enqueue(queue* q, stack* pila);

stack* dequeue(queue* q);

colaa* crecreate_queue();

void enenqueue(colaa* q, Producto pro);

Producto* dedequeue(colaa* q);

int tope(colaa* q);