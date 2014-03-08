CC=g++
CFLAGS=-Wall -Werror -pedantic -ggdb

# comment?
%: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o core a.out
