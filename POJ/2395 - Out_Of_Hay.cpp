#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_EDGE 20000
#define MAX_FARM 2001

int N, M, parent[MAX_FARM];

struct edge{
    int to, from, dist;
} edges[MAX_EDGE];

bool comparator(edge a, edge b) {
    return a.dist < b.dist;
}

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int maximum(int n){

    int maximum = 0;

    for (int i = 0; i < n; ++i){

        // Decompose edge struct
        int x = edges[i].from;
        int y = edges[i].to;
        int dist = edges[i].dist;

        // Find the parent of the two vertices
        int parentX = find(x);
        int parentY = find(y);

        // If they are not already connected
        if (parentX != parentY){
            // Attach new node to MST
            parent[parentX] = parentY;
            // Check edge distance
            if (dist > maximum) maximum = dist;
        }
    }
    return maximum;
}

int main(void) {

    // Initialise Union-Find
    for (int i = 0; i < MAX_EDGE; ++i) parent[i] = i;

    // Read in all edges
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        cin >> edges[i].from >> edges[i].to >> edges[i].dist;
    }

    // Sort edges by distance
    sort(edges, edges+M, comparator);
    cout << maximum(M) << endl;

}
