#include<bits/stdc++.h>
using namespace std;
int iInput[95][4];
char cInput[95][4];
int fouls;
map <char, string> team;
map<char, int> step;
map <char, map <int, int> > mymap;
map <char, map <int, int> > rFlag;
string read;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> read;
	team['h'] = read;
	cin >> read;
	team['a'] = read;
	step['y'] = 1;
	step['r'] = 2;

	cin >> fouls;
	for(int i=0;i<fouls;i++){
		cin >> iInput[i][0]; //min
		cin >> cInput[i][0]; //home | away
		cin >> iInput[i][1]; //player num
		cin >> cInput[i][1]; //card

		mymap[cInput[i][0]][iInput[i][1]] += step[cInput[i][1]];

		if(mymap[cInput[i][0]][iInput[i][1]] >= 2 && rFlag[cInput[i][0]][iInput[i][1]]!=-1){
				cout << team[cInput[i][0]] << " " << iInput[i][1] << " " << iInput[i][0] <<endl;
				rFlag[cInput[i][0]][iInput[i][1]] = -1;
		}
	}


	return 0;
}
