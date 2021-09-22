#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
struct node{
	int data, subTreeCount = 0;
	node *left, *right;
};

class Tree{
private:
	node *root;
	bool find_num(int num, node *root){
		if(root == NULL) return false;
		if(root->data == num) return true;

		if(num > root-> data)
			return find_num(num, root->right);

		return find_num(num, root->left);
	}

	int add_all(node *root){
		if(root == NULL) return 0;
		return root->data + add_all(root->right) + add_all(root->left);
	}

	int max_height(node *root){
		if(root == NULL) return 0;
		return 1 + max(max_height(root->right), max_height(root->left));
	}

	int min_height(node *root){
		if(root == NULL) return 0;
		return 1 + min(min_height(root->left), min_height(root->right));
	}

	bool find_num_bin(int num, node *root){
		if(root == NULL) return false;
		if(root->data == num) return true;
		bool ret = false;
		ret |= find_num_bin(num, root->right);
		ret |= find_num_bin(num, root->left);
		return ret;
	}
	void pre_order(node *root){
		if(root == NULL) return;
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
	void in_order(node *root){
		if(root == NULL) return;
		in_order(root->left);
		cout << root->data << " ";
		in_order(root->right);
	}
	void post_order(node *root){
		if(root == NULL) return;
		post_order(root->left);
		post_order(root->right);
		cout << root->data << " ";
	}
public:
	Tree():root(NULL){}

	void insert_element(int data){
		node *new_node = new node{data, NULL, NULL};
		node *prev,  *frnt = root;

		if(root == NULL){
			root = new_node;
		}

		while(frnt != NULL){
			prev = frnt;
			if(data > frnt->data){
				frnt = frnt->right;
			}
			else{
				frnt = frnt->left;
			}
		}

		if(data > prev->data){
			prev->right = new_node;
		}
		else{
			prev->left = new_node;
		}
	}

	bool find_number(int num){
		return find_num(num, root);
	}

	int add_all_nodes(){
		return add_all(root);
	}

	int get_max_height(){
		return max_height(root);
	}

	int get_min_height(){
		return min_height(root);
	}

	bool find_number_bin(int num){
		return find_num_bin(num, root);
	}

	void print_levels(){ //BFS
		if(root == NULL) return;
		queue<node* > q;
		q.push(root);
		while(q.size()){
			int queue_size = q.size();
			for (int i = 0; i < queue_size; i ++) {
				node* c_node = q.front();
				q.pop();

				cout << c_node->data <<" ";

				if(c_node->left != NULL){
					q.push(c_node->left);
				}
				if(c_node->right != NULL)
					q.push(c_node->right);
			}
			cout << endl;
		}
	}

//	void print_levels(){ //BFS
//		if(root == NULL) return;
//		queue< pair<node*, int> > q;
//		int p_level = 1;
//		q.push(pair<node*, int>(root, 1));
//		while(q.size()){
//			pair<node*, int> current = q.front();
//			node *c_node = current.first;
//			int c_level = current.second;
//			q.pop();
//			if(p_level != c_level)
//				cout << endl;
//			cout << c_node->data <<" ";
//			p_level = c_level;
//
//			if(c_node->left != NULL){
//				q.push(make_pair(c_node->left, 1 + c_level));
//			}
//			if(c_node->right != NULL)
//				q.push(make_pair(c_node->right, 1 + c_level));
//		}
//		cout << endl;
//	}
	void pre_order(){
		pre_order(root);
		cout << endl;
	}
	void in_order(){
		in_order(root);
		cout << endl;
	}
	void post_order(){
		post_order(root);
		cout << endl;
	}
	bool balanced(){
		int max_h = get_max_height();
		int min_h = get_min_height();
		return (max_h - min_h) <= 1;
	}
};

node *create_node(int n){
	return new node{n, NULL, NULL};
}

node *build_tree(const vector<int> &vec){	//build balanced BT
	node *tree;
	int v_size = vec.size(), index = 0;
	if(!v_size) return NULL;
	queue<node*> q;
	tree = create_node(vec[index++]);
	q.push(tree);
	while(q.size() && index < v_size){
		node *current = q.front();
		q.pop();
		current->left = create_node(vec[index++]);
		q.push(current->left);
		if(index < v_size){
			current->right = create_node(vec[index++]);
			q.push(current->right);
		}
	}
	return tree;
}

node *build_BST_tree(int s, int e, const vector<int> &vec){
	if(s > e) return NULL;
	int m = (s+e)/2;
	node *new_node = new node{vec[m], NULL, NULL};
	new_node->left = build_BST_tree(s, m-1, vec);
	new_node->right = build_BST_tree(m+1, e, vec);
	return new_node;
}

pair <node*, int> find_ancestor_BT(int n, int m, node *node){
	if(node == NULL) return make_pair(NULL, 0);
	pair <node*, int> ans{NULL, 0}, ans_left, ans_right;
	if(node->data == n || node->data == m)
		ans.second = 1;
	ans_left = find_ancestor_BT(n, m, node->left);
	ans_right = find_ancestor_BT(n, m, node->right);
	ans.second += (ans_left.second + ans_right.second);
	if(ans_left.first != NULL)
		return ans_left;
	if(ans_right.first != NULL)
		return ans_right;
	if(ans.second == 2) ans.first = node;
	return ans;
}

node *find_ancestor_BST(int n, int m, node *curr){
	if(curr == NULL) return NULL;
	if((n < curr->data) && (m < curr->data))
		return find_ancestor_BST(n, m, curr->left);
	if((n > curr->data) && (m > curr->data))
		return find_ancestor_BST(n, m, curr->right);

	return curr;
}

int set_subTreeCount(node *node){
	if(node == NULL) return 0;
	return node->subTreeCount = set_subTreeCount(node->left) + set_subTreeCount(node->right) + 1;
}

node *get_kth_smallest(int k, node *node){
	if(node == NULL) return NULL;
	int left_sub = 0;
	if(node->left != NULL)
		left_sub = node->left->subTreeCount;
	if(left_sub+1 == k) return node;

	if(left_sub >= k)
		return get_kth_smallest(k, node->left);
	return get_kth_smallest(k - left_sub - 1, node->right);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Tree t1;
	t1.insert_element(10);
	t1.insert_element(5);
	t1.insert_element(11);
	t1.insert_element(4);
	t1.insert_element(10);
	t1.insert_element(11);
	t1.insert_element(20);
	t1.insert_element(10);
	t1.insert_element(10);
	t1.insert_element(2);
	t1.insert_element(5);

	//t1.print_levels();
	t1.pre_order();
	t1.in_order();
	t1.post_order();
	return 0;
}
