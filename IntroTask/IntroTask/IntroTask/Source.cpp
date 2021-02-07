#include "Source.h"
#include <iostream>
using namespace std;

Board::Board(): board({"1", "2", "3", "4", "5", "6", "7", "8", "9"}){
}

void Board::addo(int o){
	this->board[o - 1] = "O";
}

void Board::addx(int x) {
	this->board[x - 1] = "X";
}

string Board::check() {
	int counter = 0;
	for (int i = 0; i < this->board.size(); i+= 1) {
		if ((this->board[i] == "X") || (this->board[i] == "O")) {
			counter++;
			string temp = this->board[i];
			// Checking rows
			if (i % 3 == 0) {
				if ((this->board[i + 1] == temp) && (this->board[i + 2] == temp)) {
					return "The winner is player " + temp;
				}
			}
			if (i < 3) {
				if ((this->board[i] == "X") || (this->board[i] == "O")) {
					string temp = this->board[i];
					// Checking columns
					if ((this->board[i + 3] == temp) && (this->board[i + 6] == temp)) {
						return "The winner is player " + temp;
					}
					//Checking diagonals
					if ((i == 0) && (this->board[i + 4] == temp) && (this->board[i + 8] == temp)) {
						return "The winner is player " + temp;
					}
					else if ((i == 2) && (this->board[i + 2] == temp) && (this->board[i + 4] == temp)) {
						return "The winner is player " + temp;
					}
				}
			}
			if (counter == 9) {
				return "There is no winner.";
			}
		}
	}
	
	return "A winner has not been found yet.";
}

ostream& operator<<(ostream& out, const Board& b){
	string output = "";
	for (int i = 0; i < b.board.size(); i++) {
		if ((i == 0) || (i % 3 != 0)) {
			output += " " + b.board[i] + "  ";
		}
		else {
			output += "\n---+---+---\n";
			output += " " + b.board[i] + "  ";
		}
	}
	return out << output;
}