#ifndef solver
#include "PositionClass.hpp"

class solver {
public:
	unsigned long long nodesExplored = 0;
	int miniMax(Position& P, bool zeroDepth = true) {
		nodesExplored++;
		short moveOrder[9] = {11,00,22,02,20,01,10,21,12};
		int maxEval = -100;
		int tempEval = 0;
		int bestMove = 11;
		if (P.hasWon(P.pos^P.mask)) {
			return -12+P.move;
		}

		if (P.move == 9) {
			return 0;
		}

		for (int i : moveOrder) {
			if (P.canPlay(i)) {

				Position P2(P);
				P2.play(i);
				
				tempEval = -miniMax(P2, false);
				if (zeroDepth) {
				}
				if (tempEval > maxEval) {
					maxEval = tempEval;
					bestMove = i;
				}
			}
		}
		if (zeroDepth) {
			return bestMove;
		}
		return maxEval;
	}
};

#endif 
