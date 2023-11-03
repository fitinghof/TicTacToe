#ifndef PositionClass
#define PositionClass

#include <iostream>
#include <bitset>
using std::bitset;
using std::cout;
using std::cin;

class Position {
private:
	static constexpr int zeroMask = 0b1;

public:
	bool playerTurn = 0;
	int move = 0;
	short pos = 0;
	short mask = 0;
	

	/*
	* * *
	2 6 10
	1 5 9
	0 4 8
	*/

	bool canPlay(int xy) {
		int y = xy % 10;
		int x = (xy - y) / 10;
		int playPos = zeroMask << (2 - y + x * 4);
		if (playPos & mask) return false;
		return true;
	}

	void play(int xy) {
		int y = xy % 10;
		int x = (xy - y) / 10;
		int playPos = zeroMask << (2 - y + x * 4);
		if (canPlay(xy)) {
			pos = pos | playPos;
			mask = mask | playPos;
			pos = pos ^ mask;
			move++;
			playerTurn = !playerTurn;
		}
	}

	bool hasWon(short pos) {
		short tempPos = pos & (pos >> 1);
		tempPos = tempPos & (tempPos >> 1);
		if (tempPos) return true;

		tempPos = pos & pos >> 5;
		tempPos = tempPos & tempPos >> 5;
		if (tempPos) return true;

		tempPos = pos & pos >> 3;
		tempPos = tempPos & tempPos >> 3;
		if (tempPos) return true;

		tempPos = pos & pos >> 4;
		tempPos = tempPos & tempPos >> 4;
		if (tempPos) return true;

		return false;
	}

	void drawBoard() {
		bitset<12> p1 = pos;
		bitset<12> p2 = pos^mask;
		for (int i = 0; i < 3; i++) {
			cout << "\n-------------\n";
			for (int j = 0; j < 3; j++) {
				if (playerTurn) {
					if (p1[2 + j * 4 - i]) {
						cout << "| X ";
					}
					else if (p2[2 + j * 4 - i]) {
						cout << "| O ";
					}
					else cout << "|   ";
				}
				else {
					if (p1[2 + j * 4 - i]) {
						cout << "| 0 ";
					}
					else if (p2[2 + j * 4 - i]) {
						cout << "| X ";
					}
					else cout << "|   ";
				}
			}
			cout << "|";
		}
		cout << "\n-------------\n";
	}
};


#endif 
