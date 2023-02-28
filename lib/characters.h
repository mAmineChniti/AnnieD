#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "img.h"
typedef struct {
    int hp;
    int lives;
    img img;    
}character;
int collision(character character1, img img1);

#endif
