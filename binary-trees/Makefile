CC=g++
CFLAGS=-Wall -Werror -pedantic -ggdb -std=c++11

# comment?
# %: %.cpp
# 	$(CC) $(CFLAGS) -o $@ $<

build: bintree.o treetest.o
	$(CC) $(CFLAGS) *.o -o bintree

treetest.o: treetest.cpp
	$(CC) $(CFLAGS) -c treetest.cpp

bintree.o: bintree.cpp
	$(CC) $(CFLAGS) -c bintree.cpp

clean:
	rm -rf *.o core bintree

rebuild: clean build
