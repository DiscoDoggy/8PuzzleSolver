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

void Eight_puzzle::a_star_misplaced() {
        //use a regular queue.
    vector<pair<int, State_node*>>frontier;
    states_seen.clear();

    State_node* first_node = new State_node(0, nullptr, 0, init_node_vals);

    first_node->heuristic_value = misplaced_heuristic(first_node->eight_puzzle_node_values);
    first_node->utility = first_node->cost_to_node + first_node->heuristic_value;
    frontier.push_back(make_pair(first_node->utility, first_node));

    State_node* path_node = nullptr;
    vector<State_node*> expanded_nodes;
    State_node* expanding_node = nullptr;
    State_node* temp_node = nullptr;
    bool is_duplicate = false;

    //vector<State_node*>solution_nodes;

    while (1) {
        
        if (frontier.empty()) {
            cout << "IMPOSSIBLE PUZZLE. FRONTIER EMPTY" << endl;
            exit(-2);
        }

        sort(frontier.rbegin(), frontier.rend());
        pair<int, State_node*> top = frontier.back();
        frontier.pop_back();

        if (top.second -> eight_puzzle_node_values == goal_node_vals) {
            path_node = top.second;
            //solution_nodes.push_back(path_node);
            print_path_taken(path_node);
            return;
            
            

        }

        states_seen.push_back(top.second->eight_puzzle_node_values);
        expanding_node = top.second;
        expanded_nodes = expanding_node->nodes_expanded();

        for(int i = 0; i < expanded_nodes.size(); i++) {

            for (int j = 0; j < states_seen.size(); j++) {
                
                if (expanded_nodes.at(i)->eight_puzzle_node_values == states_seen.at(j)) {
                    is_duplicate = true;
                } 
            }

            if (is_duplicate == false) {
                expanded_nodes.at(i)->heuristic_value = misplaced_heuristic(expanded_nodes.at(i)->eight_puzzle_node_values);
                expanded_nodes.at(i)->utility = expanded_nodes.at(i)->heuristic_value + expanded_nodes.at(i)->cost_to_node;
                frontier.push_back(make_pair(expanded_nodes.at(i)->utility, expanded_nodes.at(i)));
                sort(frontier.rbegin(), frontier.rend());

            }

            is_duplicate = false;



        }

        

    }

    print_path_taken(path_node);

}

int Eight_puzzle::misplaced_heuristic(vector<int> check_misplaced) {
    int num_misplaced_tiles = 0;

    for (int i = 0; i < goal_node_vals.size(); i++) {
        if(check_misplaced.at(i) != goal_node_vals.at(i)) {
            num_misplaced_tiles++;
        }
    }

    return num_misplaced_tiles;

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


void Eight_puzzle::uniform_cost_search2() {
    //use a regular queue.
    queue<pair<int, State_node*>>frontier;
    states_seen.clear();

    State_node* first_node = new State_node(0, nullptr, 0, init_node_vals);
    frontier.push(make_pair(first_node->cost_to_node, first_node));

    State_node* path_node = nullptr;
    vector<State_node*> expanded_nodes;
    State_node* expanding_node = nullptr;
    bool is_duplicate = false;

    while (1) {
        
        if (frontier.empty()) {
            cout << "IMPOSSIBLE PUZZLE. FRONTIER EMPTY" << endl;
            exit(-2);
        }

        pair<int, State_node*> top = frontier.front();
        frontier.pop();

        if (top.second -> eight_puzzle_node_values == goal_node_vals) {
            path_node = top.second;
            break;
        }

        states_seen.push_back(top.second->eight_puzzle_node_values);
        expanding_node = top.second;
        expanded_nodes = expanding_node->nodes_expanded();

        for(int i = 0; i < expanded_nodes.size(); i++) {

            for (int j = 0; j < states_seen.size(); j++) {
                
                if (expanded_nodes.at(i)->eight_puzzle_node_values == states_seen.at(j)) {
                    is_duplicate = true;
                } 
            }

            if (is_duplicate == false) {
                frontier.push(make_pair(expanded_nodes.at(i)->cost_to_node, expanded_nodes.at(i)));
            }

            is_duplicate = false;



        }

        

    }

    print_path_taken(path_node);

}



void Eight_puzzle::print_path_taken(State_node* sol_path) {
    State_node* temp_node = sol_path;

    cout << "\n\n--PRINITING PATH--\n\n";
    while(temp_node != nullptr) {
        temp_node->print_node_state();
        cout << "cost to node: " << temp_node->cost_to_node << endl;
        cout << "Heuristic: " << temp_node->heuristic_value << endl << endl;
        temp_node = temp_node->parent_state;
    }
}
