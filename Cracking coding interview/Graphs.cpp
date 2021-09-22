#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
struct GraphNode{
	int label, data;
	vector<GraphNode* > neighbours;
};

class Graph{
private:
	unordered_map<int, GraphNode*> find_node_by_label;

	GraphNode *create_node( int node_label ) {
		unordered_map<int, GraphNode*>::iterator it_node;
	    it_node = find_node_by_label.find(node_label);
		if(it_node == find_node_by_label.end()){
			GraphNode *new_node = new GraphNode{node_label};
			find_node_by_label[node_label] = new_node;
			return new_node;
		}
		return it_node->second;
	}
	GraphNode *get_node(int node_label){
		unordered_map<int, GraphNode*>::iterator found_node;
		found_node = find_node_by_label.find( node_label );
		if ( found_node == find_node_by_label.end() ) return NULL;
		return found_node->second;
	}

	void push_neighbours(queue<GraphNode*> &q, GraphNode *current_node){
		int neigh_size = current_node->neighbours.size();
		for(int j = 0; j < neigh_size; j++){
			GraphNode *neighbour = current_node->neighbours[j];
			q.push(neighbour);
		}
	}

	void push_neighbours(queue<GraphNode*> &q, map<GraphNode*, int> *vis, GraphNode *current_node){
		int neigh_size = current_node->neighbours.size();
		for(int j = 0; j < neigh_size; j++){
			GraphNode *neighbour = current_node->neighbours[j];
			if((*vis).find(neighbour) == (*vis).end()){
				q.push(neighbour);
				(*vis)[neighbour] = (*vis)[current_node] + 1;
			}
		}
	}

	void print_graph_levels(GraphNode *root){ //BFS
		if ( root == NULL ) return ;
		queue<GraphNode*> q;
		q.push( root );
		while(q.size()){
			int q_size = q.size();
			for(int i = 0; i < q_size; i++){
				GraphNode *current_node = q.front();
				q.pop();
				cout << current_node->label <<" ";
				push_neighbours(q, current_node);
			}
			cout << endl;
		}
	}
	map<GraphNode*, int> *shortest_path_BFS(GraphNode *root){
		if ( root == NULL ) return NULL;
		queue<GraphNode*> q;
		map<GraphNode*, int> *vis = new map<GraphNode*, int>();
		q.push( root );
		(*vis)[root] = 0;
		while(q.size()){
			int q_size = q.size();
			for(int i = 0; i < q_size; i++){
				GraphNode *current_node = q.front();
				q.pop();
				push_neighbours(q, vis, current_node);
			}
		}
		return vis;
	}

	int shortest_path_BFS(GraphNode *root, GraphNode *dest){
		if ( root == NULL ) return -1;
		queue<GraphNode*> q;
		map<GraphNode*, int> *vis = new map<GraphNode*, int>();
		q.push( root );
		(*vis)[root] = 0;
		while(q.size()){
			int q_size = q.size();
			for(int i = 0; i < q_size; i++){
				GraphNode *current_node = q.front();
				q.pop();
				if(current_node == dest){
					return (*vis)[current_node];
				}
				push_neighbours(q, vis, current_node);
			}
		}
		return -1;
	}

public:
	void add_directed_edge( int node_label_1, int node_label_2 ){
		GraphNode *node_1 = create_node( node_label_1 );
		GraphNode *node_2 = create_node( node_label_2 );
		node_1->neighbours.push_back(node_2);
	}

	void add_undirected_edge( int node_label_1, int node_label_2 ){
		add_directed_edge(node_label_1, node_label_2);
		add_directed_edge(node_label_2, node_label_1);
	}

	void print_graph_levels(int root){
		print_graph_levels( get_node(root) );
	}

	void get_shortest_path_all(int root){
		map<GraphNode*, int> *ans = shortest_path_BFS(get_node(root));
		map<GraphNode*, int>:: iterator it;
		for(it = (*ans).begin(); it != (*ans).end(); it++){
			cout << it->first->label << " " << it->second << endl;
		}
	}

	void get_shortest_path_node(int root, int dest){
		int dist = shortest_path_BFS(get_node(root), get_node(dest));
		cout << dist << endl;
	}
	bool exists_path(int root, int dest){
		int dist = shortest_path_BFS(get_node(root), get_node(dest));
		if(dist == -1)
			return false;
		return true;
	}
};

void memcopy(void *ptr1, void *ptr2, int len){
//	long long *l_pt1 = (int*) ptr1;
//	int *pt2 = (int*) ptr2;
//	for(int i = 0; i < len/4; i++){
//		pt2[i] = pt1[i];
//	}
//	int *pt1 = (int*) ptr1;
//	int *pt2 = (int*) ptr2;
//	len %= 8;
//	for(int i = 0; i < len/4; i++){
//		pt2[i] = pt1[i];
//	}
//	char *c_pt1 = (char*)pt1;
//	char *c_pt2 = (char*)pt2;
//	len %= 4;
//	for(int i = 0; i < len; i++){
//		c_pt2[i] = c_pt1[i];
//	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
		// freopen("in.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Graph tree;
	tree.add_directed_edge(0, 1);
	tree.add_directed_edge(0, 2);
	tree.add_directed_edge(0, 3);
	tree.add_directed_edge(1, 4);
	tree.add_directed_edge(1, 6);
	tree.add_directed_edge(2, 10);
	tree.add_directed_edge(6, 8);
	tree.add_directed_edge(8, 9);
	//tree.print_graph_levels(0);
	//tree.get_shortest_path_all(0);
	//tree.get_shortest_path_node(9, 0);
	// cout << tree.exists_path(8, 0);

//	int n = 8;
//	int vec[] = {-2, -1, 1, 1, 1, 2, 3, 4};
//	int lower_index = lower_bound(vec, vec+n, 5) - vec;
//	int upper_index = upper_bound(vec, vec+n, 1) - vec;  //lower_bound(vec, vec+n, 1+1);
//	if ( lower_index < n && vec[lower_index] == 5 ) {
//
//	}
//	if ( upper_index > 0 && vec[upper_index - 1] == 5 ) {
//
//	}
//	//cout << upper_index << endl;
//
//
//	int src[] = {1, 2}, des[2];
//	memcopy(src, des, sizeof(int)*2);
//	cout << des[0] << " " << des[1] << endl;

	int arr[10] = {1, 3, 5, 7 , 9};
	int T = 8, sum = 0, count = 0;
	unordered_map< int, int> present;
	present[sum] = 1;
	for(int i = 0; i < 5; i++){
		sum += arr[i];
		if(present.find(sum - T) != present.end()){
			count++;
		}
		present[sum] = 1;
	}
	//cout << count << endl;
	int left = 0, right = 0;
	sum = 0;
	count = 0;
    for(int i = 0; i < 5; i++){
    	if(sum == T){
    		count++;
    		sum -= arr[left];
    		left++;
    	}
    	else if(sum > T){
    		sum -= arr[left];
    		left++;
    	}
    	else{
    		sum += arr[right];
    		right++;
    	}
    }
    cout << count << endl;
	return 0;
}
