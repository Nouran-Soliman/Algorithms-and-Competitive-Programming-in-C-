#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
int arr[25];
int n, len, maxi = 0;
vector<int> path;
vector<int> soln;

void max_sum(int sum, int i){
	if(sum > maxi && sum <= n) {
		maxi = sum;
		vector<int>().swap(soln);
		int sz = path.size();
		for(int j = 0; j < sz; j++)
			soln.push_back(path[j]);
	}
	if(i == len) return;

	max_sum(sum, i+1);
	path.push_back(arr[i]);
	max_sum(sum + arr[i], i+1);
	path.pop_back();
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);	//input file
		//freopen("in.out","w",stdout);	//output file

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin >> n){
		cin >> len;
		for(int i = 0; i < len; i++)
			cin >> arr[i];
		max_sum(0,0);

		int sz = soln.size();
		for(int j = 0; j < sz; j++)
			cout << soln[j] << " ";
		cout <<"sum:"<< maxi << endl;
		vector<int>().swap(path);
		maxi = 0;
	}
}
