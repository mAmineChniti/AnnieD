#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "img.h"
#include "text.h"

#define SCREEN_H 800
#define SCREEN_W 1200

int init(void);

int check_mouse_collision(img img);
int check_point_collision(img img, int x, int y);
int check_button_change(img img, int x, int y);

#endif