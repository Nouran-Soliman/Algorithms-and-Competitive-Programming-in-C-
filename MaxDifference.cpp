#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int maxD=-1, mini = arr[0];
	for(int i=1;i<n;i++){
		mini = min(mini, arr[i-1]);
		maxD = max(maxD, arr[i]-mini);
	}
	cout << maxD << endl; // perfect :)
	return 0;
}
/*
 	 input:
 	 7
 	 2 3 10 2 4 8 1

 	 output:
 	 8
 */
