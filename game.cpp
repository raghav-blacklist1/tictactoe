/*
    Author:  raghav.blacklist1
*/

#include "macros.hpp"
#include "board.hpp"
#include "engine.hpp"

using namespace std;

int main(){

	cout<<" --- Welcome to Tic-Tac-Toe [AUTOMATED] ---\n\n Enter cell number to make your move or type hint to get recommendations.\n\n";

	Board board;
	Engine engine;
	ll turn = 0;
	ll flag = 1;

	while(true){

		if(flag == 1)	board.printboard();
		string inp;
		cout<<"Player "<<(turn+1)<<" make your move: ";
		cin>>inp;
		cout<<endl;

		if(inp=="exit")	return 0;

		if(inp=="hint"){

			vector<string> ret = engine.hint(board.bstate);
			rep(i,0,ret.size())	cout<<ret[i]<<endl;
			flag=0;
			continue;
		}		

		ll num = stoi(inp);
		vector<ll> ar;
		ll tmp = board.bstate;
		rep(i,0,9){

			ar.pb(tmp%3);
			tmp/=3;
		}

		if(ar[num-1]!=0){

			cout<<"Already Occupied!!"<<endl;
			flag = 0;
			cout<<endl;
			continue;
		}

		board.bstate = board.bstate + ((turn+1)*pow(3ll,num-1));
		turn = 1 - turn;
		flag = 1;

		if(board.won()){

			cout<<"Player 1 Wins!!"<<endl;
			return 0;
		}

		if(board.lost()){

			cout<<"Player 2 Wins!!"<<endl;
			return 0;
		}

		if(board.finish()){

			cout<<"DRAW!!"<<endl;
			return 0;
		}
		cout<<endl;
		
	}
	return 0;
}