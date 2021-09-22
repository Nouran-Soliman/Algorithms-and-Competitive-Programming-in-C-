#include<bits/stdc++.h>
using namespace std;
void addVal(string &temp, int val){
	int sz=temp.length();
	for(int i=0;i<sz;i++){
		int int_val = (temp[i] - '0' + val) % 10;
		temp[i] = '0' + int_val;
	}
}
void shiftRight(/*const string &str,*/ string &temp){
	//if (temp == NULL) return ;
	int sz = temp.length();
	int last = temp[sz-1];
	for(int i=sz-1;i>0;i--){
		temp[i] = str[i];
		temp[i] = temp[i-1];
	}
	temp[0] = last;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string str, mini = "z";

	cin >> n >> str;

	for(int i=0;i<n;i++){
		str = addVal(str, 10-(str[0]-'0'));
		mini = min(mini, str);
		str = shiftRight(str);
	}
	cout << mini << endl;
	return 0;
}
