IDIR   = include
CC 	   = gcc
CFLAGS = -I$(IDIR) -std=c99

ODIR   = obj
LDIR   = lib
SDIR   = src
BDIR   = bin

LIBS   = -llibtcod

_DEPS  = ini.h libtcod.h strdef.h engine.h rendering.h input.h menu.h gamestate.h party.h map.h game.h mainmenu.h chargen.h combat.h util.h
DEPS   = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ   = ini.o engine.o rendering.o input.o menu.o gamestate.o party.o map.o mainmenu.o chargen.o game.o combat.o util.o icon.res
OBJ    = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/dwemrakraftaz: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -L$(LDIR) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~