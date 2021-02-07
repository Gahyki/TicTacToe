#pragma once
#include <string>
#include <vector>
using namespace std;

class Board {
private:
	vector<string> board;
public:
	Board();
	void addo(int o);
	void addx(int x);
	string check();
	friend ostream& operator<<(ostream& out, const Board& b);
};
