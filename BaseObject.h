#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_tff.h>
#include <string>
#include <iostream>
class BaseObject
{
protected:
    SDL_Texture *p_object_;
    SDL_Rect rect_;
public:
    int goal=0;
    BaseObject();
    ~BaseObject ();
    void setRect(const int &x, const int&y)
    {
        rect_.x=x;
        rect_.y=y;
    }
    SDL_Rect getRect() const
    {
        return rect_;
    }
    SDL_Texture* getObject() const
    {
        return p_object_;
    }
    virtual bool LoadImageA (std::string path, SDL_Renderer *screen);
    void Render(SDL_Renderer* des);
    void show_goal(SDL_Renderer* des);
    void free();
};


#endif // DRAW_H_INCLUDED

