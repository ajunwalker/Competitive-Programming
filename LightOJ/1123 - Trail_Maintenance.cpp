#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 201

struct edge{
    int from, to, dist;
} edges[MAX];

bool comparator(edge a, edge b) {
    return a.dist < b.dist;
}

int j, c, parent[MAX];

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int minimum(int n, int w){

    int total = 0;
    int trails = 1;

    for (int i = 0; i < w; ++i){

        // Find the parent of the two vertices
        int parentX = find(edges[i].from);
        int parentY = find(edges[i].to);

        // If they are not already connected
        if (parentX != parentY){
            // Attach new node to MST
            parent[parentX] = parentY;
            // Add edge distance to total distance
            total += edges[i].dist;
            // Increment edge counter
            trails += 1;
        }
        // If a redundant edge was found, remove it
        else {
            for(int j = i + 1; j < w; ++j) edges[j-1] = edges[j];
            w -= 1; i -= 1; c -= 1;
        }
    }

    if (trails != n) return -1;
    return total;
}

int main(){
    int C, N, W;
    scanf("%d", &C);

    for (int i = 0; i < C; ++i){
        printf("Case %d:\n", i+1);
        scanf("%d %d", &N, &W);

        for (j = 0, c = 0; j < W; ++j, ++c){

            // Initialise Union-Find
            for (int k = 1; k <= N; ++k) parent[k] = k;

            // Read in next edge
            scanf("%d %d %d", &edges[c].from, &edges[c].to, &edges[c].dist);

            // Sort and run Kruskal's algorithm
            sort(edges, edges+c+1, comparator);
            printf("%d\n", minimum(N, c+1));
        }
    }
}
