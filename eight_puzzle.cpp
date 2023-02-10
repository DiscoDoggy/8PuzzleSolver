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

void Eight_puzzle::uniform_cost_search() {

    State_node* init_node = new State_node(0,nullptr, 0, init_node_vals);
   // stack<State_node*>solution_path;
    priority_queue<pair<int,State_node*>> frontier;

    frontier.push(make_pair(init_node->cost_to_node, init_node));
    //seen_states[init_node->node_id] = init_node->eight_puzzle_node_values;//

    states_seen.push_back(init_node->eight_puzzle_node_values);

    pair<int, State_node*> top = frontier.top();
    State_node* node_to_expand = top.second;
    frontier.pop();
    vector<State_node*>expanded_nodes;
    bool is_duplicate = false;

    while(node_to_expand->eight_puzzle_node_values != goal_node_vals) {
        expanded_nodes = node_to_expand-> nodes_expanded();

        if (expanded_nodes.empty() && frontier.empty()) {
            cout << "IMPOSSIBLE PUZZLE. FRONTIER EMPTY" << endl;
            exit(-2);
        }
        
        for (int i = 0; i < expanded_nodes.size(); i++) {
            cout << "Node State " << i << ":" << endl;
            expanded_nodes.at(i)->print_node_state();

            // if(seen_states.count(expanded_nodes.at(i)->node_id)) {
            //     //do nothing
                
            //     is_duplicate = true;
            // }
            
            for(int j = 0; j < states_seen.size(); j++) {
                if(expanded_nodes.at(i)->eight_puzzle_node_values == states_seen.at(j)) {
                    is_duplicate = true;
                }
            }

            // else {
            //     expanded_nodes.at(i)->cost_to_node = expanded_nodes.at(i)->cost_to_node + 1;
            //     seen_states[expanded_nodes.at(i)->node_id] = expanded_nodes.at(i)->eight_puzzle_node_values;
            //     frontier.push(make_pair(expanded_nodes.at(i)->cost_to_node, expanded_nodes.at(i))); 
            // }

            cout << "Caught in eight puzzle.cpp loop?" << endl;

            if (is_duplicate == false) {
               // expanded_nodes.at(i)->cost_to_node = expanded_nodes.at(i)->cost_to_node + 1;
                states_seen.push_back(expanded_nodes.at(i)->eight_puzzle_node_values);
                frontier.push(make_pair(expanded_nodes.at(i)->cost_to_node, expanded_nodes.at(i))); 

                top = frontier.top();
                node_to_expand = top.second;
                path_taken.push(node_to_expand); 
                frontier.pop();
            }

            is_duplicate = false;
            


        }

        
    }

    while(node_to_expand->parent_state != nullptr) {
        node_to_expand->print_node_state();
        node_to_expand = node_to_expand->parent_state;
    }

    return;
}

stack<State_node*> Eight_puzzle::a_star_misplaced() {
    State_node* init_node = new State_node(0,nullptr, 0, init_node_vals);
    priority_queue<pair<int,State_node*>> frontier;
    frontier.push(make_pair(init_node->cost_to_node, init_node));
    states_seen.push_back(init_node->eight_puzzle_node_values);

    pair<int, State_node*> top = frontier.top();
    State_node* node_to_expand = top.second;
    frontier.pop();



    stack<State_node*>solution_path;
    return solution_path;
}




stack<State_node*> Eight_puzzle::a_star_euclid() {
    stack<State_node*>solution_path;
    return solution_path;
}
