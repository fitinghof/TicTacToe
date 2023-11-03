#include "PositionClass.hpp"
#include "solver.hpp"
int takeInp() {
	int x;
	cout << "\nenter x value\n";
	cin >> x;

	int y;
	cout << "\nenter y value\n";
	cin >> y;
	return x * 10 + y;
}

Position P;
solver S;

int main() {
	while (true) {
		P.drawBoard();
		if (!P.playerTurn) {

			P.play(takeInp());
		}
		else {
			P.play(S.miniMax(P));
		}
		if (P.hasWon(P.pos ^ P.mask)) {
			P.drawBoard();
			cout << "win";
			break;
		}
		if (P.move == 9) {
			P.drawBoard();
			cout << "draw";
			break;
		}
		cout << S.nodesExplored;
	}
}