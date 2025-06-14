CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o queue.o
	$(CC) $(CFLAGS) -o main_program main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c -o queue.o queue.c

clear:
	del /Q main_program.exe *.o
