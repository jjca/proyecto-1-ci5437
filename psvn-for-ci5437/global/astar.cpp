#include <stdint.h>
#include "priority_queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include "heuristic.hpp"
using namespace std;

int64_t nodos = 0;
double max_time = 300;
std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point timeout = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point finish = std::chrono::high_resolution_clock::now();

int a_star(state_t start, Heuristic* h){
    ruleid_iterator_t iter;
    state_t state, child;
    int distance, ruleid;
    PriorityQueue<state_t> queue;           // Cola de prioridad con valores f(n) = g(n) + h(n), donde g es el costo acumulado y h es la heuristica
    state_map_t *map = new_state_map();     //Diccionario con costo acumulado para c/estado
    
    queue.Add(h->get_value(start), 0, start);
    state_map_add(map, &start, 0);

    while (!queue.Empty()){
        timeout = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(timeout - start);

        if(time_span.count()> max_time){
            return -1;
        }

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
                char *estado_Ptr;
                char estado[100];
                estado_Ptr = estado;
                const size_t len = 100;
                sprint_state(estado_Ptr,len,&state);
                cout << "Estado meta alcanzado: " << estado << endl;
                cout << "Profundidad: " << distance << endl;
                cout << "Nodos generados: " << nodos << endl;
                return distance; 
            }

            init_fwd_iter(&iter, &state);
            while( (ruleid = next_ruleid(&iter) ) >= 0 ) {
                nodos++;
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
    else if(strcmp(heuristic_type, "-p15") == 0){
        return new Puzzle15PDB();
    }
    else if(strcmp(heuristic_type, "-p24") == 0){
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
        nodos = 0;
        start = std::chrono::high_resolution_clock::now();
        int distance = a_star(state, h);
        finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(timeout - start);
        output_file << content << "    " << distance << "    " << nodos << "    " << duration.count() << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}