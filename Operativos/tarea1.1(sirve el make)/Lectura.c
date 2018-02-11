/*
 * Archivo: Lectura.c
 * Descripcion: Cola de pilas.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "supermercado.h"

int countlines(char *filename){

    FILE *fp;
    int count = 0;  // contador de lineas
    char c;  // To store a character read from file

    // Open the file
    fp = fopen(filename, "r");

    // chequea si el archivo existe
    if (fp == NULL)
    {
        printf("Could not open file %s\n", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
}

Producto* read(int numLines, char *filename){

    Producto *arrayP = malloc(numLines * sizeof(Producto));
    Producto *InicioArray = arrayP;

    int character, whitespace = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    int contador = 0;
    int numero = 0; // numero del producto

    FILE *file = fopen (filename, "r");

    if (file == NULL)
    {
      exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) 
    {
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
        // contamos la cantidad de tabs en la linea
        /* get the first token */
        Producto newProduct;
        token = strtok(line,"\t");

        /* iteramos sobre los otros token */
        while(token != NULL) 
        {
            if (contador == 0) 
            {
                numero = numero + 1;
                newProduct.num = numero; // es un producto nuevo, le registramos su numero
                strcpy(newProduct.name,token);
                //printf("NUMERO %d\n", newProduct.num);
                //printf("NOMBRE %s\n", newProduct.name);
            }

            if (contador == 1) 
            {
                newProduct.size = atoi(token);
                //printf("TAMANO %d\n",newProduct.size);
            }

            if (contador == 2) 
            {
                newProduct.complex = atoi(token);
                //printf("COMPLEX %d\n",newProduct.complex);
                *arrayP = newProduct;
                arrayP++;
            }

        //printf("contador %d\n", contador );
        //printf( "token %s\n", token );
        token = strtok(NULL,"\t");
        contador++;
        }

        contador = 0; // restablecemos el contador para la siguiente linea
    }

    free(line);
    fclose(file);
    return InicioArray;

}