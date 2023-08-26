.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := deque.o main.o ../slist/slist.o

deque: $(OBJFILES)
	$(CC) $(CFLAGS) -o deque $(OBJFILES) $(LDFLAGS)
deque.o: deque.c deque.h ../slist/slist.h
	$(CC) $(CFLAGS) -c deque.c -shared -FPIC -o deque.o
../slist/slist.o: ../slist/slist.c ../slist/slist.h
	$(CC) $(CFLAGS) -c ../slist/slist.c -shared -FPIC -o ../slist/slist.o
main.o: main.c deque.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./deque $(OBJFILES) *~ *.gch
