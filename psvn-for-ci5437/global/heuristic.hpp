#ifndef _HEURISTIC_HPP
#define _HEURISTIC_HPP

#include <utility>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

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

class Puzzle24PDB: public Heuristic{
public:
    Puzzle24PDB();
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

class Rubik: public Heuristic{
public:
    Rubik();
    int get_value(state_t state);

    

private:
    state_map_t* piece1;
    state_map_t* piece2;
    state_map_t* piece3;
    state_map_t* piece4; 
    state_map_t* piece5; 
    state_map_t* piece6; 
    state_map_t* piece7; 
    state_map_t* piece8; 
    state_map_t* piece9; 

    abstraction_t* abts1;
    abstraction_t* abts2;
    abstraction_t* abts3;
    abstraction_t* abts4;
    abstraction_t* abts5;
    abstraction_t* abts6;
    abstraction_t* abts7;
    abstraction_t* abts8;
    abstraction_t* abts9;

    state_t state1;
    state_t state2;
    state_t state3;
    state_t state4;
    state_t state5;
    state_t state6;
    state_t state7;
    state_t state8;
    state_t state9;
};

class TopSpin: public Heuristic{
public:
    TopSpin();
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