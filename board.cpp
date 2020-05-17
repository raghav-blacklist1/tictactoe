#include "board.hpp"

using namespace std;

// board function definitions

Board::Board(){

	bstate = 0;
}

ll Board::move(ll cell){

	if(cell<1 || cell>9)	return INVALID_MOVE;
	ll state = bstate;

	vector<ll> ar;
	ll turn = 0;

	rep(i,0,9){

		ar.pb(state%3);
		if(state%3!=0)	turn++;
		state/=3;
	}

	turn%=2;
	if(ar[cell-1] != 0)	return INVALID_MOVE;

	bstate = bstate + ((turn+1)*pow(3ll,cell-1));
	return VALID_MOVE;
}

ll Board::won(ll state){

	if(state == -1)		state = bstate;
	vector<ll> ar;

	rep(i,0,9){

		ar.pb(state%3);
		state/=3;
	}

	if(ar[0]==1 && ar[1]==1 && ar[2]==1)	return 1;
	if(ar[3]==1 && ar[4]==1 && ar[5]==1)	return 1;
	if(ar[6]==1 && ar[7]==1 && ar[8]==1)	return 1;
	if(ar[0]==1 && ar[3]==1 && ar[6]==1)	return 1;
	if(ar[1]==1 && ar[4]==1 && ar[7]==1)	return 1;
	if(ar[2]==1 && ar[5]==1 && ar[8]==1)	return 1;
	if(ar[0]==1 && ar[4]==1 && ar[8]==1)	return 1;
	if(ar[2]==1 && ar[4]==1 && ar[6]==1)	return 1;
	return 0;
}

ll Board::lost(ll state){

	if(state == -1)		state = bstate;
	vector<ll> ar;

	rep(i,0,9){

		ar.pb(state%3);
		state/=3;
	}

	if(ar[0]==2 && ar[1]==2 && ar[2]==2)	return 1;
	if(ar[3]==2 && ar[4]==2 && ar[5]==2)	return 1;
	if(ar[6]==2 && ar[7]==2 && ar[8]==2)	return 1;
	if(ar[0]==2 && ar[3]==2 && ar[6]==2)	return 1;
	if(ar[1]==2 && ar[4]==2 && ar[7]==2)	return 1;
	if(ar[2]==2 && ar[5]==2 && ar[8]==2)	return 1;
	if(ar[0]==2 && ar[4]==2 && ar[8]==2)	return 1;
	if(ar[2]==2 && ar[4]==2 && ar[6]==2)	return 1;
	return 0;
}

ll Board::draw(ll state){

	if(state == -1)		state = bstate;
	vector<ll> ar;

	rep(i,0,9){

		ar.pb(state%3);
		state/=3;
	}

	rep(i,0,9)	if(ar[i]==0)	return 0;
	return 1;
}

void Board::printboard(){

	vector<ll> ar;
	ll tmp = bstate;
	rep(i,0,9){

		ar.pb(tmp%3);
		tmp/=3;
	}

	cout<<endl;
	rep(i,0,3){

		rep(j,0,3){

			if(ar[3*i + j]==0)	cout<<(3*i+j+1)<<' ';
			else if(ar[3*i + j]==1) cout<<"O"<<' ';
			else if(ar[3*i + j]==2)	cout<<"X"<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}