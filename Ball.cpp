#include "Ball.h"
Ball::Ball()
{
    x=0, y=0;
    dx=0, dy=0;
    g=15;
    dt=0.032;
}
Ball::~Ball()
{
    //SDL_DestroyTexture(p_object_);
    //p_object_=NULL;
}
bool Ball:: LoadImg(string path, SDL_Renderer* screen)
{
    SDL_DestroyTexture(p_object_);
    bool ret=BaseObject::LoadImageA(path, screen);
    if(ret==true)
        return true;
    return false;
}
void Ball:: show(SDL_Renderer* des)
{

    bool check=LoadImg("image/Ball.png", des);
    if(check==true)
    {
        SDL_Rect renderquad= {x,y, 40, 40};
        SDL_RenderCopy(des, p_object_, NULL, &renderquad);
    }
}
int  Ball::check_collision(charactor player)
{
    float left_a=player.getX(), right_a=player.getX()+70, top_a=player.getY(), bottom_a=player.getY()+120;
    float left_b=x, right_b=x+40, top_b=y, bottom_b=y+40;
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return 1;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return 1;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return 1;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return 1;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return 1;
        }
    }
    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return 1;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return 1;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return 1;
        }
    }
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return 1;
    }


    if(y>430||y<0)
        return 2 ;
    if(x<78||x>1021-40)
        return 3;

}
int Ball:: check_collision_bac()
{
    float top_a1=362, bottom_a1=470, right_a1=165, left_a1=78;
    float top_a2=362, bottom_a2=470, right_a2=1021, left_a2=937;
    float left_b=x, right_b=x+40, top_b=y, bottom_b=y+40;
    if(left_b>left_a1&&left_b<right_a1)
    {
        if(bottom_b>top_a1&&bottom_b<bottom_a1)
            return 1;

    }
    if(right_b>left_a2&&right_b<right_a2)
    {
        if(bottom_b>top_a2&&bottom_b<bottom_a2)
            return 2;
    }

}
int Ball:: check_collision_goal()
{
    float top_g1=217, bottom_g1=362, right_g1=142, left_g1=78;
    float top_g2=217, bottom_g2=362, right_g2=1021, left_g2=957;
    float left_b=x, right_b=x+40, top_b=y, bottom_b=y+40;
    if(left_b>left_g1&&left_b<right_g1)
    {
        if(bottom_b>top_g1&&bottom_b<bottom_g1)
            return 1;
    }
    if(right_b>left_g2&&right_b<right_g2)
    {
        if(bottom_b>top_g2&&bottom_b<bottom_g2)
            return 2;
    }
}
void Ball::ball_action(charactor player)
{

    if(abs(dx)<10)
        dx=0;
    dy =dy - g*dt;
    x =x+dx*dt;
    y = y-dy*dt+g*dt*dt/2;
    float top_g1=217, bottom_g1=362, right_g1=142, left_g1=78;
    float top_g2=217, bottom_g2=362, right_g2=1021, left_g2=957;
    float top_a1=362, bottom_a1=470, right_a1=165, left_a1=78;
    float top_a2=362, bottom_a2=470, right_a2=1021, left_a2=937;
    float left_b=x, right_b=x+40, top_b=y, bottom_b=y+40;
    if(check_collision(player)==1)
    {

        if(x>player.getX()+40&&player.turn_right==1)
        {
            if(player.player_pick==2)
            {
                if(player.kick==1)
                {

                    dx=-80*cos(20*PI/180);
                    dy=80*sin(20*PI/180);
                }
                else if(player.ulti==1)
                {
                    dx=-300*cos(0*PI/180);
                    dy=300*sin(0*PI/180);
                }
                else if(player.super_kick==1)
                {
                    dx=-120*cos(20*PI/180);
                    dy=120*sin(20*PI/180);
                }
            }
            if(player.player_pick==1)
            {
                if(player.kick==1)
                {

                    dx=80*cos(20*PI/180);
                    dy=80*sin(20*PI/180);
                }
                else if(player.ulti==1)
                {
                    dx=300*cos(0*PI/180);
                    dy=300*sin(0*PI/180);
                }
                else if(player.super_kick==1)
                {
                    dx=120*cos(20*PI/180);
                    dy=120*sin(20*PI/180);
                }
            }
            g=10;
        }
        else if(x<player.getX()+40&&player.turn_left==1)
        {
            if(player.player_pick==2)
            {
                if(player.kick==1)
                {

                    dx=-80*cos(20*PI/180);
                    dy=80*sin(20*PI/180);
                }
                else if(player.ulti==1)
                {
                    dx=-300*cos(0*PI/180);
                    dy=300*sin(0*PI/180);
                }
                else if(player.super_kick==1)
                {
                    dx=-120*cos(20*PI/180);
                    dy=120*sin(20*PI/180);
                }
            }
            if(player.player_pick==1)
            {
                if(player.kick==1)
                {
                    dx=80*cos(20*PI/180);
                    dy=80*sin(20*PI/180);
                }
                else if(player.ulti==1)
                {
                    dx=300*cos(0*PI/180);
                    dy=300*sin(0*PI/180);
                }
                else if(player.super_kick==1)
                {
                    dx=120*cos(20*PI/180);
                    dy=120*sin(20*PI/180);
                }

            }
            g=10;
        }

    }
    if(check_collision_bac()==1)
    {

        if(right_b>right_a1)
        {

            x=right_a1;

            dx=-dx/1.5;

        }
        else
        {
            if(y>top_a1-40)
                y=top_a1-40;
            dy=-dy;
        }
        left_b=x, right_b=x+40, top_b=y, bottom_b=y+40;
    }
    else if(check_collision_bac()==2)
    {

        if(left_b<left_a2)
        {
            x=left_a2-40;
            dx=-dx/1.5;

        }
        else
        {
            if(y>top_a2-40)
                y=top_a2-40;
            dy=-abs(dy);
        }
    }
    if(check_collision_goal()==1)
    {

        if(right_b<=right_g1)
        {

            if(y>top_g1-40&&y<top_g1-10)
            {
                y=top_g1-40;
                dy=-abs(dy);
            }
        }
        else
        {
            if(top_b<230)
            {
                if(x<right_g1)
                {
                    x=right_g1;
                }
                dx=-dx/1.5;
            }

        }
    }
    else if(check_collision_goal()==2)
    {

        if(left_b>=left_g2)
        {
            if(y>top_g2-40&&y<top_g2-10)
            {
                y=top_g2-40;
                dy=-abs(dy);
            }

        }
        else
        {
            if(top_b<230)
            {
                if(x>left_g2-40)
                    x=left_g2-40;
                dx=-dx/1.5;
            }
        }
    }
    if(check_collision(player)==2)
    {
        if(y>430)
            y=430;
        else
            y=0;
        dy=-dy;

    }
    if(check_collision(player)==3)
    {
        if(x>1021-40)
            x=1021-40;
        else
            x=78;
        dx=-dx/1.01;


    }


}
void Ball::shot_on(charactor &player1, charactor &player2)
{

    player1_shoton=0;
    player2_shoton=0;
    if(y<=362&&y>=234)
    {

        if(x<142||x>937)
        {
            i++;
            if(x<142)
            {
                player1_shoton=1;
                dx=-2;
                x=78;
            }
            else if(x>937)
            {
                player2_shoton=1;
                dx=2;
                x=1021-40;
            }
            if(i==3)
            {
                set_first_pos();
                player1.player1_set_first_pos();
                player2.player2_set_first_pos();
                SDL_Delay(2000);
                i=0;

            }
        }
    }

}


