#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

static SDL_Window* window=NULL;
static SDL_Renderer* screen=NULL;
static SDL_Event event;


const float PI=3.14;
const int SCREEN_WIDTH=1102;
const int SCREEN_HEIGHT=620;

const int color_key_R=195;
const int color_key_G=195;
const int color_key_B=195;

const int RENDER_DRAW_COLOR=0XFF;
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};










#endif // CONSTANT_H_INCLUDED
