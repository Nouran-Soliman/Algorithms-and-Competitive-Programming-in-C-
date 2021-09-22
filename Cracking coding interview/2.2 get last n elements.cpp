#include<bits/stdc++.h>
#include <tr1/unordered_map>
#define COUNTER first
#define NODE second

using namespace std;

struct node{
    int data;
    node *nxt;
};

typedef pair<int, node*> pin;

node * ins_last(int n, node *head){
    node *p=new node();
    node *q=head;
    p->data=n;
    p->nxt=NULL;
    if(head==NULL) head=p;
    else{
        while(q->nxt!=NULL)
            q=q->nxt;
        q->nxt=p;
    }
    return head;
}

pin pointToN(int n, node *list){
	if(list == NULL) {
		return pin(0, NULL);
	}
	pin ret = pointToN(n, list->nxt);
	ret.COUNTER ++;
	if(ret.COUNTER == n){
		ret.NODE = list;
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}
