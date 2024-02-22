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

Puzzle15PDB::Puzzle15PDB()
{
    FILE* file1 = fopen("abst_1.pdb","r");
    FILE* file2 = fopen("abst_2.pdb","r");
    FILE* file3 = fopen("abst_3.pdb","r");

    abts1 = read_abstraction_from_file("abst_1.abst");
    abts2 = read_abstraction_from_file("abst_2.abst");
    abts3 = read_abstraction_from_file("abst_3.abst");

    piece1 = read_state_map(file1);
    piece2 = read_state_map(file2);
    piece3 = read_state_map(file3);

    fclose(file1);
    fclose(file2);
    fclose(file3);

}

int Puzzle15PDB::get_value(state_t state)
{
    abstract_state(abts1, &state, &state1);
    abstract_state(abts2, &state, &state2);
    abstract_state(abts3, &state, &state3);

    int value = *state_map_get(piece1, &state1) + *state_map_get(piece2, &state2) + *state_map_get(piece3, &state3);

    return value;
}
