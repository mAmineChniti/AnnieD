#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "functions.h"


void load_img(img* img, char* path, int x, int y)
{
    img->image=IMG_Load(path);
    if(img->image==NULL)printf("Unable to load background image %s \n",SDL_GetError());
    img->pos.x=x;
    img->pos.y=y;
}

void display_img(SDL_Surface *screen, img img)
{
    SDL_BlitSurface(img.image,NULL,screen,&img.pos);
}

void free_img(img img){
    SDL_FreeSurface(img.image);
}

void load_txt(txt *txt, int x, int y, int r, int g, int b, char *font, int size)
{
    txt->font=TTF_OpenFont(font,size);
    txt->color.r=r;
    txt->color.g=g;
    txt->color.b=b;
    txt->pos.x=x;
    txt->pos.y=y;
}

void print_txt(SDL_Surface *screen, txt *txt, char *message)
{
    txt->text=TTF_RenderText_Blended(txt->font,message,txt->color);
    SDL_BlitSurface(txt->text,NULL,screen,&txt->pos);
}

void free_txt(txt txt)
{
    SDL_FreeSurface(txt.text);
	TTF_CloseFont(txt.font);
}

int check_mouse_collision(img img)
{
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    if(mx>=img.pos.x && mx<=img.pos.x+img.image->w && my>=img.pos.y && my<=img.pos.y+img.image->h)return(1);
    return(0);
}

int check_point_collision(img img, int x, int y)
{
    if(x>=img.pos.x && x<=img.pos.x+img.image->w && y>=img.pos.y && y<=img.pos.y+img.image->h)return(1);
    return 0;
}

int check_button_change(img img, int x, int y)
{
    //checks if the button currently pressed changed, for sound playing purposes
    if(check_mouse_collision(img)!=check_point_collision(img,x,y))return 1;
    return 0;
}