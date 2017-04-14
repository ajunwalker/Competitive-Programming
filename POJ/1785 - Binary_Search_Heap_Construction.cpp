#include <algorithm>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
	int index;
	int priority;
    int left;
    int right;
    int parent;
};

Node tree[50001];
char label[50001][101];
int priority[50001];
int pointer[50001];

bool cmp(int a, int b) { return strcmp(label[a], label[b]) < 0; }

void inOrderTraversal(int node) {
	if(node == 0) return;
	cout << "(";
	inOrderTraversal(tree[node].left);
	printf("%s/%d", label[tree[node].index], tree[node].priority);
	inOrderTraversal(tree[node].right);
	cout << ")";
}

void insertHeap(int curr, int newNode) {

    // Recurse up tree until to find location to insert node
	while(tree[curr].priority < tree[newNode].priority && curr > 0){
        curr = tree[curr].parent;
    }

	tree[newNode].left = tree[curr].right;
    tree[newNode].parent = curr;
	tree[curr].right = newNode;
}

int main() {
	int count;
    scanf("%d", &count);
	while(count != 0) {

        // Read in the line
		for(int i = 1; i <= count; i++) {
			scanf(" %[a-z]/%d", label[i], &priority[i]);
			pointer[i] = i;
		}

        // Sort pointer by characters
		sort(pointer+1, pointer+1+count, cmp);

        // Initialise nodes for heap and insert
		for(int i = 0; i <= count; i++) {

			tree[i].left = 0;
            tree[i].right = 0;
            tree[i].parent = 0;

            if (i == 0){
                tree[0].priority = 0;
            }
            else {
                tree[i].priority = priority[pointer[i]];
                tree[i].index = pointer[i];
                insertHeap(i-1, i);
            }
		}

		inOrderTraversal(tree[0].right);
        printf("\n");
        scanf("%d", &count);
	}
	return 0;
}
