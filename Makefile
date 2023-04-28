CC=gcc -std=c17
CFLAGS=-g

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

EXE=main

all: $(EXE)

$(EXE):	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

run: $(EXE)
	./$(EXE)


#all: lista_inteiros.o main.o
#	gcc lista_inteiros.o main.o -o lista_inteiros

#lista_inteiros.o: lista_inteiros.c lista_inteiros.h
#	gcc -c lista_inteiros.c -o lista_inteiros.o

#main.o: main.c
#gcc -c main.c -o main.o

#clean:
#	rm *.o lista_inteiros