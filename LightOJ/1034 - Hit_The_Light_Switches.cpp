#include <cstdio>
#include <vector>
#define MAX 10001
using namespace std;

vector<int> postOrder;
vector<int> vertices[MAX];
bool visited[MAX];
bool visitedRev[MAX];

void dfsf(int x){
    visited[x] = true;
    for (int i = 0; i < vertices[x].size(); ++i){
        if (!visited[vertices[x][i]]) dfsf(vertices[x][i]);
    }
    postOrder.push_back(x);
}

void dfsr(int x, int scc){
    visitedRev[x] = true;
    for (int i = 0; i < vertices[x].size(); ++i){
        if (!visitedRev[vertices[x][i]]) dfsr(vertices[x][i], 0);
    }
}

vector<int> topSort(int N){

    // Sorted result
    vector<int> reverse;

    // Perform post order traversal
    for (int i = 1; i <= N; ++i){
        if (!visited[i]) dfsf(i);
    }

    // Reverse post order vector
    for (int i = postOrder.size()-1; i >= 0 ; --i){
        reverse.push_back(postOrder[i]);
    }
    return reverse;
}

int kosaraju(int N, int M){

    // Read in 'M' directed edges
    for (int i = 1; i <= M; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        vertices[x].push_back(y);
    }

    // Find SCC by counting roots in topologically sorted vector
    int sccs = 0;
    vector<int> sorted = topSort(N);
    for (int i = 0; i < sorted.size(); ++i) {
        if (!visitedRev[sorted[i]]) {
            dfsr(sorted[i], sccs++);
        }
    }
    return sccs;
}

int main(void){

    int c;
    scanf("%d", &c);

    // Repeat for 'c' test cases
    for (int i = 0; i < c; ++i){

        // Initialise graph
        postOrder.clear();
        for (int j = 0; j < MAX; ++j) vertices[j].clear();
        for (int j = 0; j < MAX; ++j) visited[j] = false;
        for (int j = 0; j < MAX; ++j) visitedRev[j] = false;

        // Perform Kosaraju's Algorithm
        int N, M;
        scanf("%d %d", &N, &M);
        printf("Case %d: %d\n", i+1, kosaraju(N,M));
    }
}
