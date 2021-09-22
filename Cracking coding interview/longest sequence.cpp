#include<bits/stdc++.h>
using namespace std;
pair<int, int> person[100];
int longSeq[100];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, maxi = 1, maxInd = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> person[i].first >> person[i].second;
	}
	sort(person, person+n);

	for(int i = 0; i < n; i++){
		longSeq[i] = 1;
		for(int j = i-1; j >= 0; j--){
			if(person[i].second > person[j].second){
				longSeq[i] = max(longSeq[i] , longSeq[j] + 1);
				if(maxi < longSeq[i]){
					maxi = longSeq[i];
					maxInd = i;
				}
			}
		}
	}

	for (int brackets = 0; brackets < (1<<(2*n)); brackets ++) {
		int balanced = 0;
		string str;
		for (int i = 0; i < 2*n; i ++) {
			if (brackets & (1 << i) > 0) {
				balanced += 1;
				str += '(';
			}
			else {
				balanced -= 1;
				str += ')';
			}
		}
		if (balanced == 0) {
			cout << str << endl;
		}
	}


	void solve( string brackets, int balanced, int ind ) {
		if (balanced == 0 && ind == 2*n){
			cout << bracketd << endl;
			return ;
		}
		if (balanced < 0 || ind == 2*n){
			return ;
		}
		brackets += '(';
		solve(brackets, balanced + 1, ind+1);

		brackets.back() = ')';
		solve(brackets, balanced - 1, ind+1);
	}
	----
	0000
	.
	.
	1111

	0: 00 => ))
	1: 01 => )(
	2: 10 => ()
	3: 11 => ((































	num:   1 2 1 4
	order: 1 2 1 3

	vector<pair<int, int> > ans;
	ans.reserve(maxi);
	for ( int i = maxInd; i >= 0; i -- ) {
		ans.push_back( person[i] );
		int j;
		for (j = i-1; j >= 0; j --) {
			if (person[i].second > person[j].second && longSeq[i] == longSeq[j] + 1)
				break;
		}
		i = j+1;
	}

	for ( int i = maxi-1; i >= 0; i -- ) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

//	int c = maxi-1, lst = maxInd;
//	cout << person[maxInd].first << " " << person[maxInd].second << endl;
//	for(int i = maxInd-1; i >= 0; i--){
//		if(longSeq[i] == c && person[i].second < person[lst].second){
//			cout << person[i].first << " " << person[i].second << endl;
//			lst = i;
//			c--;
//		}
//	}

	cout << endl << maxi << endl;
	return 0;
}

/*
W	H
56	90   1
60	100  2
61  101  3
62  102  4
63  103  5
65	95   2
67	98   3
68	150  6
70	110  6
75	16   1

6
*/
