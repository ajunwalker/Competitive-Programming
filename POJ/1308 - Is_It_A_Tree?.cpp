#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

#define MAX_SIZE 10000

int parent[MAX_SIZE];
set<int> vertices;

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int main(void){

    int x, y, c = 1;

    while(cin >> x >> y && x != -1){

        // Check if it is an empty graph
        if (x + y == 0) {
            printf("Case %d is a tree.\n", c++);
            continue;
        }

        // Initialisations
        vertices.clear();
        for(int i = 0; i < MAX_SIZE; ++i) parent[i] = i;
        bool tree = true;

        for (; x != 0; cin >> x >> y){

            // Check if it is a self loop
            if (x == y) tree = false;

            // Add vertices to set
            vertices.insert(x);
            vertices.insert(y);

            // Find their parents
            int parentX = find(x);
            int parentY = find(y);

            if (parentX == parentY) tree = false;
            if (tree) parent[parentY] = parentX;

        }

        // Check if all nodes have the same parent
        int head = find(*vertices.begin());
        for (set<int>::iterator it = vertices.begin(); it != vertices.end() && tree; it++){
            if (find(*it) != head) tree = false;
        }

        // Print result
        if (tree) printf("Case %d is a tree.\n", c++);
        else printf("Case %d is not a tree.\n", c++);
    }
}
