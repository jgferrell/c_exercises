.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := dlist.o main.o

dlist: $(OBJFILES)
	$(CC) $(CFLAGS) -o dlist $(OBJFILES) $(LDFLAGS)
dlist.o: dlist.c dlist.h
	$(CC) $(CFLAGS) -c dlist.c -shared -FPIC -o dlist.o
main.o: main.c dlist.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./dlist $(OBJFILES) *~ *.gch
