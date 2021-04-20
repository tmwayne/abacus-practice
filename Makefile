P=abacus-practice
OBJECTS=
CFLAGS=-g -pedantic -gdwarf-2 -g3 -Wall -O0
CPPFLAGS=-I ~/.local/include
LDFLAGS=-L ~/.local/lib -Wl,-rpath=/home/tyler/.local/lib
LDLIBS=-lm -lconfigparse
CC=gcc

$(P): $(OBJECTS)

clean: 
	-rm *.o

run: $(P)
	./$(P) $(PARGS)

