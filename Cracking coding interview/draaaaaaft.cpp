
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *nxt;
};

struct tNode{
	int data;
	tNode *left, *right;
};

class stack{
private:
	node *s;
public:
	stack(): s(NULL){}
	void push(int num){
		node *newNode = new node{num, NULL};
		if(s == NULL) s = newNode;
		else{
			newNode->nxt = s;
			s = newNode;
		}
	}
	void pop(){
		assert(s != NULL);
		node *del = s;
		s = s->nxt;
		free(del);
	}
	int top(){
		return s->data;
	}
};

class queue{
private:
	node *q;
public:
	queue(){}
	void push(int num){
		node *newNode ={num, NULL};
		if(q == NULL) q = newNode;
		else{
			node *it = q;
			while(it->nxt != NULL){
				it = it->nxt;
			}
			it->nxt = newNode;
		}
	}
	void pop(){
		assert(q != NULL);
		node *del = q;
		q = q->nxt;
		free(del);
	}
	int top(){
		return q->data;
	}
};

class Tree{
private:
	tNode *t;
public:
	Tree(): t(NULL){}
	void insert_element(int data){

	}

		bool find_number(int num){

		}

		int add_all_nodes(){

		}

		int get_max_height(){

		}

		bool find_number_bin(int num){

		}

		void print_levels(){ //BFS

		}

		void pre_order(){

		}
		void in_order(){

		}
		void post_order(){

		}
};
