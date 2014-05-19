CC = g++
CFLAGS = -Wall -Werror -pedantic -ggdb -std=c++11
SRC_FILES = orig.cpp dynamic-array.cpp
OUT_EXE = friend_list

# build: $(SRC_FILES)
# $(CC) $(CFLAGS) -o $(OUT_EXE) $(SRC_FILES)	

build: dynamic-array.o orig.o
	$(CC) *.o -o $(OUT_EXE)

dynamic-array.o: dynamic-array.cpp
	$(CC) $(CFLAGS) -c dynamic-array.cpp

orig.o: orig.cpp
	$(CC) $(CFLAGS) -c orig.cpp

clean: 
	rm -f *.o core friend_list

rebuild: clean build
