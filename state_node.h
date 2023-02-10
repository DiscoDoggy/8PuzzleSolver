#ifndef STATE_NODE_H
#define STATE_NODE_H

#include <iostream>
#include<vector>

using namespace std;

class State_node {
    
    public:

        State_node();
        State_node(int node_ident, State_node* pred, int new_node_cost, vector<int>state_values);

        int node_id;
        State_node *parent_state;
        int cost_to_node; // same as depth all costs are the same
        vector<int> eight_puzzle_node_values;


        int generate_node_id();
        vector<int> get_eight_puzzle_node_values();
        vector<State_node*> nodes_expanded(); //this does the node expansion
        void print_node_state();

        State_node* swap_down();
        State_node* swap_up();
        State_node* swap_left();
        State_node* swap_right();





};





#endif