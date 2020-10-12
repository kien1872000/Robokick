#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "BaseObject.h"
#include "charactor.h"
#include <cmath>
#include <string>
#include "commonfunction.h"
using namespace std;
class Ball:public BaseObject
{
    float x, y;
    float dx, dy;
    float g;
    float dt;
public:
    int player1_win=0;
    int player2_win=0;
    int player1_shoton=0;
    int player2_shoton=0;
    int delay_time=0;
    int real_time=0;

    int i=0;
    Ball();
    ~Ball();
    bool LoadImg(string path, SDL_Renderer* screen);
    void show(SDL_Renderer* des);
    int check_collision(charactor player);
    int check_collision_bac();
    int check_collision_goal();

    void ball_action(charactor player);
    void set_first_pos()
    {
        x=531;
        y=250;
        dx=0;
        dy=0;
        g=15;
    }
    void shot_on(charactor &player1, charactor &player2);
    //int check_win(TextObject goal1, TextObject goal2, TextObject Time);
};
#endif // BALL_H_INCLUDED
