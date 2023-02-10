#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "eight_puzzle.h"
#include "state_node.h"

using namespace std;

int ROW_SIZE = 3;

void display_menu();
vector<int> get_puzzle_vals_from_user();
void print_one_dim_as_two(vector<int>);


int main() {

    display_menu();




    return 0;

}


void display_menu() {

    cout << "Welcome to 862161616 8 Puzzle Solver.";
    cout << endl;
    cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle.";
    cout << endl;

    int puzzle_choice;
    cin >> puzzle_choice;
    cout << endl;

    while (puzzle_choice != 1 && puzzle_choice != 2) { //issue with non numeric input

        cout << "Invalid input. Please enter 1 for default puzzle and 2 for your own.";
        cout << endl;
        cin >> puzzle_choice;

    }
    
    vector<int>puzzle_values;

    if(puzzle_choice == 1) {
        puzzle_values = {1,2,3,4,5,6,7,0,8};    
    }

    if(puzzle_choice == 2) {
        puzzle_values = get_puzzle_vals_from_user(); 

    }

    print_one_dim_as_two(puzzle_values);

    Eight_puzzle problem(puzzle_values, {1,2,3,4,5,6,7,8,0});
    problem.print_path_taken();

    problem.uniform_cost_search();
    State_node* temp_node = nullptr;

    // while(!solution.empty()) {
    //     temp_node = solution.top();
    //     //cout << endl;
    //     // temp_node->print_node_state();
    //     // cout << endl;
    //     solution.pop();
    // }


}

vector<int> get_puzzle_vals_from_user() {


    cout << "Enter your puzzle, use a zero to represent the blank.";
    cout << endl;
    cout << "Enter the first row, use spaces or tabs between numbers.";
    cout << endl;

    int user_puz_val_input;
    vector<int> user_puzzle_values;

    for (int i = 0; i < ROW_SIZE; i++) {
        
        cin >> user_puz_val_input;
        user_puzzle_values.push_back(user_puz_val_input);

    }

    cout << endl;
    cout << "Enter your second row, use space or tabs between numbers.";
    cout << endl;

    for (int i = 0; i < ROW_SIZE; i++) {
    
        cin >> user_puz_val_input;
        user_puzzle_values.push_back(user_puz_val_input);

    }

    cout << endl;
    cout << "Enter your third row, use space or tabs between numbers.";
    cout << endl;   

    for (int i = 0; i < ROW_SIZE; i++) {
    
        cin >> user_puz_val_input;
        user_puzzle_values.push_back(user_puz_val_input);

    }

    cout << endl;

    return user_puzzle_values;

}

void print_one_dim_as_two(vector<int> vec_to_print) {
    
    for(int i = 0; i < vec_to_print.size(); i++) {

        

        if ((i + 1) % 3 == 0) {
            cout << vec_to_print.at(i);
            cout << endl;
        }

        else {
            //cout << "i + 1 " << i + 1 << endl;
            cout << vec_to_print.at(i) << " ";
        }


    }

    cout << endl;

}


