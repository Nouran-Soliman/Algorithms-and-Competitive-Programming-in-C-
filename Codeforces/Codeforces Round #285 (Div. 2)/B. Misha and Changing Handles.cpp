#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, string> output, old;
	map<string, string>::iterator it;
	string inp1, inp2;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin>> inp1 >> inp2;
		//if ( output.find( old[inp1] ) == output.end() ) {
		if(!output.count(old[inp1])){
			output[inp1] = inp2;
			old[inp2] = inp1;
		}
		else{
			output[old[inp1]] = inp2;
			old[inp2] = old[inp1];
		}
	}
	int sz = output.size();
	cout << sz << endl;
	for(it = output.begin(); it!=output.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
