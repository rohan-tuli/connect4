// Connect 4

#include <iostream> 

using namespace std;

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
}
	
int main() {
	printGrid();
	return 0;
}