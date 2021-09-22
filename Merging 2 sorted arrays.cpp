#include<bits/stdc++.h>
using namespace std;
int arr1[1005], arr2[1005], res[2010];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2;
	cin >> n1;
	for(int i=0;i<n1;i++)
		cin >> arr1[i];
	cin >> n2;
	for(int i=0;i<n2;i++)
		cin >> arr2[i];

	sort(arr1, arr1+n1);
	sort(arr2, arr2+n2);

	int i1 = 0, i2 = 0;

//	while ( i1 <n1 || i2 < n2 ) {
//		int val1 = i1 < n1? arr1[i1] : INT_MAX;
//		int val2 = i2 < n2? arr2[i2] : INT_MAX;
//		if( val1 < val2) {
//			res[i1+i2] = val1;
//			i1 ++;
//		}
//		else {
//			res[i1+i2] = val2;
//			i2 ++;
//		}
//	}

	for(int i=0;i<n1+n2;i++){
		if(i1 == n1
		   ||
		   ( i2 < n2 && arr1[i1] > arr2[i2] )) {
			res[i] = arr2[i2++];
		}
		else /*if(i2 == n2 || arr1[i1] < arr2[i2])*/{
			res[i] = arr1[i1++];
		}
	}
	int array_size = n1 + n2; // Google C++ style format
	for(int i = 0; i < array_size ; i++)
		cout << res[i] <<" ";
	cout << endl;

	return 0;
}

/*
input:
5
1 3 4 7 10
5
2 5 6 8 9

output:
1 2 3 4 5 6 7 8 9 10
 */
