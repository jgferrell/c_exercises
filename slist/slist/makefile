.PHONY : clean

CFLAGS += -Wall -std=c99 -g
LDFLAGS +=
OBJFILES := slist.o main.o

slist: $(OBJFILES)
	$(CC) $(CFLAGS) -o slist $(OBJFILES) $(LDFLAGS)
slist.o: slist.c slist.h
	$(CC) $(CFLAGS) -c slist.c -shared -FPIC -o slist.o
main.o: main.c slist.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f ./slist $(OBJFILES) *~ *.gch
