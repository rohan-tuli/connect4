// Connect 4

#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 6;
const int NUM_COLUMNS = 7;
const char EMPTY = '.';
const char PLAYER = 'X';
const char SPACE = ' ';

int gameStatus = 0;

vector<vector<char> > grid(NUM_ROWS, vector<char>(NUM_COLUMNS, EMPTY));

// Gets the input.
void getInput() {
	int column;
	while ((cout << "Which column would you like to place your disk in? ")
		&& !(cin >> column)) {
		cout << "That's not a number. Please try again.\n";
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

	}
  // TODO: find exact row where this goes.

  grid[0][column - 1] = PLAYER;

}

void printGrid() {
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      cout << grid[i][j] <<  SPACE;
    }
    cout << endl;
  }
}

int main() {
	while (gameStatus == 0) {
		printGrid();
		getInput();
	}
  return 0;
}
