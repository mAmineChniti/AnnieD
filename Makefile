CFLAGS = -Wall -Wextra `sdl-config --cflags`
LIBS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
CONF = `sdl-config --libs` 
CC = gcc
LDFLAGS = $(CONF) $(LIBS)
$(shell mkdir -p obj)


obj/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

obj/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

AnnieD: obj/main.o $(patsubst lib/%.c, obj/%.o, $(wildcard lib/*.c))
	$(CC) $(CFLAGS) $^ -o AnnieD $(LDFLAGS)

exe: cleanall AnnieD

# Clean object files
clean:
	rm -f -r obj/
cleanall:
	rm -f -r obj/ AnnieD