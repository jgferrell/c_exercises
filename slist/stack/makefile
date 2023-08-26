.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := stack.o main.o ../slist/slist.o

stack: $(OBJFILES)
	$(CC) $(CFLAGS) -o stack $(OBJFILES) $(LDFLAGS)
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -shared -FPIC -o stack.o
../slist/slist.o: ../slist/slist.c ../slist/slist.h
	$(CC) $(CFLAGS) -c ../slist/slist.c -shared -FPIC -o ../slist/slist.o
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./stack $(OBJFILES) *~ *.gch
