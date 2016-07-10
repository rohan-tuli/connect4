// Connect 4

#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 6;
const int NUM_COLUMNS = 7;
const char EMPTY = '.';
const char PLAYER = 'X';
const char SPACE = ' ';
const int INITIAL_ROW_VALUE = -1;
int gameStatus = 0;
int columnNumber;
int column;

void printBoard();

vector<vector<char> > grid(NUM_ROWS, vector<char>(NUM_COLUMNS, EMPTY));
vector<int> rowsOccupied(NUM_COLUMNS, INITIAL_ROW_VALUE);

bool columnIsFull(int columnNumber) {
	return rowsOccupied[columnNumber] == 5;
}

bool horizontalConnect4Found() {
	int counter = 0;
	for (int i = 0; i < grid.size(); ++i) {
		counter = 0;
		for (int j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] == PLAYER) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
			else {
				counter = 0;
			}
		}
	}
	return false;
}

bool verticalConnect4Found() {
	int counter = 0;
	for (int i = 0; i < grid.size(); ++i) {
		if (grid[i][column] == PLAYER) {
			counter++;
			if (counter == 4) {
				return true;
			}
		} else {
			counter = 0;
		}
	}
	return false;
}

void getInput() {
	int userInput;
	while ((cout << "Which column would you like to place your disk in? ")
		&& (!(cin >> userInput) || userInput < 1 || userInput > 7)) {
		cout << "That's not a number between 1 and 7 inclusive. Please try again.\n";
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	column = userInput - 1;
	
	if (columnIsFull(column)) {
		cout << "All the rows are filled up in that column." << endl;
	} else {
		rowsOccupied[column]++;
		int row = 5 - rowsOccupied[column];
		grid[row][column] = PLAYER;
		if (horizontalConnect4Found() || verticalConnect4Found()) {
			printBoard();
			gameStatus = 1;
			cout << "You won!!!!" << endl;
		}
	}
} 

void printBoard() {
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {

			cout << grid[i][j] << SPACE;
		}
		cout << endl;
	}
}

int main() {
	while (gameStatus == 0) {
		printBoard();
		getInput();
	}
  return 0;
}