CC=gcc
CFLAGS= -Wall -Wextra -pedantic

EXEC=main_dijkstra

SRC_FILES = main_dijkstra.c dijkstra.c matrice.c lecture.c utils.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

all: $(EXEC)

main_dijkstra : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main_dijkstra