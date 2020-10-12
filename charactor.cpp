#include "charactor.h"
charactor::charactor()
{
    var_x=0;
    var_y=0;
    pos_x=0;
    pos_y=0;
    frame_width=0;
    frame_heigth=0;
    frame_ani=0;
}
charactor::~charactor()
{

}

bool charactor::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_DestroyTexture(p_object_);

    bool ret=BaseObject::LoadImageA(path, screen);
    if(ret==true)
    {
        frame_width=rect_.w/4;
        frame_heigth=rect_.h;
    }
    return ret;
}
void charactor::set_animation()
{
    animation_[0].x=0;
    animation_[0].y=0;
    animation_[0].w=frame_width;
    animation_[0].h=frame_heigth;

    animation_[1].x=frame_width;
    animation_[1].y=0;
    animation_[1].w=frame_width;
    animation_[1].h=frame_heigth;

    animation_[2].x=frame_width*2;
    animation_[2].y=0;
    animation_[2].w=frame_width;
    animation_[2].h=frame_heigth;

    animation_[3].x=frame_width*3;
    animation_[3].y=0;
    animation_[3].w=frame_width;
    animation_[3].h=frame_heigth;

}
void charactor::show(SDL_Renderer* des)
{
    wait_time++;
    if(wait_time==11)
        wait_time=0;
    if(player_pick==1)
    {
        if(first==0)
            LoadImg("image/P1_move_right.png", des);
        if(move_right==1)
            LoadImg("image/P1_move_right.png", des);
        else if(move_left==1)
            LoadImg("image/P1_move_left.png", des);

        if(kick==1||ulti==1||super_kick==1)
        {
            if(turn_right==1)
                LoadImg("image/P1_kick_right.png", des);
            else if(turn_left==1)
                LoadImg("image/P1_kick_left.png", des);
        }
        if(kick!=1&&ulti!=1&&super_kick!=1)
        {
            if(turn_right==1)
                LoadImg("image/P1_move_right.png", des);
            else if(turn_left==1)
                LoadImg("image/P1_move_left.png", des);
        }
    }
    if(player_pick==2)
    {
        if(first==0)
            LoadImg("image/P2_move_left.png", des);
        if(move_right==1)
            LoadImg("image/P2_move_right.png", des);
        else if(move_left==1)
            LoadImg("image/P2_move_left.png", des);

        if(kick==1||super_kick==1||ulti==1)
        {
            if(turn_right==1)
                LoadImg("image/P2_kick_right.png", des);
            else if(turn_left==1)
                LoadImg("image/P2_kick_left.png", des);
        }
        if(kick!=1&&ulti!=1&&super_kick!=1)
        {
            if(turn_right==1)
                LoadImg("image/P2_move_right.png", des);
            else if(turn_left==1)
                LoadImg("image/P2_move_left.png", des);
        }
    }
    set_animation();

    if(move_right==1||move_left==1||kick==1||ulti==1||super_kick==1)
    {
        if(wait_time==10)
        {
            frame_ani++;

        }
    }

    if(frame_ani>=3)
        frame_ani=0;

    SDL_Rect* ani=&animation_[frame_ani];
    ani=&animation_[frame_ani];

    SDL_Rect renderquad= {pos_x,pos_y, frame_width, frame_heigth};
    SDL_RenderCopy(des, p_object_, ani, &renderquad);
    SDL_DestroyTexture(p_object_);
}

