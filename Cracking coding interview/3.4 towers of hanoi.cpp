#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
stack<int> rods[3];
void count_steps(int discs, int src, int buff, int dest){
	if( !rods[src].size() ) return;
	if(discs == 1){
		rods[dest].push(rods[src].top());
		rods[src].pop();
		return;
	}
	int A = src, B = buff, C = dest;
	count_steps(discs-1, A, C, B);
	count_steps(1, A, B, C);
	count_steps(discs-1, B, A, C);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	rods[0].push(5);
	rods[0].push(4);
	rods[0].push(3);
	rods[0].push(2);
	rods[0].push(1);

	count_steps(5, 0, 1, 2);
	while(rods[2].size()){
		cout << rods[2].top() << " ";
		rods[2].pop();
	}
	cout << endl;
	return 0;
}
