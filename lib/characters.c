#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "characters.h"

int collision(character character1, img img1) {
    // Calculate the boundaries of the character and the image
    int char_left = character1.img.pos.x;
    int char_right = char_left + character1.img.pos.w;
    int char_top = character1.img.pos.y;
    int char_bottom = char_top + character1.img.pos.h;

    int img_left = img1.pos.x;
    int img_right = img_left + img1.pos.w;
    int img_top = img1.pos.y;
    int img_bottom = img_top + img1.pos.h;

    // Check for collision by comparing the boundaries
    if (char_left < img_right && char_right > img_left && 
        char_top < img_bottom && char_bottom > img_top) {
        // Collision detected
        return 1;
    } else {
        // No collision detected
        return 0;
    }
}