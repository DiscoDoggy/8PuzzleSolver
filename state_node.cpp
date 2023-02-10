#include "state_node.h"

State_node::State_node() {

    eight_puzzle_node_values = {1,2,3,4,5,6,7,0,8};
    node_id = 0;
    cost_to_node = 0;
    parent_state = nullptr;

}

State_node::State_node(int node_ident, State_node* pred, int new_node_cost, vector<int>state_values){
    node_id = node_ident;
    parent_state = pred;
    cost_to_node = new_node_cost;
    eight_puzzle_node_values = state_values;

}

int State_node::generate_node_id() {


    return 0;
}

vector<int> State_node::get_eight_puzzle_node_values() {

    return eight_puzzle_node_values;

}

vector<State_node*> State_node::nodes_expanded() {
    vector<State_node*>expanded_nodes;
    return expanded_nodes;

}

void State_node::print_node_state() {
    return;
}