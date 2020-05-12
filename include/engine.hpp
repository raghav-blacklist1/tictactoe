// ==================================================================
// contains all info relating to the game engine used in program
// ==================================================================

#ifndef ENGINE_H
#define ENGINE_H

#include "macros.hpp"
#include "board.hpp"

using namespace std;

class Engine{

public:
	ll cons = 19683;
	ll states[MAX];

	Engine();
	ll solve(ll state);
	vector<string> hint(ll state);
};

#endif