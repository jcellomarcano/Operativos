# Archivo con las instrucciones para compilar los
# archivos de codigo fuente y crear el ejecutable.


CC = gcc
CFLAGS = -g -pthread -Wall -Wextra
DEPS = supermercado.h
OBJETOS = Menu.o pruebaMenu.o
PROGRAMA = Menu

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

default: Menu
Menu: $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	-rm -f $(OBJETOS)
	-rm -f $(PROGRAMA)
