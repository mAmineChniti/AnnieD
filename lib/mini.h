#ifndef MINI_H
#define MINI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "img.h"
#include "characters.h"
typedef struct {
    img img;
}minimap;
typedef struct {
    img img;
}miniplayer;
void init_minimap(minimap *m);
void init_miniplayer(minimap *m, character player);
#endif