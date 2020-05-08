/*
    Author:  raghav.blacklist1
*/

#include<bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define endl        '\n'
#define ln(a,b)     ((a==(b-1))?'\n':' ')
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define trace(x)    cerr<<#x<<": "<<x<<" "<<endl;
#define MAX			39366

using namespace std;

ll cons = 19683;
ll states[MAX];

ll won(ll state){

	vector<ll> ar;

	rep(i,0,10){

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

ll lost(ll state){

	vector<ll> ar;

	rep(i,0,10){

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

ll draw(ll state){

	vector<ll> ar;

	rep(i,0,9){

		ar.pb(state%3);
		state/=3;
	}

	rep(i,0,9)	if(ar[i]==0)	return 0;
	return 1;
}

ll solve(ll state){

	if( states[state] != -1)	return states[state];

	vector<ll> ar;

	ll tmp = state;

	rep(i,0,10){

		ar.pb(tmp%3);
		tmp/=3;
	}

	ll flag = 0;

	rep(i,0,9){

		if(ar[i]!=0)	continue;
		ll turn = ar[9];
		ll newstate = (state%cons) + ((turn+1)*pow(3ll,i));
		if(turn == 0)	newstate += cons;

		if(solve(newstate) == 0)	flag=1;
	}

	return states[state] = flag;
}

void build(){

	rep(i,0,MAX)	states[i] = -1;

	rep(i,0,MAX){

		if(won(i)){

			if((i/cons)==1)	states[i]=0;
			else	states[i]=1;
		}
		if(lost(i)){

			if((i/cons)==1)	states[i]=1;
			else	states[i]=0;
		}
	}

	solve(0);
}

void hint(ll state){

	//cout<<state<<endl;
	if(states[state]==0){

		cout<<"Oops, it is a losing state, your only hope is your opponent!!!"<<endl;
		return;
	}

	vector<ll> ar;

	ll tmp = state;

	rep(i,0,10){

		ar.pb(tmp%3);
		tmp/=3;
	}

	vector<ll> ans;

	rep(i,0,9){

		if(ar[i]!=0)	continue;
		ll turn = state/cons;
		ll newstate = (state%cons) + ((turn+1)*pow(3ll,i));

		if(turn == 0)	newstate += cons;

		if(states[newstate] == 0)	ans.pb(i);
	}

	cout<<"Place at: ";
	rep(i,0,ans.size())	cout<<ans[i]+1<<((i==ans.size()-1)?".\n":", ");
}

void printboard(ll board){

	vector<ll> ar;
	ll tmp = board;
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

int main(){

	cout<<" --- Welcome to Tic-Tac-Toe [AUTOMATED] ---"<<endl;
	build();

	ll board = 0;
	ll turn = 0;
	ll flag = 1;

	while(true){

		if(flag == 1)	printboard(board);
		string inp;
		cout<<"Player "<<(turn+1)<<" make your move: ";
		cin>>inp;
		cout<<endl;
		ll state = board + cons*turn;

		if(inp=="exit")	return 0;

		if(inp=="hint"){

			hint(state);
			flag=0;
			continue;
		}		

		ll num = stoi(inp);
		vector<ll> ar;
		ll tmp = board;
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

		board = board + ((turn+1)*pow(3ll,num-1));
		turn = 1 - turn;
		flag = 1;

		if(won(board)){

			cout<<"Player 1 Wins!!"<<endl;
			return 0;
		}

		if(lost(board)){

			cout<<"Player 2 Wins!!"<<endl;
			return 0;
		}

		if(draw(board)){

			cout<<"DRAW!!"<<endl;
			return 0;
		}
		cout<<endl;
		
	}
	return 0;
}