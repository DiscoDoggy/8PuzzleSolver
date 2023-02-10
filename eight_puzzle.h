#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H

#include "state_node.h"
#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

class Eight_puzzle {

    public:
        
        Eight_puzzle();
        Eight_puzzle(vector<int> starting, vector<int> goal);


        vector<int> init_node_vals;
        vector<int> goal_node_vals;
        stack<State_node*> path_taken;
        int num_nodes_expanded;
        int max_nodes_frontier;

        void print_path_taken();
        stack<State_node*> uniform_cost_search();
        stack<State_node*> a_star_misplaced();
        stack<State_node*> a_star_euclid();








};











#endif