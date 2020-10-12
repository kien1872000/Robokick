#include <iostream>
#include "TextObject.h"
#include "charactor.h"
#include "Ball.h"
#include "commonfunction.h"
using namespace std;
BaseObject background;
TTF_Font* font_time=NULL;
TTF_Font* font_goals=NULL;
TTF_Font* font_win=NULL;
bool initSDL()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {

        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    window=SDL_CreateWindow("Robo Kick", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window==NULL)
    {
        success=false;
    }
    else
    {
        screen=SDL_CreateRenderer(window, 1, SDL_RENDERER_ACCELERATED);
        if(screen==NULL)
        {
            success=false;
        }
        else
        {
            SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
            int imgFlags=IMG_INIT_PNG;

            if(!(IMG_Init(imgFlags)&&imgFlags))
            {

                success=false;
            }
        }
        if(TTF_Init()==-1)
        {

            success=false;
        }
        font_time=TTF_OpenFont("font-times-new-roman.ttf", 60);
        font_goals=TTF_OpenFont("font-times-new-roman.ttf", 30);
        font_win=TTF_OpenFont("font-times-new-roman.ttf", 30);
    }

    return success;
}
bool LoadBackGround()
{
    bool ret=background.LoadImageA("image/Background.png", screen);
    if(ret==false)
        return false;
    return true;
}
void close()
{
    background.free();
    SDL_DestroyRenderer(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
}
int main(int argc, char *argv[])
{
    if(initSDL()==false)
        return 0;
    if(LoadBackGround()==false)
        return 0;
    BaseObject goal1, goal2;
    goal1.goal=1;
    goal2.goal=2;
    goal1.LoadImageA("image/GoalL.png", screen);
    goal2.LoadImageA("image/GoalR.png", screen);
    bool not_quit=true;
    Ball bong;
    TextObject time;
    TextObject goals1, goals2;
    TextObject win;
    goals1.type_text=1, goals2.type_text=1;
    goals1.goal=1, goals2.goal=2;
    charactor player1, player2, player1_pow, player2_pow;
    player1_pow.BaseObject::LoadImageA("image/NoCharge.png", screen);
    player2_pow.BaseObject::LoadImageA("image/NoCharge.png", screen);
    float y1=345, x1=135, a=200, b=430, y2=y1, x2=870;
    player1.player1_set_first_pos();
    player2.player2_set_first_pos();
    player2.turn_right=0;
    player1.player_pick=1;
    player2.player_pick=2;
    bong.set_first_pos();
    while(not_quit)
    {
        SDL_RenderClear(screen);
        while(SDL_PollEvent(&event)!=0)
        {
            if(event.type==SDL_QUIT)
                not_quit=false;
            player2.Move(event);
            player1.Move(event);
        }
        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        bong.ball_action(player1);
        bong.ball_action(player2);
        player1.player_action();
        player2.player_action();
        background.Render(screen);
        player1_pow.show_pow(screen, player1);
        player2_pow.show_pow(screen, player2);
        player1.show(screen);
        player2.show(screen);
        bong.show(screen);
        goal1.show_goal(screen);
        goal2.show_goal(screen);
        goals1.show_text_time_goals(font_goals,screen, bong);
        goals2.show_text_time_goals(font_goals, screen, bong);
        win.show_text_win(font_win,screen, time, goals1, goals2, player1, player2, bong);
        bong.shot_on(player1, player2);
        time.show_text_time_goals(font_time, screen, bong);
        SDL_RenderPresent(screen);
    }
    close();
    return 0;
}
