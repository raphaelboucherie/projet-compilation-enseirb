CFLAGS = -Wall -Wextra -std=c99
BUILDAPP = $$HOME/save/try/buildapp-1.4.2/buildapp

OBJ_FILES = \
	initmap.o \
	mixcards.o \

CLEANFILES = *~ \

all: $(OBJ_FILES)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	@rm -f $(OBJ_FILES) *~ 
