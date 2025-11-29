#include<iostream>
using namespace std;

// Functions Declaration
bool isValidMove(int[9][9], int, int, int);
bool solveSudoku(int[9][9]);

// Move Validation
bool isValidMove(int grid[9][9], int row, int col, int num) {

    // check if placing a number in a specific cell is valid
    for (int i = 0; i < 9; i++) {

        // Check the entire row for the number
        if (grid[row][i] == num) {
            return false;
        }
        
        // Check the entire column for the number
        if (grid[i][col] == num) {
            return false;
        }
    }

    // 3x3 boxes of sudoku grid
    int boxRow = (row / 3) * 3;  // top-left row of 3x3 box
    int boxCol = (col / 3) * 3;  // top-left column of 3x3 box
    
    // Check all cells in the 3x3 box for the number
    for (int r = 0; r < boxRow + 3; r++) {

        for (int c = 0; c < boxCol + 3; c++) {

            if (grid[r][c] == num) {
                return false;  // Number already in box
            }

        }
    }
    return true;  // It's safe to place the number
}

// Solving Sudoku using backtracking
bool solveSudoku(int grid[9][9]) {
    
    // Finding empty cell
    for (int row = 0; row < 9; row++) {

        for (int col = 0; col < 9; col++) {
            
            // Found an empty cell
            if (grid[row][col] == 0) {
                
                // Try inserting all numbers from 1-9
                for (int num = 1; num < 9; num++) {
                    
                    // Check if this number can be placed here
                    if (isValidMove(grid, row, col, num)) {

                        // Place the number
                        grid[row][col] = num;
                        
                        // Recursion to fill the remaining empty cells
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        
                        // Backtrack: undo the move if it leads to dead end
                        grid[row][col] = 0;
                    }
                }

                // If no number worked, backtrack to the previous cell
                return false;
            }
        }
    }

    // If no empty cells remain, Sudoku is solved
    return true;
}