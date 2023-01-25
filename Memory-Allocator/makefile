CC=gcc

all:  allocator.c
	make library

library: allocator.c
	$(CC) -O2 -DNDEBUG -Wall -fPIC -shared allocator.c -o libmyalloc.so

test: allocator.c test.c
	$(CC) -g -o test test.c allocator.c

pkg: allocator.c allocator.h README makefile
	tar cvzf project3.tgz README makefile allocator.c allocator.h

clean:
	rm -rf *.a
	rm -rf *.o
	find . -type f -name '*~' -delete
	rm -rf test
	rm -rf project3.tgz
	rm -rf libmyalloc.so