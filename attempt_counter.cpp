#include <iostream>
using namespace std;

const int rows = 9;
const int cols = 9;
// Function for keeping 
void check_attempt(int arr[][cols], int row, int col, int key, int &attempts, int &mistakes);

int main()
{

    // Main consisting of sudoku code and the functions for playing sudoku as a whole
    // row_column_check(arr, row, col, key) 
    // The function above represents a function for checker and calls the function below to increment 
    // the attempts and have a display at the end


    //
    return 0;
}

void check_attempt(int arr[][cols], int row, int col, int key, int &attempts, int &mistakes) {
    attempts++;
    if (/* Recursive function call with true output repesenting valid input
        like row_column_check(arr, row, col, key)*/) 
        {
        arr[row][col] = key;
        } 
    else {
        mistakes++;
    cout<<"You Took "<<attempts<<" to solve.\nYou Made "<<mistakes<<" mistakes to solve the game.\n";
    }
}
