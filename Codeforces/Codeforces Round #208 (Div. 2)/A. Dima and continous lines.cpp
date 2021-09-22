//============================================================================
// Name        : my.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		//freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, x[1000];

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i];

    for(int s1=0;s1<n-1;s1++)
        for(int s2=s1+1;s2<n-1;s2++)
            if ( (max(x[s1],x[s1+1]) > min(x[s2],x[s2+1])
            	  && min(x[s1],x[s1+1]) < min(x[s2],x[s2+1])
				  && max(x[s2],x[s2+1]) > max(x[s1],x[s1+1]))
            	 || (min(x[s1],x[s1+1]) < max(x[s2],x[s2+1])
            	  && max(x[s1],x[s1+1]) > max(x[s2],x[s2+1])
				  && min(x[s2],x[s2+1]) < min(x[s1],x[s1+1])) ){
                cout << "yes\n";
                //cout << x[s1] << " " << x[s1+1] << " " << x[s2] << " " << x[s2+1];
                return 0;
            }
    cout<<"no\n";
}
