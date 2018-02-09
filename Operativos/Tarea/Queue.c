#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prod{
   int num; // El numero del producto
   char name[15]; // Nombre del Producto
   int size; // tamano del producto
   int complex; // complejidad
}Producto;

typedef struct node_{
    Producto product;
    struct node_ *next;
    struct node_ *prev;
}node;

typedef struct queue_{
    unsigned int size;
    node* head;
    node* tail;
}queue;

queue* create_queue();
void enqueue(queue* q, Producto val);
void top(queue* q);
Producto* dequeue(queue*q);

int main(void) {

  char value, val;

  queue* cola = create_queue();

  Producto cafe;
  cafe.num= 0;
  strcpy(cafe.name,"cafe");
  cafe.size = 5;
  cafe.complex = 10;

  Producto queso;
  queso.num= 1;
  strcpy(queso.name,"queso");
  queso.size = 10;
  queso.complex = 15;

  Producto jam;
  jam.num = 2;
  strcpy(jam.name,"jamon");
  jam.size = 10;
  jam.complex = 15;

  Producto pan;
  pan.num= 3;
  strcpy(pan.name,"pan");
  pan.size = 12;
  pan.complex = 20;

  Producto cacao;
  cacao.num= 4;
  strcpy(cacao.name,"cacao");
  cacao.size = 15;
  cacao.complex = 21;

  enqueue(cola, cafe);
  enqueue(cola, queso);
  enqueue(cola, jam);
  enqueue(cola, pan);
  enqueue(cola, cacao);

  //val = top(cola);

  //printf("TOPE %c\n", val);

  top(cola);
  dequeue(cola);
  top(cola);
  dequeue(cola);
  top(cola);
  dequeue(cola);
  top(cola);
  dequeue(cola);
  top(cola);
  dequeue(cola);
  dequeue(cola);

  return 0;
}

queue* create_queue(){ //initializes the queue

    queue* cola = malloc (sizeof(queue));

    cola->size = 0;
    cola->head = NULL;
    cola->tail = NULL;

    return cola;

}

void enqueue(queue* q, Producto pro) {

    node* temp = (node*)malloc(sizeof(node)); //allocates

    if ( temp == NULL ) {
        printf("Unable to allocate memory\n");
    }
    else if ((q->size) == 0) {
      temp->next = q->head;
      temp->product = pro;
      //(temp->next)->prev = temp;
      q->head = temp;
      q->head->next = NULL;
      q->tail = temp;
      q->tail->next = NULL;
      q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
    }
    else{
      temp->next = q->tail;
      q->tail->prev = temp;
      temp->product = pro;
      q->tail = temp;
      q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
    }

}

Producto* dequeue(queue* q) {
  int salida = 0;
    if ((q->size) == 0) {
      printf("La cola esta vacia \n");
      return NULL;
    }
    else{
      node* temp;
      node* temp2;

      temp = q->head;
      q->head = q->head->prev;
      temp2 = temp;
      //printf("%p\n", &(temp2->product));
      //Producto casa = (temp2->product);
      //printf("----%s\n", casa.name);
      //q->head = temp->next;
      free(temp);
      q->size = (q->size) - 1; //subtracts from counter
      return &(temp2->product);
    }
}

void top(queue* q) {
    if ((q->size) == 0) {
      printf("La cola esta vacia \n");
    }

    node* temp = q->head;

    Producto value = temp->product;
    printf("%s\n",value.name );

}
