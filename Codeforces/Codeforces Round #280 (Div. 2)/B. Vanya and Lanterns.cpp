#include<bits/stdc++.h>
using namespace std;
int n, L, arr[1005], m = 0;
double res;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> L;


	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr, arr+n);

	for(int i=1; i< n; i++)
		m = max(m, arr[i] - arr[i-1]);

	res = max((double)max(arr[0], L - arr[n-1]), m/2.0);
    cout << setprecision(9) << res << endl;

	return 0;

}
