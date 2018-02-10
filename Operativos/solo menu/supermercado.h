#include<stdio.h>
#include <string.h>
#include <stdlib.h>
// Conjunto de funciones y estructuras que utiliza el
typedef struct prod{
   int num; // El numero del producto
   char name[15]; // Nombre del Producto
   int size; // tamano del producto
   int complex; // complejidad
}Producto;

int countlines(char *filename){
    FILE *fp;
    int count = 0;  // contador de lineas
    char c;  // To store a character read from file

    // Open the file
    fp = fopen(filename, "r");

    // chequea si el archivo existe
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n'){
            count = count + 1;
        }
    }
    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
};
int read(int numLines, char *filename){
  Producto *arrayP = malloc(numLines * sizeof(Producto));
  int character, whitespace = 0;
  char *line = NULL;
  //char *line2 = NULL;
  size_t len = 0;
  ssize_t read;
  char *token;
  int contador = 0;
  int numero = 0; // numero del producto

  FILE *file = fopen ( filename, "r" );

  if (file == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, file)) != -1) {
		//printf("Retrieved line of length %zu :\n", read);
		//printf("%s", line);
    //line2 = line;
    // contamos la cantidad de tabs en la linea
    /* get the first token */
    //contador = contador+1;
    Producto newProduct;
    token = strtok(line,"\t");
    /* iteramos sobre los otros token */
    while( token != NULL ) {
      if (contador == 0) {
        numero = numero + 1;
        newProduct.num = numero; // es un producto nuevo, le registramos su numero
        strcpy(newProduct.name,token);
        printf("NUMERO %d\n", newProduct.num);
        printf("NOMBRE %s\n", newProduct.name);
      }
      if (contador == 1) {
        newProduct.size = atoi(token);
        printf("TAMANO %d\n",newProduct.size);
      }
      if (contador == 2) {
        newProduct.complex = atoi(token);
        printf("COMPLEX %d\n",newProduct.complex);
        arrayP = &newProduct;
        arrayP++;
      }
      printf("contador %d\n", contador );
      printf( "token %s\n", token );
      token = strtok(NULL,"\t");
      contador++;
    }
    contador = 0; // restablecemos el contador para la siguiente linea
  }

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/* Estructuras */
// PILA --------------------------------------------------------------------------
typedef struct node_{
    Producto product;
    struct node_ *next;
}node;

typedef struct stack_{
    unsigned int size;
    node* head;
}stack;

stack* create_stack(){ //initializes the stack

    stack* pila = malloc (sizeof(stack));

    pila->size = 0;
    pila->head = NULL;

    return pila;

}

void push(stack* s, Producto pro) {

    node* temp = (node*)malloc(sizeof(node)); //allocates

    if ( temp == NULL ) {
        printf("No se puede asignar el espacio de memoria solicitado\n");
    }

    else{
        temp->next = s->head;
        temp->product = pro;
        s->head = temp;
        s->size = (s->size) + 1; //bumps the counter for how many elements are in the stack
    }

}

Producto* pop(stack* s) {

    if ((s->size) == 0) {
      printf("La pila esta vacia \n");
      return NULL;
    }
    else{
      node* temp;
      node* temp2;

      temp = s->head;
      s->head = temp->next;
      s->size = (s->size) - 1; //subtracts from counter
      temp2 = temp;
      //printf("%p\n", &(temp2->product));
      //Producto casa = (temp2->product);
      //printf("%s\n", casa.name);
      free(temp);
      //printf("%s\n", casa.name);
      //printf("%p\n",&(temp2->product) );
      return &(temp2->product);
    }


}

void top(stack* s) {
  if ((s->size) == 0) {
    printf("La pila esta vacia \n");
  }

  else{
    node* temp = s->head;

    Producto value = temp->product;
    printf("%s\n",value.name );
  }
}
/* Prototipos de funciones */

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
