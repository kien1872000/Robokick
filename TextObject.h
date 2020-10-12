#ifndef TEXTOBJECT_H_INCLUDED
#define TEXTOBJECT_H_INCLUDED
#include <string>
#include <iostream>
#include <string.h>
#include <SDL_image.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "commonfunction.h"
#include "Ball.h"
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;
class TextObject
{
    string time;
    string goals;
    string win;
    SDL_Texture *text;

public:
    int type_text=0;
    int count_time=1;
    int goal=1;
    int check_loop=0;

    int i=0;
    TextObject();
    ~TextObject();
    string get_goals()
    {
        return goals;
    }
    string get_time()
    {
        return time;
    }
    void increase_one(string &str);
    int check_win(TextObject goal1, TextObject goal2, TextObject Time);
    void set_time()
    {
        time="00";
    }
    void set_goals()
    {
        goals="00";
    }
    bool LoadTextTimeGoals(  SDL_Renderer *screen, TTF_Font *font, Ball ball);
    bool LoadTextWin(SDL_Renderer* screen, TTF_Font *font, TextObject goal1, TextObject goal2, TextObject time);
    void show_text_time_goals(TTF_Font* font, SDL_Renderer *screen, Ball ball);
    void show_text_win(TTF_Font* font, SDL_Renderer* screen, TextObject &time_, TextObject &goal1, TextObject &goal2, charactor &player1, charactor &player2, Ball &ball);

};


#endif // TEXTOBJECT_H_INCLUDED
