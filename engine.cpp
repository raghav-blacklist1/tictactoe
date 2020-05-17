#include "board.hpp"
#include "engine.hpp"

using namespace std;

// engine function definitions

Engine::Engine(){

	rep(i,0,MAX)	states[i] = -1;

	Board tmp;
	rep(i,0,MAX){

		if(tmp.won(i)){

			states[i] = 1;
		}
		if(tmp.lost(i)){

			states[i] = 0;
		}
		if(tmp.draw(i)){

			states[i] = 2;
		}
	}

	solve(0);
}

ll Engine::solve(ll state){

	if(states[state] != -1)	return states[state];

	vector<ll> ar;

	ll tmp = state;
	ll turn = 0;

	rep(i,0,9){

		ar.pb(tmp%3);
		if((tmp%3)!=0)	turn++;
		tmp/=3;
	}

	turn%=2;
	ll calls[3] = {0};

	rep(i,0,9){

		if(ar[i]!=0)	continue;
		ll newstate = state + ((turn+1)*pow(3ll,i));
		ll ret = solve(newstate);
		calls[ret]++;		
	}

	if((calls[0] + calls[1]) == 0)	return states[state] = 2;
	if(turn == 0){

		return states[state] = (calls[1]>0);
	}
	else{

		return states[state] = (calls[0]==0);
	}
	
}

vector<string> Engine::hint(ll state){

	vector<string> ret;
	ll turn = 0;
	vector<ll> ar;
	ll tmp = state;

	rep(i,0,9){

		ar.pb(tmp%3);
		if(tmp%3!=0)	turn++;
		tmp/=3;
	}

	turn%=2;

	if(states[state]==2){

		ret.pb("Oops, the game has tied!!!");
		return ret;
	}

	if((turn==0 && states[state]==0) || (turn==1 && states[state]==1)){

		ret.pb("DANGER, you may lose afterall!!!");
		return ret;
	}

	vector<ll> ans1,ans2;

	rep(i,0,9){

		if(ar[i]!=0)	continue;
		ll newstate = state + ((turn+1)*pow(3ll,i));

		if(states[newstate]==2)	ans2.pb(i+1);
		else if((turn==0 && states[newstate] == 1) || (turn==1 && states[newstate] == 0))	ans1.pb(i+1);
	}

	string val = "To win, place at: ";
	if(ans1.size()==0)	val+="Empty Set!!";
	rep(i,0,ans1.size()){

		val += to_string(ans1[i]);
		if(i!=(ans1.size()-1))	val += ", ";
	}

	ret.pb(val);
	val = "To draw, place at: ";
	if(ans2.size()==0)	val+="Empty Set!!";
	rep(i,0,ans2.size()){

		val += to_string(ans2[i]);
		if(i!=(ans2.size()-1))	val += ", ";
	}

	ret.pb(val);
	return ret;
}