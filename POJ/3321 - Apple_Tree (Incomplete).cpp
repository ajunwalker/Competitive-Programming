#include <cstdio>
#include <vector>
using namespace std;
#define MAX_SIZE 100011
int SIZE;

struct Node{
	int index;
	int subtree_max;    // Subtree maximum index
	int notPicked;        // Whether the apple has been picked or not
};

vector<int> branch[MAX_SIZE];   // Input branches
Node nodes[MAX_SIZE];           // Array of nodes
int tree[MAX_SIZE];             // BIT Tree
int curr_node = 1;              // Current index of node

// Flatten tree
void BIT(int node, int p){
	nodes[node].index = curr_node++;
	nodes[node].notPicked = 1;
	//printf("%d\n", node);
	for(int i = 0; i < branch[node].size(); ++i){
		if(p == branch[node][i])		continue;
		BIT(branch[node][i], node);
	}
	nodes[node].subtree_max = curr_node;
	//cout<< " -- "<<node<<" "<<nodes[node].index<<" "<<curr_node<<endl;
}

int sum(int i){
	int total = 0;
	for(; i > 0; i -= i&-i){
		total += tree[i];
	}
	return total;
}

void add(int i, int value){
	for(; i <= SIZE; i += i&-i) tree[i] += value;
}

int main(){

	scanf("%d", &SIZE);
	for(int i = 0; i < SIZE - 1; ++i){
		int from, to;
		scanf("%d %d", &from, &to);
		branch[from].push_back(to);
		branch[to].push_back(from);
	}

	// Flatten tree
	for(int a=0;a<=MAX_SIZE;a++){
		tree[a] = 0;
	}
	BIT(1, 1);

	// Construct BIT
	for(int i = 1; i <= SIZE; ++i){
		add(i, 1);
	}

	int queries;
	scanf("%d", &queries);

	for(int i = 1; i <= queries; ++i){
		char command[2];
		int fork;
		scanf("%s%d", command, &fork);
		if (command[0] == 'C'){
			nodes[fork].notPicked *= -1;
			add(nodes[fork].index, nodes[fork].notPicked);
		} else {
			printf("%d\n", sum(nodes[fork].subtree_max-1) - sum(nodes[fork].index-1));
		}
	}
	return 0;

}
