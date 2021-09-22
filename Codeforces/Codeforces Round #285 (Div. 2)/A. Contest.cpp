#include<bits/stdc++.h>
using namespace std;
#define EPS 0.000000001

float max(float f1, float f2){
	if(f1+EPS > f2+EPS) return f1;
	return f2;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p1, p2, t1, t2;
	cin >> p1 >> p2 >> t1 >> t2;

	float misha = max((0.3 * p1), (p1 - (p1/250.0)*t1));
	float vasya = max(0.3 * p2, p2 - (p2/250.0)*t2);

	//float misha = max(p1, p2);

	if(misha+EPS > vasya+EPS) cout << "Misha" << endl;
	else if(misha+EPS < vasya+EPS) cout << "Vasya" << endl;
	else cout << "Tie" << endl;
	return 0;
}
