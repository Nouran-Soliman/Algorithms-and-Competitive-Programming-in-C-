#include<bits/stdc++.h>
using namespace std;
#define V 1005

int c1, c2, c3, c4, b, t;
int bus[V], troll[V];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int bCost = 0, tCost = 0;

	cin >> c1 >> c2 >> c3 >> c4 >> b >> t;
	for(int i = 0; i < b; i++){
		cin >> bus[ i ];
		bCost+= min(c1*bus[i], c2);
	}
	bCost = min(bCost, c3);
	for(int i = 0; i < t; i++){
			cin >> troll[ i ];
			tCost+= min(c1*troll[i], c2);
	}
	tCost = min(tCost, c3);
	cout << min(bCost+tCost, c4) << endl;
}
