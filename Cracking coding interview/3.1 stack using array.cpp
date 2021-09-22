#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;

#define value first
#define prev second

pair<int, int> mystack[100];
int  next_free = 0;
int top[3] = {-1, -1, -1};

class setOfStacks{
	vector<stack<int> > stacks;
	const int THRESHOLD;
	unsigned total_size;

public:
	setOfStacks() : THRESHOLD(5), total_size(0) {}

	void push(int element){
		if ( !total_size || (int)stacks.back().size() > THRESHOLD ) {
			stacks.push_back(stack<int>());
		}
		stacks.back().push(element);
		total_size ++;

//
//		if(stacks_size && stacks[stacks_size-1].size() < THRESHOLD ){
//			stacks[stacks_size-1].push(element);
//		}
//		else{
//			stack<int> temp;
//			temp.push(element);
//			stacks.push_back(temp);
//		}
	}

	unsigned size() {
		return total_size;
	}

	int top() {
		assert(this->size());
		return stacks.back().top();
	}

	void pop(){
		assert(this->size());
		stacks.back().pop();
		if(!stacks.back().size()){
			stacks.pop_back();
		}
		total_size --;
	}

	int pop_at( int index ) {
		assert(index < this->size());
		setOfStacks *temp = new setOfStacks();
		while (this->size() > index) {
			temp->push( this->top() );
			this->pop();
		}
		int element = this->top();
		this->pop();
		while (temp->size()) {
			this->push( temp->top() );
			temp->pop();
		}
		return element;
	}
};


void push(int element, int stack){
	mystack[next_free].value = element;
	mystack[next_free].prev = top[stack];
	top[stack] = next_free++;
}

int pop(int stack){
	int element;
	assert(top[stack] != -1);
	element = mystack[top[stack]].value;
	top[stack] = mystack[top[stack]].prev;
	next_free--;
	return element;
}
void print_stack(int stack){
	int index = top[stack];
	cout << "********* " << stack << " *********" << endl;
	while(index != -1){
		cout << mystack[index].value << " ";
		index = mystack[index].prev;
	}
	cout << endl;
}

void print_all_stacks(){
	for(int i = 0; i < 3; i++)
		print_stack(i);
	cout << "--------------------------" << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	push(10, 1);
	pop(1);
	print_all_stacks();
	push(10, 1);
	push(9, 1);
	print_all_stacks();
	push(11, 2);
	print_all_stacks();
	push(8, 1);
	pop(1);
	pop(2);
	print_all_stacks();
	pop(2);
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
