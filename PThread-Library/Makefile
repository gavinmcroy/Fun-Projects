CC=gcc
CFLAGS=-Wall -c

BINS=thread_manager.o libmythreads.a

all: $(BINS)

thread_manager.o: mythreads.c mythreads.h
	$(CC) $(CFLAGS) thread_manager.c

libmythreads.a: thread_manager.o 
	ar -cvr libmythreads.a thread_manager.o

clean:
	rm $(BINS)