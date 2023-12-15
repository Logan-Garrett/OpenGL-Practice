CC = gcc # compiler
CFLAGS = -Wall -g # Compilation Flags
LIBS = -lGL -lGLU -lglut -lm

all: main

main: main.o
	$(CC) -o main main.c $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f main *.o *~
