#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "img.h"
#include "characters.h"
#include "mini.h"
#include "text.h"

void init_minimap(minimap *mm, char *path, SDL_Surface *screen){
    mm->img.image=IMG_Load(path);
    if(mm->img.image==NULL)printf("Unable to load image %s \n",SDL_GetError());
    mm->img.pos.x = screen->w - mm->img.image->w;
    mm->img.pos.y = screen->w - mm->img.image->w;
}

void init_miniplayer(miniplayer *mp, char *path){
    mp->img.image=IMG_Load(path);
    if(mp->img.image==NULL)printf("Unable to load image %s \n",SDL_GetError());
}

void update_miniplayer(minimap *mm, miniplayer *mp, character *player, SDL_Surface *screen){
    float scale_factor = (float) mm->img.image->w / (float)screen->w;
    mp->img.pos.x = player->img.pos.x * scale_factor + mm->img.pos.x;
    mp->img.pos.y = player->img.pos.y * scale_factor + mm->img.pos.y;
    SDL_BlitSurface(mp->img.image,NULL,screen,&mp->img.pos);
}

void update_time(int pause, minimap *mm, Uint32 *start_time) {
    txt timertxt;
    char time_str[20];
    load_txt(&timertxt, mm->img.pos.x + 10, mm->img.pos.y + 10, 255, 255, 255, "fonts/pixel_arial.ttf", 10);
    if(!pause) {
        Uint32 current_time = SDL_GetTicks();
        Uint32 elapsed_time = (current_time - (*start_time)) / 1000;
        sprintf(time_str, "%02d:%02d", elapsed_time / 60, elapsed_time % 60);
        print_txt(mm->img.image, &timertxt, time_str);
    }else{
        (*start_time) = SDL_GetTicks();
    }
}

void minimap_maker(minimap *mm, SDL_Surface *screen, img *Tiles, int TilesNum, int pause){
    float scale_factor = (float) mm->img.image->w / (float)screen->w;
    if(!pause){
        for (int i = 0; i < TilesNum; i++) {
            int x = (int)(Tiles[i].pos.x / scale_factor);
            int y = (int)(Tiles[i].pos.y / scale_factor);
            int w = (int)(Tiles[i].pos.w / scale_factor);
            int h = (int)(Tiles[i].pos.h / scale_factor);
            SDL_Rect tile_rect = {x, y, w ,h};
            SDL_FillRect(mm->img.image, &tile_rect, SDL_MapRGB(screen->format, 0, 255, 0));
        }
        SDL_BlitSurface(mm->img.image, NULL, screen, &(mm->img.pos));
    }
}
