#ifndef _HEURISTIC_HPP
#define _HEURISTIC_HPP

#include <utility>
#include <stdlib.h>
#include <iostream>

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

class Puzzle15PDB: public Heuristic{
public:
    Puzzle15PDB();
    int get_value(state_t state);

    

private:
    state_map_t* piece1;
    state_map_t* piece2;
    state_map_t* piece3; 

    abstraction_t* abts1;
    abstraction_t* abts2;
    abstraction_t* abts3;

    state_t state1;
    state_t state2;
    state_t state3;
};



#endif