#include<bits/stdc++.h>
using namespace std;
int h[105], n;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int maxi=0, mIndex=0, mini;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> h[i];
		if(i && maxi < h[i] - h[i-1]){
			maxi = h[i]-h[i-1];
			mIndex = i;
		}
	}
	mini = h[2] - h[0];
	for(int i=2; i< n-1;i++)
		mini = min(mini, h[i+1]-h[i-1]);

	cout << max(mini, maxi) << endl;

	return 0;
}
