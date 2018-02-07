#include<stdio.h>
#include <string.h>
#include <stdlib.h>
// “\t”
typedef struct prod{
   char  name[15];
   int  size;
   int  complex;
}Producto;

int countlines(char *filename){
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file

    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

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
    //newProduct.nombre = token;
    /* iteramos sobre los otros token */
    while( token != NULL ) {
      if (contador == 0) {
        //newProduct.name = token;
        strcpy(newProduct.name,token);
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

void main(int argc, char *argv[])
{
  int lines;
  lines = countlines(argv[1]);
  printf("LINES: %d\n",lines);
  printf("Lineas \n");
  read(lines,argv[1]);
}
