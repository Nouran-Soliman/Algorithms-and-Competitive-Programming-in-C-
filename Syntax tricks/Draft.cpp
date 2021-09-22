#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *nxt;
};

node *Initialize_node(int n){
	node *p=new node();
	p->data=n;
	p->nxt = NULL;
	return p;
}
class mystack{
    node *s;
public:
    mystack(){
        s=NULL;
    }
    void push(int n){
        node *p=Initialize_node(n);
        if(s==NULL) s=p;
        else{
            p->nxt=s;
            s=p;
        }
        }
    void pop(){
        node *p=s;
        if(p!=NULL) {
            s=p->nxt;
            free(p);
        }
    }
    int top(){
        return s->data;
    }
};

class myqueue{
    node *q;
public:
    myqueue(){
        q=NULL;
    }
    void add(int n){
        node *p=Initialize_node(n);
       if(q == NULL) q = p;
       else{
           node *i = q;
           while(i->nxt != NULL)
        	   i = i->nxt;
           i->nxt = p;
       }
    }
    void remove(){
        if(q != NULL){
        	node *p = q;
        	q = q->nxt;
        	free(p);
        }
    }
    int top(){
        return q->data;
    }
};

int getlen( char * str ) {
	if (str == NULL) return 0;
	int sz = 0;
	while (*str ++)
		sz ++;
	while (str[i ++] != NULL)
		sz ++;
	return sz;
}

//'a' 'b' 'c' 'd' '\0'		pointer++
// 0   1   2   3    4
// 13 14   15  16   17 18 . . . . .
// str = 13



void reverse_str(string str[]) {
	if(str == NULL) return;
	int sz = strlen(str);
	for(int i=0;i<sz/2;i++){
		swap(str[i], str[sz-i-1]);
	}
}

//11100
//11010 -> 11011 -> 11100
//
//1010101
//1001101
//10011
//10110
//011 -> 100 -> 101
//
//11101

void reverse_str(char * str) {
	if(str == NULL) return;
	char * end = str;


}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char str[100];
	cin >> str;
	reverse_str(str);
	cout << str;
	vector<int> x;
	sort(x, );
	//swap(str[i], str[i+1]);

/*
	mystack stack ;
	stack.push(1);
	stack.push(2);

	mystack *p = &stack;
	while(p!=NULL){
		cout << stack.top() << " ";
		stack.pop();
	}
*/
	return 0;
}

/*
Given N numbers calculate the frequency of each number in the array.
N <= 1,000,000
each number <= 1000

Solve it in constant memory complexity.
*/\

public static void removeDuplicates(char[] str) {
 if (str == null) return;
 int len = str.length;
 if (len < 2) return;

 int tail = 1;

 for (int i = 1; i < len; ++i) {
     int j;
     for (j = 0; j < tail; ++j) {
     if (str[i] == str[j]) break;
     }
     if (j == tail) {
     str[tail] = str[i];
     ++tail;
     }
 }
 str[tail] = 0;
 }


void replace(char *&tr[], const int newSize){
	if(str == NULL) return;
	char *newStr = new char[newSize];

	newStr[i] = str[i];

	free(str);
	str = newStr;
}

replace(str, strlen(str)+2);



//W	H
//56	90
//60	100
//65	95 unfit = 2
//67	98
//68	150
//70	110
//75	190
