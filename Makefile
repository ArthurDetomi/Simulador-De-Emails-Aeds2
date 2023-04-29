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