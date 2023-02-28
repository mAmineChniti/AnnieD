CFLAGS = -I ./lib -O2 -Wall -Wextra

LIBS = -lSDL_image -lSDL_mixer -lSDL_ttf

INCLUDED = lib/functions.c lib/img.c lib/text.c lib/characters.c

# Linux 32-bit
LIN32_CC = gcc -m32
LIN32_CFLAGS = $(CFLAGS)
LIN32_LDFLAGS = $(LIBS)

# Linux 64-bit
LIN64_CC = gcc -m64
LIN64_CFLAGS = $(CFLAGS)
LIN64_LDFLAGS = $(LIBS)

# Windows 32-bit
WIN32_CC = i686-w64-mingw32-gcc
WIN32_CFLAGS = $(CFLAGS)
WIN32_LDFLAGS = $(LIBS) -lmingw32 -mwindows

# Windows 64-bit
WIN64_CC = x86_64-w64-mingw32-gcc
WIN64_CFLAGS = $(CFLAGS)
WIN64_LDFLAGS = $(LIBS) -lmingw32 -mwindows

# Compile all the C files in the lib directory into object files
LIB_OBJECTS = $(patsubst %.c,%.o,$(wildcard lib/*.c))

# Rule to compile object files in the lib directory
lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@

main_lin32.o: main.c
	$(LIN32_CC) $(LIN32_CFLAGS) -c $< -o $@ $(LIN32_LDFLAGS)

main_lin64.o: main.c
	$(LIN64_CC) $(LIN64_CFLAGS) -c $< -o $@ $(LIN64_LDFLAGS)

main_win32.o: main.c
	$(WIN32_CC) $(WIN32_CFLAGS) -c $< -o $@ $(WIN32_LDFLAGS)

main_win64.o: main.c
	$(WIN64_CC) $(WIN64_CFLAGS) -c $< -o $@ $(WIN64_LDFLAGS)

AnnieD_lin32: main_lin32.o $(LIB_OBJECTS)
	$(LIN32_CC) $^ -o AnnieD_lin32 $(LIN32_LDFLAGS)

AnnieD_lin64: main_lin64.o $(LIB_OBJECTS)
	$(LIN64_CC) $^ -o AnnieD_lin64  $(LIN64_LDFLAGS)

lin: AnnieD_lin32 AnnieD_lin64

AnnieD_win32.exe: main_win32.o $(LIB_OBJECTS)
	$(WIN32_CC) $(WIN32_LDFLAGS) $^ -o AnnieD_win32.exe

AnnieD_win64.exe: main_win64.o $(LIB_OBJECTS)
	$(WIN64_CC) $(WIN64_LDFLAGS) $^ -o AnnieD_win64.exe

win: AnnieD_win32.exe AnnieD_win64.exe

both: win lin

# Clean object files
clean:
	rm -f *.o lib/*.o
	rm -rf exe
	mkdir exe
	mv AnnieD* exe/
