CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LIBS = -lm

SRC_FILES = main_bellman.c bellman.c matrice.c lecture.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

all: main_bellman

main_bellman: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main_bellman