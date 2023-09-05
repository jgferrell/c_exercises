.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := stack.o main.o ../dlist/dlist.o

stack: $(OBJFILES)
	$(CC) $(CFLAGS) -o stack $(OBJFILES) $(LDFLAGS)
stack.o: stack.c stack.h ../dlist/dlist.h
	$(CC) $(CFLAGS) -c stack.c -shared -FPIC -o stack.o
../dlist/dlist.o: ../dlist/dlist.c ../dlist/dlist.h
	$(CC) $(CFLAGS) -c ../dlist/dlist.c -shared -FPIC -o ../dlist/dlist.o
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./stack $(OBJFILES) *~ *.gch
