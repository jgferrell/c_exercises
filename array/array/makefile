.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := array.o main.o

array: $(OBJFILES)
	$(CC) $(CFLAGS) -o array $(OBJFILES) $(LDFLAGS)
array.o: array.c array.h
	$(CC) $(CFLAGS) -c array.c -shared -FPIC -o array.o
main.o: main.c array.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./array $(OBJFILES) *~ *.gch
