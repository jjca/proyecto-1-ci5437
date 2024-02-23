#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int bfs(state_t *goal, int pruning) { 
    state_t state;
    state_t child;
    queue<int> queue_history;
    queue<state_t> queue;
    ruleid_iterator_t iterator;
    
    int number_of_childs;
    int number_of_childs_per_depth;
    int ruleid = 0;
    int depth = 0;
    int history = init_history;
    queue_history.push(history);
    queue.push(*goal);
    printf("Profundidad | Nodos | BF \n");
    while (!queue.empty())
    {
        number_of_childs_per_depth = queue.size();
        number_of_childs = 0;
        for (int i = 0; i < number_of_childs_per_depth; i++){
            state = queue.front();
            queue.pop();
            
            init_bwd_iter(&iterator,&state);
            if (pruning) {
                history = queue_history.front();
                queue_history.pop();    
                while ((ruleid = next_ruleid(&iterator)) >= 0) {
                    if (bwd_rule_valid_for_history(history,ruleid) == 0) continue;
                    apply_bwd_rule(ruleid, &state, &child);
                    queue.push(child);
                    int move_cost = get_bwd_rule_cost(ruleid);
                    int new_history = next_fwd_history(history,ruleid);
                    queue_history.push(new_history);
                    number_of_childs++;
                }
            }
            else {
                while ((ruleid = next_ruleid(&iterator)) >= 0){
                    apply_bwd_rule(ruleid,&state,&child);
                    queue.push(child);
                    number_of_childs++;
                }
            }
            
        }
        printf("%d | %d | %.3f \n",depth,number_of_childs_per_depth,(float)number_of_childs/number_of_childs_per_depth);
        depth++;    
    }
    return 0;
}

int main(int argc, char **argv){
    if (argc != 2){
        cout << "Número incorrecto de argumentos. Poner 1 para pruning, 0 para no pruning" << endl;
        return -1;
    }
    int pruning = atoi(argv[1]);
    state_t goal;
    int goal_id, finished;
    first_goal_state(&goal,&goal_id);
    bfs(&goal,pruning);
    return 0;
}