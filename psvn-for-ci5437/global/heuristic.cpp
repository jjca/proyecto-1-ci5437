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

Puzzle24PDB::Puzzle24PDB()
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
};

int Puzzle24PDB::get_value(state_t state)
{
    abstract_state(abts1, &state, &state1);
    abstract_state(abts2, &state, &state2);
    abstract_state(abts3, &state, &state3);

    int value = *state_map_get(piece1, &state1) + *state_map_get(piece2, &state2) + *state_map_get(piece3, &state3);

    return value;
};

Rubik::Rubik()
{
    FILE* file1 = fopen("abst_corner.pdb","r");
    FILE* file2 = fopen("abst_edges_1.pdb","r");
    FILE* file3 = fopen("abst_edges_2.pdb","r");
    FILE* file4 = fopen("abst_edges_3.pdb","r");
    FILE* file5 = fopen("abst_edges_4.pdb","r");
    FILE* file6 = fopen("abst_edges_5.pdb","r");
    FILE* file7 = fopen("abst_edges_6.pdb","r");
    FILE* file8 = fopen("abst_edges_7.pdb","r");
    FILE* file9 = fopen("abst_edges_8.pdb","r");

    abts1 = read_abstraction_from_file("abst_corner.abst");
    abts2 = read_abstraction_from_file("abst_edges_1.abst");
    abts3 = read_abstraction_from_file("abst_edges_2.abst");
    abts4 = read_abstraction_from_file("abst_edges_3.abst");
    abts5 = read_abstraction_from_file("abst_edges_4.abst");
    abts6 = read_abstraction_from_file("abst_edges_5.abst");
    abts7 = read_abstraction_from_file("abst_edges_6.abst");
    abts8 = read_abstraction_from_file("abst_edges_7.abst");
    abts9 = read_abstraction_from_file("abst_edges_8.abst");

    piece1 = read_state_map(file1);
    piece2 = read_state_map(file2);
    piece3 = read_state_map(file3);
    piece4 = read_state_map(file4);
    piece5 = read_state_map(file5);
    piece6 = read_state_map(file6);
    piece7 = read_state_map(file7);
    piece8 = read_state_map(file8);
    piece9 = read_state_map(file9);

    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    fclose(file7);
    fclose(file8);
    fclose(file9);
}
int Rubik::get_value(state_t state)
{
    abstract_state(abts1, &state, &state1);
    abstract_state(abts2, &state, &state2);
    abstract_state(abts3, &state, &state3);
    abstract_state(abts4, &state, &state4);
    abstract_state(abts5, &state, &state5);
    abstract_state(abts6, &state, &state6);
    abstract_state(abts7, &state, &state7);
    abstract_state(abts8, &state, &state8);
    abstract_state(abts9, &state, &state9);

    int value = std::max({*state_map_get(piece1, &state1),*state_map_get(piece2, &state2),*state_map_get(piece3, &state3),*state_map_get(piece4, &state4),*state_map_get(piece5, &state5),
    *state_map_get(piece6, &state6),*state_map_get(piece7, &state7),*state_map_get(piece8, &state8),*state_map_get(piece9, &state9)});

    return value;
};

TopSpin::TopSpin()
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
};

int TopSpin::get_value(state_t state)
{
    abstract_state(abts1, &state, &state1);
    abstract_state(abts2, &state, &state2);
    abstract_state(abts3, &state, &state3);

    int value = std::max({*state_map_get(piece1, &state1),*state_map_get(piece2, &state2),*state_map_get(piece3, &state3)});

    return value;   
};

Hanoi::Hanoi()
{
    FILE* file1 = fopen("abst_1.pdb","r");
    FILE* file2 = fopen("abst_2.pdb","r");

    abts1 = read_abstraction_from_file("abst_1.abst");
    abts2 = read_abstraction_from_file("abst_2.abst");

    piece1 = read_state_map(file1);
    piece2 = read_state_map(file2);

    fclose(file1);
    fclose(file2);
};

int Hanoi::get_value(state_t state)
{
    abstract_state(abts1, &state, &state1);
    abstract_state(abts2, &state, &state2);

    int value = std::max({*state_map_get(piece1, &state1),*state_map_get(piece2, &state2)});

    return value;   
};