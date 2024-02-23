#include <stdint.h>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include "priority_queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "heuristic.hpp"
using namespace std;


Heuristic* get_heuristic(const char* heuristic_type){
    if(strcmp(heuristic_type, "-m") == 0){
        return new ManhattanHeuristic();
    }
    else if(strcmp(heuristic_type, "-p15") == 0){
        return new Puzzle15PDB();
    }else if(strcmp(heuristic_type, "-p24") == 0){
        return new Puzzle24PDB();
    }
    else if(strcmp(heuristic_type, "-r") == 0){
        return new Rubik();
    }
    else if(strcmp(heuristic_type, "-ts") == 0){
        return new TopSpin();
    }

    return NULL;
}

int64_t nodos = 0;

Heuristic* h = get_heuristic("-m");

pair<bool, unsigned int> f_bounded_dfs_visit(unsigned int bound, unsigned int g, state_t state){
    ruleid_iterator_t iterator;
    int cost, rule_id;
    unsigned int t = INT_MAX;
    // Casos base:
    //const char* heuristic_type = argv[3];
    int state_h = h->get_value(state);
    unsigned int f = g + state_h;
    if (f > bound){
        return make_pair(false,f);
    }

    if (is_goal(&state)) {
        char *estado_Ptr;
        char estado[100];
        estado_Ptr = estado;
        const size_t len = 100;
        sprint_state(estado_Ptr,len,&state);
        cout << "Estado meta alcanzado: " << estado << endl;
        pair p = make_pair(true,f);
        cout << "Profundidad: " << bound << endl;
        cout << "Nodos generados: " << nodos << endl;
        return p;
    }
    // Inicializa el metodo para ir hacia adelante
    init_fwd_iter(&iterator, &state);
    while ((rule_id = next_ruleid(&iterator)) >= 0){
        nodos++;
        state_t child;
        int child_cost = g + get_fwd_rule_cost(rule_id);
        apply_fwd_rule(rule_id,&state,&child);
        if (h->get_value(state) < t){
            pair<bool,unsigned int> p = f_bounded_dfs_visit(bound,child_cost,child);
            if (p.first) {
                return p;
            }
            t = min(t,p.second);
        } 
    }
    return make_pair(false,t);
    
}


int idastar(state_t start) {
    // Heuristica
    unsigned int bound = h->get_value(start);
    while(1){
        pair<bool,unsigned int> p = f_bounded_dfs_visit(bound,0,start);
        if (p.first){
            return p.second;
        }
        bound = p.second;
    }

}

int main(int argc, char **argv) {
    if(argc < 4) {
        cout << "Missing arguments. Try running ./<program>.idastar <input_file> <output_file> -<flag> \n";
        return 0;
    }

    string content;
    ifstream input_file;
    ofstream output_file;
    state_t state; 

    input_file.open(argv[1]);
    output_file.open(argv[2]);

    output_file << "Instance    Distance\n";
    output_file << "-----------------------------------------------------------------------------\n";

    const char* heuristic_type = argv[3];
    Heuristic* h =  get_heuristic(heuristic_type);

    while (getline (input_file, content)) {
        ssize_t chars = read_state(content.c_str(), &state);

        if( chars <= 0 ) {
            cout << "Error: invalid state entered.\n";
            continue;
        }

        cout << "Solving " << content << "\n";
        nodos = 0;
        int distance = idastar(state);
        nodos = 0;
        output_file << content << "    " << distance << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}