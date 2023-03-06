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
void init_minimap(minimap *mm, char *path, SDL_Surface *screen);
void init_miniplayer(miniplayer *mp,char *path);
void update_miniplayer(minimap * mm, miniplayer *mp, character *player, SDL_Surface *screen);
#endif