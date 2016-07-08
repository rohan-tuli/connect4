// Connect 4

#include <iostream> 
#include <string>

using namespace std;

int gameStatus = 0;
int column; // TO"DO: better name.


// TODO: fix syntax.

string[] grid = new string[7][6];


//Creates the grid.
void createGrid() {
	std::vector<std::vector<int>> grid{ {1, 1, 1} }
	}
}

// Gets the input.
void getInput() {
	while ((std::cout << "Which column would you like to place your disk in?\n")
		&& !(std::cin >> column)) {
		std::cout << "That's not a number. Please try again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// Prints the grid.
void printGrid() {
	for (int i = 0; i <= 6; ++i) {
		cout << " _";
	}
	cout << endl;
	for (int i = 0; i <= 5; ++i) {
		for (int i = 0; i <= 6; ++i) {
			cout << "|_";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i <= 6; ++i) {
		cout << " " << i + 1;
	}
	cout << endl;
}
	
void editGrid() {
	string cat = "cat";
	string dog = "dog";
	string row1 = cat + dog;
	cout << row1;
}

int main() {
	createGrid();
	grid.size();
	//while (gameStatus == 0) {
		printGrid();
		getInput();
		editGrid();
	//}
    return 0;
}
