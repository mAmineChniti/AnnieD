CFLAGS = -Wall -Wextra `sdl-config --cflags`
LIBS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
CONF = `sdl-config --libs` 
CC = gcc
LDFLAGS = $(CONF) $(LIBS)


lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

AnnieD: main.o $(patsubst lib/%.c, lib/%.o, $(wildcard lib/*.c))
	$(CC) $(CFLAGS) $^ -o AnnieD $(LDFLAGS)

all: AnnieD

# Clean object files
clean:
	rm -f *.o lib/*.o