// Connect 4

#include <iostream> 

using namespace std;

int gameStatus = 0;

// Gets the input.
void getInput() {
	int column;
	// TODO: check for invalid column values.
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
	
int main() {
	while (gameStatus == 0) {
		printGrid();
		getInput();
	}
    return 0;
}
