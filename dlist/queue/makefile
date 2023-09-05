.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := queue.o main.o ../dlist/dlist.o

queue: $(OBJFILES)
	$(CC) $(CFLAGS) -o queue $(OBJFILES) $(LDFLAGS)
queue.o: queue.c queue.h ../dlist/dlist.h
	$(CC) $(CFLAGS) -c queue.c -shared -FPIC -o queue.o
../dlist/dlist.o: ../dlist/dlist.c ../dlist/dlist.h
	$(CC) $(CFLAGS) -c ../dlist/dlist.c -shared -FPIC -o ../dlist/dlist.o
main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./queue $(OBJFILES) *~ *.gch
