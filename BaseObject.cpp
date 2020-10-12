#include "commonfunction.h"
#include "BaseObject.h"
using namespace std;
BaseObject::BaseObject()
{
    p_object_=NULL;
    rect_.x=0;
    rect_.y=0;
    rect_.h=0;
    rect_.w=0;
}
BaseObject::~BaseObject()
{
    // delete p_object_;
    p_object_=NULL;
}
bool BaseObject::LoadImageA(string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture=NULL;
    SDL_Surface* load_surface=IMG_Load(path.c_str());
    if(load_surface!=NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, color_key_R,color_key_G, color_key_B));
        new_texture=SDL_CreateTextureFromSurface(screen, load_surface);
        if(new_texture!=NULL)
        {
            rect_.w=load_surface->w;
            rect_.h=load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    p_object_=new_texture;
    if(p_object_==NULL)
        return false;
    return true;
}
void BaseObject::Render(SDL_Renderer* des)
{
    SDL_Rect renderquad= {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_object_, NULL, &renderquad);

}
void BaseObject::show_goal(SDL_Renderer* des)
{
    if(goal==1)
    {
        SDL_Rect renderquad= {50,217, 95, 156};
        SDL_RenderCopy(des, p_object_, NULL, &renderquad);
    }
    else if(goal==2)
    {
        SDL_Rect renderquad= {958, 217, 95, 156};
        SDL_RenderCopy(des, p_object_, NULL, &renderquad);
    }
}
void BaseObject:: free()
{
    if(p_object_!=NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_=NULL;
        rect_.w=0;
        rect_.h=0;
    }
}
