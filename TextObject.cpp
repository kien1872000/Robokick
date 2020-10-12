#include "TextObject.h"
TextObject::TextObject()
{
    time="00";
    goals="00";
    win="win";
    text=NULL;
}
TextObject::~TextObject()
{

}
void TextObject:: increase_one(string &str)
{
    int integer;
    int n=str.length();
    for(int i=0; i<n; i++)
    {
        integer=integer*10+str[i]-48;
    }
    integer=integer+1;
    for(int i=n-1; i>=0; i--)
    {
        str[i]=(char)((integer%10)+48);
        integer=integer/10;
    }
}
int TextObject::check_win(TextObject goal1, TextObject goal2, TextObject Time)
{
    if(Time.get_time()=="91")
    {
        if(goal1.get_goals()>goal2.get_goals())
            return -1;
        else if(goal1.get_goals()==goal2.get_goals())
            return 0;
        else
            return 1;
    }
}
bool TextObject::LoadTextTimeGoals( SDL_Renderer *screen, TTF_Font* font, Ball ball)
{
    SDL_DestroyTexture(text);
    SDL_Surface* surface=NULL;
    if(type_text==0) // text thoi gian
    {
        count_time++;
        if(count_time==100)
        {
            increase_one(time);

            count_time=1;
        }
        surface = TTF_RenderText_Solid(font, time.c_str(), RED_COLOR);
    }
    else if(type_text==1) // text ti so
    {
        if(ball.player1_shoton==1&&goal==2)
        {
            i++;
            if(i==3)
            {
                increase_one(goals);
                i=0;
            }

        }
        else if(ball.player2_shoton==1&&goal==1)
        {
            i++;
            if(i==3)
            {
                increase_one(goals);
                i=0;
            }
        }
        surface = TTF_RenderText_Solid(font, goals.c_str(),WHITE_COLOR);
    }

    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(screen, surface);
    SDL_FreeSurface(surface);
    text=new_texture;
    if(text==NULL)
    {
        return false;
    }
    return true;
}
void TextObject::show_text_time_goals(TTF_Font* font, SDL_Renderer *screen, Ball ball)
{
    if(LoadTextTimeGoals( screen, font, ball)==true)
    {
        SDL_Rect srcRest;
        SDL_Rect desRect;
        if(type_text==0)
        {
            TTF_SizeText(font, time.c_str(), &srcRest.w, &srcRest.h);
            srcRest.x = 0;
            srcRest.y =  0;
            desRect.x = 531;
            desRect.y = 0;
            desRect.w = srcRest.w;
            desRect.h = srcRest.h;
            SDL_RenderCopy(screen, text, &srcRest, &desRect);
        }
        else if(type_text==1)
        {

            if(goal==2)
            {
                TTF_SizeText(font, goals.c_str(), &srcRest.w, &srcRest.h);
                srcRest.x = 0;
                srcRest.y =  0;
                desRect.x = 561;
                desRect.y = 570;
                desRect.w = srcRest.w;
                desRect.h = srcRest.h;
                SDL_RenderCopy(screen, text, &srcRest, &desRect);
            }
            else if(goal==1)
            {
                TTF_SizeText(font, goals.c_str(), &srcRest.w, &srcRest.h);
                srcRest.x = 0;
                srcRest.y =  0;
                desRect.x = 501;
                desRect.y = 570;
                desRect.w = srcRest.w;
                desRect.h = srcRest.h;
                SDL_RenderCopy(screen, text, &srcRest, &desRect);
            }

        }
    }

}
bool TextObject::LoadTextWin(SDL_Renderer* screen, TTF_Font *font, TextObject goal1, TextObject goal2, TextObject time_)
{
    SDL_DestroyTexture(text);
    SDL_Surface* surface=NULL;
    if(time_.get_time()=="90")
    {
        if(goal1.get_goals()>goal2.get_goals())
        {
            win="P1 win";
        }
        else if(goal1.get_goals()<goal2.get_goals())
        {
            win="P2 win";
        }
        else
        {
            win="Draw";
        }

    }
    surface = TTF_RenderText_Solid(font, win.c_str(), YELLOW_COLOR);
    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(screen, surface);
    SDL_FreeSurface(surface);
    text=new_texture;
    if(text==NULL)
    {
        return false;
    }
    return true;
}
void TextObject::show_text_win(TTF_Font* font, SDL_Renderer* screen, TextObject &time_, TextObject &goal1, TextObject &goal2, charactor &player1, charactor &player2, Ball &ball)

{

    if(LoadTextWin(screen, font, goal1, goal2, time_)==true)
    {
        if(time_.get_time()=="90")
        {

            SDL_Rect srcRest;
            SDL_Rect desRect;
            TTF_SizeText(font, win.c_str(), &srcRest.w, &srcRest.h);
            srcRest.x = 0;
            srcRest.y =  0;
            desRect.x = 520;
            desRect.y = 60;
            desRect.w = srcRest.w;
            desRect.h = srcRest.h;
            SDL_RenderCopy(screen, text, &srcRest, &desRect);
            check_loop++;
            if(check_loop==2)
            {
                time_.set_time();
                goal1.set_goals();
                goal2.set_goals();
                ball.set_first_pos();
                player1.player1_set_first_pos();
                player2.player2_set_first_pos();
                Sleep(3000);
                check_loop=0;
            }

        }

    }

}
