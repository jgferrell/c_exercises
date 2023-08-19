.PHONY : clean

CFLAGS += -std=c99 -g
LDFLAGS +=
OBJFILES := bintree.o main.o ../stack/stack.o
SHAREDLIB := -shared -FPIC

bintree: $(OBJFILES)
	$(CC) $(CFLAGS) -o bintree $(OBJFILES) $(LDFLAGS)
bintree.o: bintree.c bintree.h
	$(CC) $(CFLAGS) -c bintree.c $(SHAREDLIB) -o bintree.o
main.o: main.c bintree.h
	$(CC) $(CFLAGS) -c main.c -o main.o
stack.o: ../stack/stack.c ../stack/stack.h
	$(CC) $(CFLAGS) -c ../stack/stack.c $(SHAREDLIB) -o ../stack/stack.o

clean:
	rm -f ./bintree $(OBJFILES) *~
