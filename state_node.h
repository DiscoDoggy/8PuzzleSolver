#ifndef STATE_NODE_H
#define STATE_NODE_H

#include <iostream>
#include<vector>

using namespace std;

class State_node {
    
    public:

        int node_id;
        State_node *parent_state;
        int cost_to_node; // same as depth all costs are the same
        vector<int> eight_puzzle_node_values;


        int generate_node_id();
        vector<int> get_eight_puzzle_node_values();
        vector<State_node*> nodes_expanded(); //this does the node expansion
        void print_node_state();





};





#endif