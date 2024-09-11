
CC=clang
CFLAGS=-Wall -g

BINS=shim.dylib main.c

all: $(BINS)

main : main.c
	$(CC) $(CFLAGS) -o main main.c

shim.dylib: shim.c
	$(CC) $(CFLAGS) -shared -fPIC shim.c -o shim.dylib -ldl

clean:
	$(RM) $(BINS)
	$(RM) -r *.dSYM
run: shim.dylib
	DYLD_INSERT_LIBRARIES= "/Users/gavintaylormcroy/Desktop/shim-test/shim.dylib" DYLD_FORCE_FLAT_NAMESPACE=1 ./main
