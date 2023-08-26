.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := queue.o main.o ../slist/slist.o

queue: $(OBJFILES)
	$(CC) $(CFLAGS) -o queue $(OBJFILES) $(LDFLAGS)
queue.o: queue.c queue.h ../slist/slist.h
	$(CC) $(CFLAGS) -c queue.c -shared -FPIC -o queue.o
../slist/slist.o: ../slist/slist.c ../slist/slist.h
	$(CC) $(CFLAGS) -c ../slist/slist.c -shared -FPIC -o ../slist/slist.o
main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./queue $(OBJFILES) *~ *.gch
