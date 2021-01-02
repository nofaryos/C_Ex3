CC=gcc
FLAGS=-Wall -g

all : isort txtfind

isort: insertionSort.o 
	$(CC) $(-Wall -g) -o isort insertionSort.o

txtfind: strings.o 
	$(CC) $(-Wall -g) -o txtfind strings.o 	
	
insertionSort.o: insertionSort.c insertionSort.h
	$(CC) $(-Wall -g) -c insertionSort.c
	
strings.o: strings.c strings.h
	$(CC) $(-Wall -g) -c strings.c
	
	
.PHONY: clean

clean:
	rm -f  *.o isort txtfind