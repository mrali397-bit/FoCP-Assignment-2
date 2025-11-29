#include<iostream>

using namespace std;

const int rows = 9;
const int cols = 9;

void fill_0(int [][cols]);

void sol_grid_fill(int[][cols]);
void print_grid(int[][cols]);
bool row_column_check(int[][cols],int,int,int);

int main() {
	int grid[rows][cols];
	sol_grid_fill(grid);
	print_grid(grid);
	
	return 0;
}

void fill_0(int arr[][cols]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[1][j] = 0;
		}
	}
}


bool row_column_check(int arr[][cols],int row,int column, int key) {
	
	for (int i = 0; i < row; i++) {
		if (arr[i][column] == key) return false;
	}
	for (int j = 0; j < column; j++) {
		if (arr[row][j] == key) return false;
	}
	for (int box_row = 3 * (row / 3); box_row < (3 * (row / 3)) +3; box_row++) {
		for (int box_col = 3 * (column / 3); box_col < (3*(column/3) )+3 ; box_col++) {
			if (arr[box_row][box_col] == key&& box_row!= row&&box_col!= column)return false;
		}
	}
	return true;
}

void sol_grid_fill(int sol[][cols]) {
	bool grid_check;
	int key;
	bool sudoku_grid = false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int tries = 1; tries < 300;tries++) {
				sudoku_grid = false;
				key = 1 + rand() % 9;
				grid_check = row_column_check(sol, i, j, key);
				if (grid_check) {
					sudoku_grid = true;
					break;
				}
				
			}
			sol[i][j] = key;
		}
		if (!sudoku_grid) {
			fill_0(sol);
			i = -1;
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