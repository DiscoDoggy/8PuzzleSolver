#include "eight_puzzle.h"
#include<queue>
#include <functional>
#include <cstdlib>

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
   typedef pair<int, State_node*> pair_type;
    priority_queue<pair_type,vector<pair_type>,greater<pair_type> > frontier;

    frontier.push(make_pair(init_node->cost_to_node, init_node));
    //seen_states[init_node->node_id] = init_node->eight_puzzle_node_values;//

    states_seen.push_back(init_node->eight_puzzle_node_values);

    pair<int, State_node*> top = frontier.top();
    State_node* node_to_expand = top.second;
    frontier.pop();
    vector<State_node*>expanded_nodes;
    bool is_duplicate = false;

    while(node_to_expand->eight_puzzle_node_values != goal_node_vals) {
        expanded_nodes.clear();
        expanded_nodes = node_to_expand-> nodes_expanded();

        if (expanded_nodes.empty() && frontier.empty()) {
            cout << "IMPOSSIBLE PUZZLE. FRONTIER EMPTY" << endl;
            exit(-2);
        }
        
        cout << "--PRINTING CURRENT NODE--" << endl;
        node_to_expand->print_node_state();
        cout << "\tNode Cost: " << node_to_expand->cost_to_node;
        cout << endl << endl;

        system("pause");

        for (int i = 0; i < expanded_nodes.size(); i++) {
            cout << "EXPANDED NODES " << i << ":" << endl;
            expanded_nodes.at(i)->print_node_state();

            
            for(int j = 0; j < states_seen.size(); j++) {
                if(expanded_nodes.at(i)->eight_puzzle_node_values == states_seen.at(j)) {
                    is_duplicate = true;
                }

            }



            if (is_duplicate == false) {
                //expanded_nodes.at(i)->cost_to_node = expanded_nodes.at(i)->cost_to_node * -1;
                states_seen.push_back(expanded_nodes.at(i)->eight_puzzle_node_values);
                frontier.push(make_pair(expanded_nodes.at(i)->cost_to_node, expanded_nodes.at(i))); 

                top = frontier.top();
                node_to_expand = top.second;
                cout << "\n\n--TOP. FIRST--\n" << top.first << endl;
                path_taken.push(node_to_expand); 
                frontier.pop();
            }

            is_duplicate = false;
            //  print_frontier(frontier);

            // system("pause");     


        }

        system("pause");

        print_repeats();

        system("pause");

       

        
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

void Eight_puzzle::print_repeats() {
    cout << "\n\n----REPEAT STATES----\n\n";

              for (int k = 0; k < states_seen.size(); k++) {
                    for (int p = 0; p < states_seen[k].size();p++) {
                        if ((p + 1) % 3 == 0) {
                            cout << states_seen.at(k).at(p);
                            cout << endl;
                        }

                        else {
                            //cout << "i + 1 " << i + 1 << endl;
                            cout <<states_seen.at(k).at(p) << " ";
                        }
                    }

                    cout << endl;

                }
                cout << "Number of repeated States: " << states_seen.size();
                cout << endl << endl;

}

void Eight_puzzle::print_frontier(priority_queue<pair_type,vector<pair_type>,greater<pair_type> > front_to_print) {
    
    pair<int, State_node*>top;
    cout << "\n\n--PRINTING FRONTIER--\n";
    while(!front_to_print.empty()) {
        top = front_to_print.top();
        cout << "cost: " << top.first << endl;
        front_to_print.pop();
    }
}
