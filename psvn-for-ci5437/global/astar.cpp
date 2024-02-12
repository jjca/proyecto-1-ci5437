#include <stdint.h>
#include "priority_queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "heuristic.hpp"

int a_star(state_t start, Heuristic* h){
    ruleid_iterator_t iter;
    state_t state, child;
    int distance, ruleid;
    PriorityQueue<state_t> queue;           // Cola de prioridad con valores f(n) = g(n) + h(n), donde g es el costo acumulado y h es la heuristica
    state_map_t *map = new_state_map();     //Diccionario con costo acumulado para c/estado
    
    queue.Add(h->get_value(start), 0, start);
    state_map_add(map, &start, 0);

    while (!queue.Empty()){
        distance = queue.CurrentPriority(); 
        state = queue.Top();
        queue.Pop();

        const int *cost_so_far = state_map_get(map, &state);

        //Condiciones:
        //1) Si es Null, no hemos pasado por el estado actual
        //2)Conseguimos una distancia mas corta a la que teniamos guardada
        //3)Si nos ecnontramos en el estado incial, necesitamos que entre en la condicion
        if ((cost_so_far == NULL) || (distance < *cost_so_far) || !compare_states(&state, &start)) {
            state_map_add(map, &state, distance);

            if (is_goal(&state)) {
                return distance; 
            }

            init_fwd_iter(&iter, &state);
            while( (ruleid = next_ruleid(&iter) ) >= 0 ) {
                apply_fwd_rule(ruleid, &state, &child);
                const int child_d = distance + get_fwd_rule_cost(ruleid);

                int child_h = h->get_value(child);

                if(child_h < INT32_MAX){
                    queue.Add(child_d + child_h, child_d, child);
                }
            }
            
        }
    }
    return -1;
}

Heuristic* get_heuristic(const char* heuristic_type){
    if(strcmp(heuristic_type, "-m") == 0){
        return new ManhattanHeuristic();
    }

    return NULL;
}

int main(int argc, char **argv) {
    if(argc < 4) {
        std::cout << "Missing arguments. Try running ./<program>.astar <input_file> <output_file> -<flag>";
        return 0;
    }

    std::string content;
    std::ifstream input_file;
    std::ofstream output_file;
    state_t state; 

    input_file.open(argv[1]);
    output_file.open(argv[2]);

    output_file << "Instance    Distance\n";
    output_file << "-----------------------------------------------------------------------------\n";

    const char* heuristic_type = argv[3];
    Heuristic* h =  get_heuristic(heuristic_type);

    while (std::getline (input_file, content)) {
        ssize_t chars = read_state(content.c_str(), &state);

        if( chars <= 0 ) {
            std::cout << "Error: invalid state entered.\n";
            continue;
        }

        std::cout << "Solving " << content << "\n";

        int distance = a_star(state, h);

        output_file << content << "    " << distance << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}