#include "state_node.h"

State_node::State_node() {

    eight_puzzle_node_values = {1,2,3,4,5,6,7,0,8};
    node_id = 0;
    cost_to_node = 500;
    parent_state = nullptr;

}

State_node::State_node(int node_ident, State_node* pred, int new_node_cost, vector<int>state_values){
    node_id = node_ident;
    parent_state = pred;
    cost_to_node = new_node_cost;
    eight_puzzle_node_values = state_values;

}

int State_node::generate_node_id(vector<int> to_id_vec) {
    vector<int> index_enumeration = {11,12,13,14,15,16,17,18,19};

    int id = 0;

    for (int i = 0; i < to_id_vec.size(); i++) {
        id += to_id_vec.at(i) * index_enumeration.at(i);
    }

    return id;
}

vector<int> State_node::get_eight_puzzle_node_values() {

    return eight_puzzle_node_values;

}

vector<State_node*> State_node::nodes_expanded() {
    vector<State_node*>expanded_nodes;

    int index_where_0_is = -1;
    
    for (int i = 0; i < eight_puzzle_node_values.size(); i++) {
        
        if (eight_puzzle_node_values.at(i) == 0) {
            index_where_0_is = i;
        }
    }

    if (index_where_0_is == -1 || index_where_0_is > 8 || index_where_0_is < 0) {
        cout << "ERR: NO BLANK TILE... EXITING" << endl;
        exit(-1);
    }

    State_node* temp_node = nullptr;

    if (index_where_0_is == 0 || index_where_0_is == 1 || index_where_0_is == 2 
    || index_where_0_is == 3 || index_where_0_is == 4 || index_where_0_is == 5) 
    
    {

        //swapdown
        temp_node = swap_down(index_where_0_is, this);
        expanded_nodes.push_back(temp_node);


    }


    if (index_where_0_is >= 3 && index_where_0_is <=8) {

        //swap up
        temp_node = swap_up(index_where_0_is, this);
        expanded_nodes.push_back(temp_node);

    }


    if (index_where_0_is != 0 && index_where_0_is != 3 && index_where_0_is != 6) {

        //swap left
        temp_node = swap_left(index_where_0_is, this);
        expanded_nodes.push_back(temp_node);


    }

    if (index_where_0_is != 2 && index_where_0_is != 5 && index_where_0_is != 8) {

        //swap right
        temp_node = swap_right(index_where_0_is, this);
        expanded_nodes.push_back(temp_node);
    }


    return expanded_nodes;

}

State_node* State_node::swap_down(int zero_index, State_node* curr_node) { //technically pass by reference
    
    vector<int> new_puzzle_values;
    new_puzzle_values = curr_node->eight_puzzle_node_values;

    swap(new_puzzle_values.at(zero_index), new_puzzle_values.at(zero_index + 3));
    int new_id = generate_node_id(new_puzzle_values);
    State_node* temp_node = new State_node(new_id, curr_node, curr_node->cost_to_node - 1, new_puzzle_values);

    return temp_node;
}

State_node* State_node::swap_up(int zero_index, State_node* curr_node) {
    vector<int> new_puzzle_values;
    new_puzzle_values = curr_node->eight_puzzle_node_values;
    
    swap(new_puzzle_values.at(zero_index), new_puzzle_values.at(zero_index - 3));
    int new_id = generate_node_id(new_puzzle_values);
    State_node* temp_node = new State_node(new_id, curr_node, curr_node->cost_to_node-1, new_puzzle_values);

    return temp_node;

}

State_node* State_node::swap_left(int zero_index, State_node* curr_node) {
    vector<int> new_puzzle_values;
    new_puzzle_values = curr_node->eight_puzzle_node_values;
    
    swap(new_puzzle_values.at(zero_index), new_puzzle_values.at(zero_index - 1));
    int new_id = generate_node_id(new_puzzle_values);
    State_node* temp_node = new State_node(new_id, curr_node, curr_node->cost_to_node-1, new_puzzle_values);

    return temp_node;

}

State_node* State_node::swap_right(int zero_index, State_node* curr_node) {
    vector<int> new_puzzle_values;
    new_puzzle_values = curr_node->eight_puzzle_node_values;
    
    swap(new_puzzle_values.at(zero_index), new_puzzle_values.at(zero_index + 1));
    int new_id = generate_node_id(new_puzzle_values);
    State_node* temp_node = new State_node(new_id, curr_node, curr_node->cost_to_node-1, new_puzzle_values);

    return temp_node;
}


void State_node::print_node_state() {
    for(int i = 0; i < eight_puzzle_node_values.size(); i++) {

        

        if ((i + 1) % 3 == 0) {
            cout << eight_puzzle_node_values.at(i);
            cout << endl;
        }

        else {
            //cout << "i + 1 " << i + 1 << endl;
            cout << eight_puzzle_node_values.at(i) << " ";
        }


    }

    cout << endl;
}