#ifndef CHARACTOR_H_INCLUDED
#define CHARACTOR_H_INCLUDED
#include "BaseObject.h"
#include "commonfunction.h"
#include <iostream>
using namespace std;
class charactor: public BaseObject
{
    float var_x;
    float var_y;
    float pos_x;
    float pos_y;
    SDL_Rect animation_[4];
    int frame_ani;
    int frame_width;
    int frame_heigth;
public:
    charactor();
    ~charactor();
    int check_kick=0;
    int check_jump=0;
    int move_right=0;
    int move_left=0;
    int move_up=0;
    int first=0;
    int len=0;
    int xuong=0;
    int time_to_kick=1;
    int wait_time=0;
    int kick=0;
    int super_kick=0;
    int check_super_kick=0;
    int turn_right=1;
    int turn_left=0;
    int player_pick=0;
    int charge=0;
    int pow=0;
    int check_pow=0;
    int ulti=0;
    int first_kick=0;
    int first_jump=0;
    int time_jump=0;
    int time_kick=0;



    bool LoadImg(std::string path, SDL_Renderer* screen);
    void set_animation();
    void show(SDL_Renderer* des);
    void Move(SDL_Event even);
    void set_pos(float &y, float &x)
    {
        pos_y=y;
        pos_x=x;
    }
    void  player_action();
    float getX()
    {
        return pos_x;
    }
    float getY()
    {
        return pos_y;
    }
    void show_pow(SDL_Renderer* des, charactor player);
    void player1_set_first_pos()
    {
        pos_x=135;
        pos_y=345;
        turn_right=1;
        turn_left=0;
        check_jump=0;
    }
    void player2_set_first_pos()
    {
        pos_x=870;
        pos_y=345;
        turn_right=0;
        turn_left=1;
        check_jump=0;
    }





};



#endif // CHARACTOR_H_INCLUDED
