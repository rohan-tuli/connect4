// Connect 4

#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 6;
const int NUM_COLUMNS = 7;
const char EMPTY = '.';
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char SPACE = ' ';
const int INITIAL_ROW_VALUE = -1;
int gameStatus = 0;
int columnNumber;
int column;
bool playerTurn = true;

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
			if (grid[i][j] == (playerTurn ? PLAYER : COMPUTER)) {
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
		if (grid[i][column] == (playerTurn ? PLAYER : COMPUTER)) {
			counter++;
			if (counter == 4) {
				return true;
			}
		}
		else {
			counter = 0;
		}
	}
	return false;
}

bool positiveSlopeConnect4Found() {
	for (int i = 0; i < 4; i++) {
		int row = 5;
		int col = i;
		int counter = 0;
		while (row >= 0 && col < NUM_COLUMNS) {
			if (grid[row][col] == (playerTurn ? PLAYER : COMPUTER)) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
			else {
				counter = 0;
			}
			row--;
			col++;
		}
	}

	for (int i = 4; i > 2; i--) {
		int row = i;
		int col = 0;
		int counter = 0;
		while (row >= 0 && col < NUM_COLUMNS) {
			if (grid[row][col] == (playerTurn ? PLAYER : COMPUTER)) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
			else {
				counter = 0;
			}
			row--;
			col++;
		}
	}
	return false;
}
bool negativeSlopeConnect4Found() {
	for (int i = 0; i < 4; i++) {
		int row = 0;
		int col = i;
		int counter = 0;
		while (row < NUM_ROWS && col < NUM_COLUMNS) {
			if (grid[row][col] == (playerTurn ? PLAYER : COMPUTER)) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
			else {
				counter = 0;
			}
			row++;
			col++;
		}
	}

	for (int i = 1; i < 3; i++) {
		int row = i;
		int col = 0;
		int counter = 0;
		while (row < NUM_ROWS && col < NUM_COLUMNS) {
			if (grid[row][col] == (playerTurn ? PLAYER : COMPUTER)) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
			else {
				counter = 0;
			}
			row++;
			col++;
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
	}
	else {
		rowsOccupied[column]++;
		int row = 5 - rowsOccupied[column];
		char symbol;

		grid[row][column] = playerTurn ? PLAYER : COMPUTER;
		if (horizontalConnect4Found() || verticalConnect4Found()
			|| positiveSlopeConnect4Found() || negativeSlopeConnect4Found()) {
			printBoard();
			gameStatus = 1;
			if (playerTurn) {
				cout << "You won!!!!" << endl;
			}
			else {
				cout << "You lost!!!!" << endl;
			}
		}
		playerTurn = !playerTurn;
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
