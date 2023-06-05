#pragma once
#include "board.h"

class Computer : public Board 
{
private:
    int x, y;
    int depth_limit;  // maksymalna glebokosc rekursji  
public:
    Computer(int depth_limit) : depth_limit(depth_limit) {};
    int min_max(Board _board, int depth, int alpha, int beta, bool maximizing) const; // gracz - max, ai - min
    void move(Board _board);
    int get_x() const { return x; }
    int get_y() const { return y; }

};
