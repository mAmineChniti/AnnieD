#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "img.h"
#include "characters.h"
#include "mini.h"

void init_minimap(minimap *mm,char *path, SDL_Surface *screen){
    mm->img.image=IMG_Load(path);
    if(mm->img.image==NULL)printf("Unable to load background image %s \n",SDL_GetError());
    mm->img.pos.x = screen->w - mm->img.image->w;
    mm->img.pos.y = screen->w - mm->img.image->w;
} // use load_img from img.c to show minimap

void init_miniplayer(miniplayer *mp, char *path){
    mp->img.image=IMG_Load(path);
    if(mp->img.image==NULL)printf("Unable to load background image %s \n",SDL_GetError());
}

void update_miniplayer(minimap *mm,miniplayer *mp,character *player, SDL_Surface *screen){
    float scale_factor = (float) mm->img.image->w / (float)screen->w;
    mp->img.pos.x = player->img.pos.x * scale_factor + mm->img.pos.x;
    mp->img.pos.y = player->img.pos.y * scale_factor + mm->img.pos.y;
    SDL_BlitSurface(mp->img.image,NULL,screen,&mp->img.pos);
}