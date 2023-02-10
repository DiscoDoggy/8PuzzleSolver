#include "eight_puzzle.h"
#include<queue>

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
    // for (int i = 0; i < this->init_node_vals.size(); i++) {
    //     cout << this->init_node_vals.at(i) << ' ';
    // }
    return;
}

stack<State_node*> Eight_puzzle::uniform_cost_search() {

    State_node* init_node = new State_node(0,nullptr, 0, init_node_vals);
    stack<State_node*>solution_path;
    priority_queue<pair<int,State_node*>> frontier;

    frontier.push(make_pair(init_node->cost_to_node, init_node));
    seen_states[init_node->node_id] = init_node->eight_puzzle_node_values;

    


    init_node->print_node_state();

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
