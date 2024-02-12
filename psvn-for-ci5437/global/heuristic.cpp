#include "heuristic.hpp"

ManhattanHeuristic::ManhattanHeuristic() {

    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = count != 16 ? count : 0;
            count += 1;
        }
        
    }
    
}

int ManhattanHeuristic::get_value(state_t state){

    int mhd = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::pair<int, int> goal_position = find_goal(state.vars[i*4 + j]);
            if(goal_position.first != -1){
                mhd += abs(i - goal_position.first) + abs(j - goal_position.second);
            }
        }
        
    }
    return mhd;

}

std::pair<int, int> ManhattanHeuristic::find_goal(int value) {

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(board[i][j] == value){
                return std::make_pair(i,j);
            }
        }
        
    }
    return std::make_pair(-1,-1);
}

