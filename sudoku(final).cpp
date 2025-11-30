#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int rows = 9;
const int cols = 9;
int count = 0;


void fill_0(int [][cols]);
void fill_arr(int[]);
void sol_grid_fill(int[][cols]);
void print_grid(int[][cols]);
bool row_column_box_check(int[][cols],int,int,int);
bool issolvable(int[][cols]);
void solveable_board(int[][cols],int [][cols],int d );
bool check_solveable(int[][cols]);
bool check_solved(int[][cols], int[][cols]);
void hint(int[][cols], int[][cols]);

int main() {
	srand(time(0));
	int grid[rows][cols];
	int solution[rows][cols];
	int difficulty = 1;
	int row, col, val, choice,score = 0;
	fill_0(grid);
	fill_0(solution);
	sol_grid_fill(solution);
	solveable_board(grid, solution, difficulty);
	while (true) {
		print_grid(grid);
		while (true) {
			cout << "Enter your choice(Enter an integer please):\n1. Enter a value\n2. Take a hint.\n3. View solution.\n";
			cin >> choice;
			if (choice > 3 || choice < 1){ 
				cout << "Invalid input.Please input correctly";
				continue;
			}
			break;
		}
		if (choice == 1) {

			cout << "Enter your move (row then column then value)  ";
			cin >> row >> col >> val;
			row -= 1;
			col -= 1;

			// Validate input
			if (row < 0 || row > 8 || col < 0 || col > 8 || val < 1 || val > 9) {
				cout << "Invalid input! Row/Col must be 0-8 and value 1-9.\n";
				continue;
			}

			// Check if the cell is already filled
			if (grid[row][col] != 0) {
				cout << "This cell is already filled! Choose another.\n";
				continue;
			}
			if (val == solution[row][col]) {
				score += 5;
				cout << "\nScore + 5\n" << "Score: " << score << endl;
				grid[row][col] = solution[row][col];
			}
			else {
				score -= 5;
				cout << "\nWrong move. Score - 5\n"<<"Score: "<<score<<endl;
			}
		}
		else if (choice == 2) {
			
			hint(grid, solution);
		}
		else {
			cout << "\nHere is the solution to the sudoku board.\n";
			cout << "Your final score: " << score << endl;
			print_grid(solution);
			break;
		}
	
		if (check_solved(grid,solution) ){
			cout << "Congratulations! You solved the Sudoku.\n";
			cout << "Score: " << score<<endl;
			print_grid(grid);
			break;
		}
	}
	 
	
	
	return 0;
}

void fill_0(int arr[][cols]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = 0;
		}
	}
}


bool row_column_box_check(int arr[][cols],int row,int column, int key) {
	
	for (int i = 0; i < rows; i++) {
		if (arr[i][column] == key) return false;
	}
	for (int j = 0; j < cols; j++) {
		if (arr[row][j] == key) return false;
	}
	for (int box_row = 3 * (row / 3); box_row < (3 * (row / 3)) +3; box_row++) {
		for (int box_col = 3 * (column / 3); box_col < (3*(column/3) )+3 ; box_col++) {
			if (arr[box_row][box_col] == key)return false;
		}
	}
	return true;
}

void sol_grid_fill(int sol[][cols]) {
	bool tried[10]; 
	int placed = 0;
	int key;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (sol[i][j] != 0) continue;


			for (int k = 1; k <= 9; k++) tried[k] = 0;
			placed = 0;
			while (placed < 9) {
				key = 1 + rand() % 9;
				if (tried[key]) continue; 
				tried[key] = 1;

				if (row_column_box_check(sol, i, j, key)) {
					sol[i][j] = key;
					if (check_solveable(sol)) {
						break; 
					}
					else {
						sol[i][j] = 0; 
					}
				}
				placed++;
			}

			if (sol[i][j] == 0) {
				
				fill_0(sol);
				i = -1;
				break;
			}
		}
	}
}

void print_grid(int arr[][cols]) {
	cout << "+----------+-----------+-----------+\n";
	for (int i = 0; i < rows; i++) {
		
		cout << "|";
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j];
			if ((j+1) % 3 == 0) cout << " | ";
			else cout << " . ";
	
		}
	
		cout << endl;
		if ((i + 1) % 3 == 0) {
			for (int dash = 1; dash < 37; dash++)cout << "-";
			cout << endl;
		}
		
	}

}

void count_solutions(int grid[rows][cols], int& count) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 0) {
				for (int key = 1; key <= 9; key++) {
					if (row_column_box_check(grid, i, j, key)) {
						grid[i][j] = key;
						count_solutions(grid, count);
						grid[i][j] = 0;
					}
				}
				return;
			}
		}
	}
	count++;
}

bool issolvable(int grid[][cols]) {
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 0) {
				for (int key = 1; key <= 9; key++) {
					if (row_column_box_check(grid, i, j, key)) {
						grid[i][j] = key;
						if (issolvable(grid)) {
							return true;
						}
						grid[i][j] = 0;
					}

				}
				return false;
			}
		}

	}
	return true;
}

void fill_arr(int arr[]) {
	for (int i = 1; i < 10; i++) {
		arr[i] = i;
	}
}

bool check_solveable(int grid[][cols]) {
	int check_grid[rows][cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			check_grid[i][j] = grid[i][j];
		}
	}
	
	return issolvable(check_grid);
}

void solveable_board(int grid[][cols],int sol[][cols],int difficulty) {
	int num_clues = 40 + rand() % 3;
	int row, column;
	int solutions = 0;
	while (true) {
		for (int clues = 1; clues <= num_clues - 4 * difficulty;) {
			row = 0 + rand() % 9;
			column = 0 + rand() % 9;
			if (grid[row][column] != 0) {
				continue;
			}
			grid[row][column] = sol[row][column];
			clues++;
		}
		solutions = 0;
		count_solutions(grid, solutions);
		if (check_solveable(grid) && solutions==1) break;
		fill_0(grid);
		
	}
}

bool check_solved(int grid[][cols], int sol[][cols]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] != sol[i][j]) {
				return false;
			}
		}
	}
	return true; 
}
void hint(int grid[][cols], int sol[][cols]) {
	int row , col ;
	while (true) {
		cout << "Enter where you want hint (row then column): ";
		cin >> row >> col;
		row -= 1;
		col -= 1;
		// Validate input
		if (row < 0 || row > 8 || col < 0 || col > 8) {
			cout << "Invalid input! Row/Col must be 0-8 and value 1-9.\n";
			continue;
		}
		if (grid[row][col] != 0) {
			cout << "\nThis cell is already filled.\n";
		}
		else {
			grid[row][col] = sol[row][col];
			break;
		}
	}
	
}





