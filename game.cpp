/*
    Author:  raghav.blacklist1
*/

#include "macros.hpp"
#include "board.hpp"
#include "engine.hpp"

using namespace std;

Board board;
Engine engine;

void introtext(){

	cout<<" --- Welcome to Tic-Tac-Toe [AUTOMATED] ---\n\n";
	cout<<"Enter cell number to make your move or type hint to get recommendations.\n\n";
}

void printhint(){

	vector<string> ret = engine.hint(board.bstate);
	rep(i,0,ret.size())	cout<<ret[i]<<endl;
}

ll play_move(ll moves, ll prev_move){

	if(prev_move == VALID_MOVE)	board.printboard();
	if(board.won()){

			cout<<"Player 1 Wins!!"<<endl;
			return SIGNAL_EXIT;
		}

		if(board.lost()){

			cout<<"Player 2 Wins!!"<<endl;
			return SIGNAL_EXIT;
		}

		if(board.draw()){

			cout<<"DRAW!!"<<endl;
			return SIGNAL_EXIT;
		}

	string inp;
	cout<<"Player "<<((moves%2)+1)<<" make your move: ";
	cin>>inp;

	if(inp=="exit")	return SIGNAL_EXIT;

	if(inp=="hint"){

		if(moves%2==0)	printhint();
		else	cout<<"Hint allowed only for Player 1."<<endl;
		return INVALID_MOVE;
	}

	ll flag = board.move(stoi(inp));
	if(flag == INVALID_MOVE){

		cout<<"Out of Range or Already Occupied!!"<<endl;
		return INVALID_MOVE;
	}

	return VALID_MOVE;

}

int main(){

	introtext();

	ll moves = 0;
	ll move_state = 1;

	while(true){

		move_state = play_move(moves,move_state);

		if(move_state == SIGNAL_EXIT)	return 0;
		if(move_state == VALID_MOVE)	moves++;
		
	}
	return 0;
}