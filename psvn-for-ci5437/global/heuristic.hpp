#ifndef _HEURISTIC_HPP
#define _HEURISTIC_HPP

#include <utility>
#include <stdlib.h>

class Heuristic
{
public:
    virtual int get_value(state_t state) = 0;
    
};

class ManhattanHeuristic:public Heuristic{
public:
    ManhattanHeuristic();
    int get_value(state_t state);
private:
    std::pair<int, int> find_goal(int value);

private:
    int board[4][4];
};

#endif