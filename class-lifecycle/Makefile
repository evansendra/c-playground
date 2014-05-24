CC = g++
CFLAGS = -Wall -Werror -pedantic -ggdb 

build: VectorInt.o
	$(CC) $(CFLAGS) *.o -o VectorInt

VectorInt.o: VectorInt.cpp
	$(CC) $(CFLAGS) -c VectorInt.cpp

rebuild: clean build

clean: 
	rm -rf *.o VectorInt
