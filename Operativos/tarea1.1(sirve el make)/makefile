# Archivo con las instrucciones para compilar los
# archivos de codigo fuente y crear el ejecutable.


CC = gcc
CFLAGS = -g -pthread -Wall -Wextra
DEPS = supermercado.h
OBJETOS = supermercado.o Menu.o ListaEnlazadaOrdenada.o Pila.o ColaDePilas.o BandaTransportadora.o Lectura.o
PROGRAMA = supermercado

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

default: supermercado
supermercado: $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	-rm -f $(OBJETOS)
	-rm -f $(PROGRAMA)
