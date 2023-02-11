#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H

#include "state_node.h"
#include <iostream>
#include <vector>
#include <string>
#include<stack>
#include <queue>
#include<unordered_map>

using namespace std;
typedef pair<int, State_node*> pair_type;

class Eight_puzzle {

    public:
        
        Eight_puzzle();
        Eight_puzzle(vector<int> starting, vector<int> goal);


        vector<int> init_node_vals;
        vector<int> goal_node_vals;
        stack<State_node*> path_taken;
        unordered_map<int, vector<int>> seen_states;
        vector<vector<int>>states_seen;

        int num_nodes_expanded;
        int max_nodes_frontier;

        void print_path_taken(State_node* sol_path);
        void uniform_cost_search();
        void uniform_cost_search2();
        void a_star_misplaced();
        stack<State_node*> a_star_euclid();
        int misplaced_heuristic();
        void print_repeats();
        void print_frontier(priority_queue<pair_type,vector<pair_type>,greater<pair_type> > front_to_print);
        //deciper path 







};











#endif