# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# SDL libraries
SDL_LIBS = -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image

# Directories
SRC_DIR = .
LIB_DIR = lib
BUILD_DIR = build

# Targets
EXECUTABLE = program
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
LIB_SOURCES = $(wildcard $(LIB_DIR)/*.c)
LIB_OBJECTS = $(LIB_SOURCES:$(LIB_DIR)/%.c=$(BUILD_DIR)/%.o)

# Rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(LIB_OBJECTS)
	$(CC) $(CFLAGS) $^ $(SDL_LIBS) -o $@

$(OBJECTS): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_OBJECTS): $(BUILD_DIR)/%.o : $(LIB_DIR)/%.c $(LIB_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)

