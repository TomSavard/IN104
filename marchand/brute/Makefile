CC=gcc
CFLAGS= -Wall -Wextra -pedantic

EXEC=main_brute

SRC_FILES = main_brute.c matrice.c lecture.c utils.c brute.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

all: $(EXEC)

main_brute : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main_brute