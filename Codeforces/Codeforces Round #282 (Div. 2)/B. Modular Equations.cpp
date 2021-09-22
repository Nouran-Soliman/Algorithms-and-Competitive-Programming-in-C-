#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-9

int a, b, c, cnt=0, i;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	c = a-b;
	if(c < 0) {
		cout << "0" << endl;
		return 0;
	}
	int strt = (int)ceil(sqrt(c) - (1e-9));

	if(!strt){
		cout << "infinity" << endl;
		return 0;
	}
	for (int i = 1; i*i < c; i++)
	if(!(c%i)) cnt+= ((i>b)+(c/i > b));

	if(strt > b) cnt+= (strt*strt == c); //sqrt #
	cout << cnt << endl;

	return 0;
}
