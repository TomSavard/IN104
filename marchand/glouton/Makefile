CC=gcc
CFLAGS= -Wall -Wextra -pedantic

EXEC=main_glouton

SRC_FILES = main_glouton.c matrice.c lecture.c utils.c glouton.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

all: $(EXEC)

main_glouton : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main_glouton