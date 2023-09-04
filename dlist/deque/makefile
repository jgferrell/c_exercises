.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := deque.o main.o ../dlist/dlist.o

deque: $(OBJFILES)
	$(CC) $(CFLAGS) -o deque $(OBJFILES) $(LDFLAGS)
deque.o: deque.c deque.h ../dlist/dlist.h
	$(CC) $(CFLAGS) -c deque.c -shared -FPIC -o deque.o
../dlist/dlist.o: ../dlist/dlist.c ../dlist/dlist.h
	$(CC) $(CFLAGS) -c ../dlist/dlist.c -shared -FPIC -o ../dlist/dlist.o
main.o: main.c deque.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./deque $(OBJFILES) *~ *.gch
