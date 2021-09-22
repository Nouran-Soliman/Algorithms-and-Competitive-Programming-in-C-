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

bool insertWZabbat(string temp, int pos, char c) {
	temp.insert(pos, 1, c);
	if ( check_pal(temp) ) {
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

	string inp;
	cin >> inp;

	for (int i = 0 ; i <= (int)inp.size(); i ++) // N
		for (int let = 0; let < 26; let ++) // 26
			if ( insertWZabbat(inp, i, 'a'+let) ) // N
				return 0;
			
	cout << "NA" << endl;

	return 0;
}
