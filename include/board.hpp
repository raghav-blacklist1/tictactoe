// ==================================================================
// contains all info relating to the game board used in program
// ==================================================================

#ifndef BOARD_H
#define BOARD_H

#include "macros.hpp"

using namespace std;

class Board{

public:
	ll bstate;

	Board();
	ll move(ll cell);
	ll won(ll state = -1);
	ll lost(ll state = -1);
	ll draw(ll state = -1);
	void printboard();
};

#endif