# Eight Puzzle Solver Using A-Star Search with Different Heuristics and Uniform Cost Search

### Introduction 
The Eight puzzle is a problem in which you are given a 3x3 grid with eight tiles numbered 1-8 and an empty space. The problem is to arrange the numbers in order and have the empty space be on the bottom right. In the image below,
the program prompts for if we want to supply a custom puzzle or use the default puzzle (only one number is shifted). Once choosing grid arrangement option, the user is prompted with what algorithm to use for searching for a correct solution.
The program then begins searching the problem space for a solution with the selected search algorithm.

### Easy Example 
Below is a picture of the results using the default very easy example. Here, 0 represents the blank space and so only the number 8 and the blank space are misaligned. Sliding the eight into the blank space produces the correct solution.

![image](https://github.com/DiscoDoggy/8PuzzleSolver/assets/110149934/e842db45-1a88-4e94-bee5-21f8d4d63cbd) 

### A Harder Example 
This time, we have a harder example in which the blank space is in the top left.
![image](https://github.com/DiscoDoggy/8PuzzleSolver/assets/110149934/d3a6fd0b-8652-4b80-84ef-3c4b147bd984) 

These are the steps the search algorithm, in this case A-star search with euclidian heuristic takes to solve the puzzle. 

![image](https://github.com/DiscoDoggy/8PuzzleSolver/assets/110149934/80db1e21-1bb2-45d5-919c-5a3dfdbce067)



