IDIR =../include
CC=gcc
CFLAGS= -ftest-coverage -fprofile-arcs -I$(IDIR) 

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = contador.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = teste_contador.o contador.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste_pilha: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
