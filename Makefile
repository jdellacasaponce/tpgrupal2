BIN = Programa
OBJ = main.o afd.o
CFLAGS = -std=c23
RM = rm -f
CC = gcc

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

main.o: main.c afd.h
	$(CC) -c main.c -o main.o $(CFLAGS)

afd.o: afd.c afd.h
	$(CC) -c afd.c -o afd.o $(CFLAGS)

.PHONY: run clean

run: $(BIN)
	./$(BIN) $(FILE)

clean:
	$(RM) $(BIN) $(OBJ)
