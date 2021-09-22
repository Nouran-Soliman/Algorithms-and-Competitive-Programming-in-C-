#include<bits/stdc++.h>
using namespace std;
int sticks[10][7] ={
		{1,1,1,1,1,1,0}, //0
		{0,1,1,0,0,0,0}, //1
		{1,1,0,1,1,0,1}, //2
		{1,1,1,1,0,0,1}, //3
		{0,1,1,0,0,1,1}, //4
		{1,0,1,1,0,1,1}, //5
		{1,0,1,1,1,1,1}, //6
		{1,1,1,0,0,0,0}, //7
		{1,1,1,1,1,1,1}, //8
		{1,1,1,1,0,1,1}  //9
};

int taken[10], res=1, c=0;
char inp[2];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> inp[0] >> inp[1];

	for(int k=0;k<2;k++){
	c=0;
	memset(taken, 0, sizeof taken);
	for(int i=0;i<7;i++){
		if(sticks[inp[k]-'0'][i])
			for(int j = 0;j<10;j++)
				if(!sticks[j][i] && !taken[j]){
					c++;
					taken[j]=1;
				}
	}
	res*=(10-c);
	}
	cout << res <<endl;
	return 0;
}
