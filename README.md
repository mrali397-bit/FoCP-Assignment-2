# **-----------------------Sudoku-------------------------**



### **Title \& Team Info:**





1. #### **Project Title:** "Sudoku Game, Checker, and Solver"



2. #### **Team Members:**



* ##### Muhammad Aniq Nasir
* ##### Muhammad Faizan Asif
* ##### Muhammad Ali Hassan

##### 

#### 3\. **Roles:**



* ##### Aniq (Team Lead): Main Programmer, Debugger
* ##### Faizan: Programmer 2, Logic Building
* ##### Ali: Programmer 3, README.md author, Documenter





### **Overview:**





1. #### **What the Game does:**

##### 

##### This project is a comprehensive Sudoku application that includes three main components:

* ##### Sudoku Generator: Automatically generates valid 9x9 Sudoku grids using a randomized algorithm with backtracking capabilities.
* ##### Sudoku Solver: Solve an incomplete Sudoku puzzle using backtracking that continuously tries numbers and backtracks when it encounters conflicts.
* ##### Grid Display: Provides formatted output for the 3x3 boxes, making the grid easy to read.



2. #### **Why it's useful:**

* ##### Understanding programming concepts like backtracking, recursion, 2D-arrays.
* ##### Shows practical implementation of backtracking algorithms in C++.
* ##### Helpful in Building future Sudoku-based applications.





### **Design \& Logic:**



1. #### **List of functions:**



* ##### Grid-Generator functions:

1. ##### void fill\_0(int \[]\[cols]): Resets the entire Sudoku grid to zeros.
2. ##### void fill\_arr(int\[]): Initializes or clears a 1D helper array.
3. ##### void sol\_grid\_fill(int\[]\[cols]): Generates a full valid Sudoku solution grid using randomized filling.
4. ##### void print\_grid(int\[]\[cols]): Displays the Sudoku grid in a readable format.
5. ##### bool row\_column\_box\_check(int\[]\[cols],int,int,int): Checks if a number can be placed at a given row, column, and box.



* ##### Solver functions:

1. ##### bool issolvable(int\[]\[cols]): Determines if the current Sudoku board is solvable.
2. ##### void solveable\_board(int\[]\[cols],int \[]\[cols],int d ): Creates a playable puzzle by removing numbers based on difficulty.
3. ##### bool check\_solveable(int\[]\[cols]): Validates whether the puzzle still has a unique solvable path.
4. ##### bool check\_solved(int\[]\[cols], int\[]\[cols]): Compares solved grid with current grid to confirm correctness.
5. ##### void hint(int\[]\[cols], int\[]\[cols]): Reveals a correct number in one empty cell as a hint.

#### 

2. #### **Grid handling**

* ##### The grid is represented as a 9x9 two-dimensional integer array
* ##### Empty cells are represented by 0
* ##### Filled cells contain numbers 1-9
* ##### The grid is divided into nine 3x3 boxes
* ##### Validates using row\_column\_box\_check
* ##### If a row fails, grid resets using fill\_0()
* ##### Continues until a valid 9×9 solution is built
* ##### Visual output uses | and - characters to create clear box boundaries





#### 3\. **Hint/Solver approach**

1. ##### Generator Approach:

* ##### Uses random number generation (1-9) for each cell
* ##### Validates each placement against row, column, and 3x3 box constraints
* ##### Attempts up to 300 tries per cell before resetting the grid
* ##### Restarts entire grid generation if a valid configuration cannot be found



##### 2\. Solver Approach:

* ##### Searches for the next empty cell (value 0)
* ##### Tries values 1–9
* ##### Uses: Row check, Column check, 3×3 box check
* ##### Recursively continues if valid, backtracks if invalid
* ##### Returns true when all cells are successfully filled



### **Execution Instructions:**



1. #### **How to compile:**

##### In Visual Studio 2022, we created a C++ file named "sudoku(final).cpp".

##### 

#### **2.  How to run:**

##### Then clicked "Start Without Debugging" or pressed Ctrl + F5 to run it.

##### 

#### **3.  Sample inputs/outputs:**



* ##### Sample partially filled grid shown as output in start:

##### \[0 0 6 | 1 0 0 | 0 4 0]

##### \[9 0 0 | 0 5 3 | 0 0 0]

##### \[0 1 0 | 0 0 0 | 0 6 0]



##### \[0 0 0 | 0 4 0 | 0 6 0]

##### \[7 0 0 | 0 0 0 | 0 1 0]

##### \[0 3 8 | 0 0 0 | 0 0 0]



##### \[0 0 0 | 0 0 5 | 0 0 0]

##### \[0 9 0 | 7 0 0 | 0 0 0]

##### \[4 0 0 | 0 0 0 | 0 8 0]



* ##### Sample partially filled grid for solver as input after inputting some values by user:

##### \[2 5 6 | 1 0 7 | 0 4 0]

##### \[9 0 7 | 0 5 3 | 0 0 0]

##### \[8 1 0 | 0 0 0 | 0 5 0]



##### \[1 0 0 | 0 4 0 | 0 6 0]

##### \[7 0 0 | 0 0 0 | 0 1 0]

##### \[0 3 8 | 0 0 0 | 0 0 2]



##### \[0 0 0 | 0 0 5 | 0 0 0]

##### \[0 9 0 | 7 0 0 | 0 0 0]

##### \[4 0 0 | 0 0 0 | 0 8 0]



* ##### Sample completely filled grid by solver shown as output:

##### \[2 5 6 | 1 9 7 | 3 4 8]

##### \[9 4 7 | 8 5 3 | 1 2 6]

##### \[8 1 3 | 2 6 4 | 9 5 7]



##### \[1 2 9 | 3 4 8 | 7 6 5]

##### \[7 6 4 | 5 2 9 | 8 1 3]

##### \[5 3 8 | 6 7 1 | 4 9 2]



##### \[3 8 2 | 4 1 5 | 6 7 9]

##### \[6 9 1 | 7 8 2 | 5 3 4]

##### \[4 7 5 | 9 3 6 | 2 8 1]

##### 





### **AI Tool Reflection:**

##### AI tool (ChatGPT) was used for:

* ##### Learning Backtracking algorithm
* ##### Random Sudoku generation
* ##### Suggesting enhancements for future expansion



### **Future Enhancements:**

* ##### Build a GUI interface using SFML, Qt, or ImGui
* ##### Add a timer based scoring.
* ##### Making proper database of user information storing his/her game progress like number of games played, win, number of hints and average time taken.
