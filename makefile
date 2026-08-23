CC = g++ -std=c++98
CFLAGS = -g -Wall 

all: Prog1

Prog1: Prog1.o Support.o
	$(CC) $(CFLAGS) -o Prog1 Prog1.o Support.o

Prog1.o: Support.h Prog1.cpp
	$(CC) $(CFLAGS) -c Prog1.cpp

Support.o: Support.h Support.cpp
	$(CC) $(CFLAGS) -c Support.cpp

clean:
	rm -f Prog1 Prog1.o Support.o