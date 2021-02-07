#include "Source.h"
#include <iostream>
using namespace std;

int main() {
	Board *b = new Board();
	int counter = 0;
	cout << "Welcome to Jason's Tic Tac Toe!\n\n" << endl;
	while (b->check() == "A winner has not been found yet.") {
		int input;
		cout << *b << endl;
		if (counter % 2 == 0) {
			cout << "Player O, please pick a position on the board: ";
			cin >> input;
			b->addo(input);
			cout << endl;
		}
		else {
			cout << "Player X, please pick a position on the board: ";
			cin >> input;
			b->addx(input);
			cout << endl;
		}
		counter++;
	}

	cout << *b << endl;
	cout << "Results: " << b->check() << endl;
	return 0;
}