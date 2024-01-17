IDIR =include
CC=gcc
SRCS=game.c
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -lncurses 

_DEPS=defs.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_PEPS=proto.h
PEPS= $(patsubst %,$(IDIR)/%,$(_PEPS))

_OBJ=main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS) $(PEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(SRCS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run: all
	./all
