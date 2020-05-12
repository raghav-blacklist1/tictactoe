#include "board.hpp"

using namespace std;

// board function definitions

Board::Board(){

	bstate = 0;
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

	if(won(state))	return 0;
	if(lost(state))	return 0;

	vector<ll> ar;
	ll turn = 0;

	rep(i,0,9){

		ar.pb(state%3);
		if(state%3!=0)	turn++;
		state/=3;
	}

	if(ar[0]!=1 && ar[1]!=1 && ar[2]!=1 && (((ar[0]+ar[1]+ar[2])/2) <= ((10-turn)/2)))	return 0;
	if(ar[3]!=1 && ar[4]!=1 && ar[5]!=1 && (((ar[3]+ar[4]+ar[5])/2) <= ((10-turn)/2)))	return 0;
	if(ar[6]!=1 && ar[7]!=1 && ar[8]!=1 && (((ar[6]+ar[7]+ar[8])/2) <= ((10-turn)/2)))	return 0;
	if(ar[0]!=1 && ar[3]!=1 && ar[6]!=1 && (((ar[0]+ar[3]+ar[6])/2) <= ((10-turn)/2)))	return 0;
	if(ar[1]!=1 && ar[4]!=1 && ar[7]!=1 && (((ar[1]+ar[4]+ar[7])/2) <= ((10-turn)/2)))	return 0;
	if(ar[2]!=1 && ar[5]!=1 && ar[8]!=1 && (((ar[2]+ar[5]+ar[8])/2) <= ((10-turn)/2)))	return 0;
	if(ar[0]!=1 && ar[4]!=1 && ar[8]!=1 && (((ar[0]+ar[4]+ar[8])/2) <= ((10-turn)/2)))	return 0;
	if(ar[2]!=1 && ar[4]!=1 && ar[6]!=1 && (((ar[2]+ar[4]+ar[6])/2) <= ((10-turn)/2)))	return 0;
	if(ar[0]!=2 && ar[1]!=2 && ar[2]!=2 && ((ar[0]+ar[1]+ar[2]) <= ((10-turn)/2)))	return 0;
	if(ar[3]!=2 && ar[4]!=2 && ar[5]!=2 && ((ar[3]+ar[4]+ar[5]) <= ((10-turn)/2)))	return 0;
	if(ar[6]!=2 && ar[7]!=2 && ar[8]!=2 && ((ar[6]+ar[7]+ar[8]) <= ((10-turn)/2)))	return 0;
	if(ar[0]!=2 && ar[3]!=2 && ar[6]!=2 && ((ar[0]+ar[3]+ar[6]) <= ((10-turn)/2)))	return 0;
	if(ar[1]!=2 && ar[4]!=2 && ar[7]!=2 && ((ar[1]+ar[4]+ar[7]) <= ((10-turn)/2)))	return 0;
	if(ar[2]!=2 && ar[5]!=2 && ar[8]!=2 && ((ar[2]+ar[5]+ar[8]) <= ((10-turn)/2)))	return 0;
	if(ar[0]!=2 && ar[4]!=2 && ar[8]!=2 && ((ar[0]+ar[4]+ar[8]) <= ((10-turn)/2)))	return 0;
	if(ar[2]!=2 && ar[4]!=2 && ar[6]!=2 && ((ar[2]+ar[4]+ar[6]) <= ((10-turn)/2)))	return 0;
	return 1;

}

ll Board::finish(ll state){

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