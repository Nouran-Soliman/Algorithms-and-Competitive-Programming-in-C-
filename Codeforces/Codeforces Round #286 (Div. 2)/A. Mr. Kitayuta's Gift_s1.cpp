#include<bits/stdc++.h>
using namespace std;

string inp;

bool check_pal(string cpy){ // N/2
	string temp = cpy;
	reverse(cpy.begin(), cpy.end());
	return temp == cpy;

	int s=0, e = cpy.length()-1;

	while(s<e && cpy[s++] == cpy[e --]);

	return (s >= e);
}

bool insertWZabbat(string temp, int pos, char c) { // N
	temp.insert(pos, 1, c); // N + 1 = N
	if ( check_pal(temp) ) { // N/2 = N
		cout << temp <<endl;
		return 1;
	}
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> inp;

	int s = 0, e;
	e= inp.length()-1;
//O(N)
	while(s<=e){ // N/2 = N
		if(inp[s] != inp[e]){
			if( !insertWZabbat(inp, s, inp[e]) && !insertWZabbat(inp, e+1, inp[s]) ) // N
				cout << "NA" << endl;
			return 0;
		}
		s++; e--;
	}
	inp.insert(s, 1, inp[s-1]); // N
	cout << inp << endl;

	return 0;
}
