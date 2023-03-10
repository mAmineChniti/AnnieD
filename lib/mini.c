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

void update_time(int pause, minimap *mm, Uint32 start_time, SDL_Event event) {
    txt timertxt;
    char time_str[20];
    load_txt(&timertxt, mm->img.pos.x + 10, mm->img.pos.y + 10, 255, 255, 255, "fonts/pixel_arial.ttf", 10);

    while (!pause) {
        Uint32 current_time = SDL_GetTicks();
        Uint32 elapsed_time = (current_time - start_time) / 1000;
        sprintf(time_str, "%02d:%02d", elapsed_time / 60, elapsed_time % 60);
        print_txt(mm->img.image, &timertxt, time_str);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                pause = 1;
            }
        }
    }
}

Uint32 get_pixel(SDL_Surface *surface, int x, int y){
    Uint32 *pixels = (Uint32 *)surface->pixels;
    return pixels[y * surface->w + x];
}

void minimap_maker(minimap *mm, SDL_Surface *screen, int pause, SDL_Event event){
    int block_size = 5;
    int screen_width = screen->w;
    int screen_height = screen->h;
    SDL_Surface *minimap_surface = SDL_CreateRGBSurface(0, screen_width/block_size, screen_height/block_size, 32, 0, 0, 0, 0);
    while(!pause){
        for (int y = 0; y < screen_height; y += block_size) {
            for (int x = 0; x < screen_width; x += block_size) {
                SDL_Rect rect = {x/block_size, y/block_size, 1, 1};
                Uint32 pixel = get_pixel(screen, x, y);
                if (pixel != SDL_MapRGB(screen->format, 0, 0, 0)) {
                    SDL_FillRect(minimap_surface, &rect, SDL_MapRGB(screen->format, 0, 255, 0));
                }
            }
        }
        SDL_BlitSurface(mm->img.image, NULL, minimap_surface, NULL);
        SDL_Rect minimap_pos = {mm->img.pos.x, mm->img.pos.y, 0, 0};
        SDL_BlitSurface(minimap_surface, NULL, screen, &minimap_pos);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                pause = 1;
            }
        }
    }
    // SDL_FreeSurface(minimap_surface);
}