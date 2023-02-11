#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <chrono>

#include "eight_puzzle.h"
#include "state_node.h"

using namespace std;
using namespace std::chrono;

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
    //problem.print_path_taken();



    cout << "Enter your choice of algorithm" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with Misplaced Tile Heuristic" << endl;
    cout << "3. A* with the Euclidian Distance Heuristic" << endl;
    cout << endl;

    int algo_choice = 1;
    cin >> algo_choice;
    cout << endl;
    
    auto start = high_resolution_clock::now();


    if (algo_choice == 1) {
        problem.uniform_cost_search2();
    }

    else if (algo_choice == 2) {
        
        problem.a_star_misplaced();

    }

    else if (algo_choice == 3) {
        problem.a_star_euclid();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

    cout << endl << endl;
    cout << "The searcht took " << duration.count() << " ms." << endl;
    problem.print_prob_info();


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