void charactor::Move(SDL_Event event)
{
    if(player_pick==1)
    {
        if(event.type==SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_d:
                move_right=1;
                turn_right=1;
                turn_left=0;
                first=1;
                move_left=0;
                break;
            case SDLK_a:
                move_left=1;
                turn_left=1;
                turn_right=0;
                first=1;
                move_right=0;
                break;
            case SDLK_w:
                check_jump=1;
                break;
            case SDLK_u:
                check_kick=1;
                break;
            case SDLK_o:
                check_pow=1;
                break;
            case SDLK_i:
                check_super_kick=1;
                break;
            }

        }
        else if(event.type==SDL_KEYUP)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_d:
                move_right=0;
                frame_ani=0;
                break;
            case SDLK_a:
                move_left=0;
                frame_ani=0;
                break;
            case SDLK_w:
                check_jump=0;
                break;
            case SDLK_u:
                check_kick=0;
                first_jump=0;
                break;
            case SDLK_o:
                check_pow=0;
                break;
            case SDLK_i:
                check_super_kick=0;
                break;
            }
        }
    }
    else if(player_pick==2)
    {
        if(event.type==SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                move_right=1;
                turn_right=1;
                turn_left=0;
                first=1;
                move_left=0;
                break;
            case SDLK_LEFT:
                move_left=1;
                turn_left=1;
                turn_right=0;
                first=1;
                move_right=0;
                break;
            case SDLK_UP:
                check_jump=1;
                break;
            case SDLK_KP_4:
                check_kick=1;
                break;
            case SDLK_KP_6:
                check_pow=1;
                break;
            case SDLK_KP_5:
                check_super_kick=1;
                break;
            }

        }
        else if(event.type==SDL_KEYUP)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                move_right=0;
                frame_ani=0;
                break;
            case SDLK_LEFT:
                move_left=0;
                frame_ani=0;
                break;
            case SDLK_UP:
                check_jump=0;
                break;
            case SDLK_p:
                check_kick=0;
                break;
            case SDLK_KP_4:
                check_kick=0;
                break;
            case SDLK_KP_6:
                check_pow=0;
                break;
            case SDLK_KP_5:
                check_super_kick=0;
                break;
            }
        }
    }

}
void charactor:: player_action()
{
    charge++;
    if(first_kick==1)
    {
        if(time_kick<30)
            time_kick++;
        else if(time_kick==30)
        {
            if(check_super_kick==1)
                super_kick=1;
            if(check_pow==1&&pow==1)
                ulti=1;
            if(check_kick==1)
                kick=1;
            first_kick=0;
        }

    }
    else if(first_kick==0)
    {
        if(check_super_kick==1)
            super_kick=1;
        if(check_pow==1&&pow==1)
            ulti=1;
        if(check_kick==1)
            kick=1;
    }

    if(first_jump==1)
    {
        if(time_jump<15)
        {
            time_jump++;
        }
        else if(time_jump==15)
        {
            if(check_jump==1)
                move_up=1;
            first_jump==0;
        }
    }
    else if(first_jump==0)
    {
        if(check_jump==1)
            move_up=1;
    }

    if(charge==2000)
    {
        pow=1;
    }

    if(kick==1||ulti==1||super_kick==1)
    {
        if(kick==1)
        {
            first_kick=1;
            super_kick=0;
            ulti=0;
        }
        else if(ulti==1)
        {
            pow=0;
            charge=0;
            super_kick=0;
            kick=0;

        }
        else if(super_kick==1)
        {
            first_kick=1;
            kick=0;
            ulti=0;
        }
        time_to_kick++;
        if(time_to_kick==25)
        {
            time_to_kick=1;
            ulti=0;
            kick=0;
            super_kick=0;
            time_kick=0;
        }
    }

    if(move_right==1)
    {
        if(pos_x>870)
            pos_x=870;
        else
            pos_x=pos_x+3;
    }
    if(move_left==1)
    {
        if(pos_x<135)
            pos_x==135;
        else
            pos_x=pos_x-3;
    }
    if(move_up==1)
    {
        first_jump=1;
        if(len!=200)
        {
            pos_y=340-len;
            len=len+5;
        }
        else
        {
            if(xuong!=210)
            {
                pos_y=140+xuong;
                xuong=xuong+5;
            }
            else
            {
                len=0;
                xuong=0;
                move_up=0;
                time_jump=0;

            }

        }
    }
}
void charactor::show_pow(SDL_Renderer* des, charactor player)
{
    if(player.pow==0)
    {
        if(player.player_pick==1)
        {
            SDL_Rect renderquad= {3,515, 94, 94};
            SDL_RenderCopy(des, p_object_, NULL, &renderquad);
        }
        else if(player.player_pick==2)
        {
            SDL_Rect renderquad= {1001,515, 94, 94};
            SDL_RenderCopy(des, p_object_, NULL, &renderquad);
        }
    }
}




