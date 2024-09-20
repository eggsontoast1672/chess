CFLAGS = -Iinclude

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,%.o,$(SOURCES))

# This is chess.exe right now because there's already a directory called
# 'chess' that I don't want to be overwritten.
all: chess.exe

%.o: src/%.c
	$(CC) -c $(CFLAGS) -o $(@) $(^)

chess.exe: $(OBJECTS)
	$(CC) -o $(@) $(^)

clean:
	$(RM) $(OBJECTS) chess.exe

.PHONY: all clean
