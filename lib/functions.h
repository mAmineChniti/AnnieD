#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 800
#define SCREEN_W 1200

typedef struct{
    SDL_Rect pos;
    SDL_Surface* image;
}img;

typedef struct{
    SDL_Surface *text;
	SDL_Rect pos;
	SDL_Colour color;
	TTF_Font* font;
}txt;
 
void load_img(img* img, char* path, int x, int y);
void display_img(SDL_Surface* screen, img img);
void free_img(img img);

void load_txt(txt* txt, int x, int y, int r, int g, int b, char* font, int size);
void print_txt(SDL_Surface* screen, txt* txt, char* message);
void free_txt(txt txt);

int check_mouse_collision(img img);
int check_point_collision(img img, int x, int y);
int check_button_change(img img, int x, int y);

#endif