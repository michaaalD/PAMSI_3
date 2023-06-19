#pragma once
#ifndef GAME_AI
#define GAME_AI
#include "../inc/game.h"

class Game_ai : public Game 
{
private:
    int x;         
    int y;         
    int depth_limit;  // maksymalna glebokosc rekursji  
public:
    Game_ai(int depth_limit) : depth_limit(depth_limit) {}; // konstruktor 
    int min_max(Game game, int depth, int alpha, int beta, bool maximizing)const; 
    void move(Game game); 
    int get_x() const { return x; }  //getter x
    int get_y() const { return y; }  // getter y
};
#endif