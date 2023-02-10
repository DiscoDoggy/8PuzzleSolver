#include "eight_puzzle.h"

Eight_puzzle::Eight_puzzle() {
    init_node_vals = {1,2,3,4,5,6,7,0,8};
    goal_node_vals = {1,2,3,4,5,6,7,8,0};
    num_nodes_expanded = 0;
    max_nodes_frontier = 0;
}

Eight_puzzle::Eight_puzzle(vector<int> starting, vector<int> goal) {
    init_node_vals = starting;
    goal_node_vals = goal;
    num_nodes_expanded = 0;
    max_nodes_frontier = 0;
}

void Eight_puzzle::print_path_taken() {
    return;
}

stack<State_node*> Eight_puzzle::uniform_cost_search() {
    stack<State_node*>solution_path;
    return solution_path;
}

stack<State_node*> Eight_puzzle::a_star_misplaced() {
    stack<State_node*>solution_path;
    return solution_path;
}

stack<State_node*> Eight_puzzle::a_star_euclid() {
    stack<State_node*>solution_path;
    return solution_path;
}
