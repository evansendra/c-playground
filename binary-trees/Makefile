CC=g++
CFLAGS=-Wall -Werror -pedantic -ggdb -std=c++11

# comment?
%: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o core a.out
