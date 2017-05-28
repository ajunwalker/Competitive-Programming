#include <cstdio>
#include <vector>
#define MAX 5001
using namespace std;

vector<int> vertices[MAX];
int visited[MAX], low[MAX], connected[MAX];
bool edge[MAX][MAX];
int T = 0;

void tarjan(int curr, int from){
    visited[curr] = low[curr] = ++T;
    for (int i = 0; i < vertices[curr].size(); ++i) {
        int next = vertices[curr][i];
        if (next == from) continue;
        if (!visited[next]){
            tarjan (next, curr);
            low[curr] = min(low[curr], low[next]);
        }
        else{
            low[curr] = min (low[curr], visited[next]);
        }
    }
}

int main(){

    int F, R;
    scanf("%d %d", &F, &R);

    // Initialisation Step
    for(int i = 1; i <= F; ++i) {
        visited[i] = 0;
        low[i] = 0;
        connected[i] = 0;
        for(int j = 1; j <= F; ++j) edge[i][j] = false;
    }

    // Read in all edges and add if it has not been added before
    for (int i = 0; i < R; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        if (!edge[x][y] && !edge[y][x]) {
            edge[x][y] = true;
            vertices[x].push_back(y);
            vertices[y].push_back(x);
        }
    }

    // Perform the Tarjan algorithm on the graph
    tarjan(1,-1);

    // Figure out how many more edges we need
    int ans = 0;
    for(int i = 1; i <= F; ++i){
        for(int j = 0; j < vertices[i].size(); ++j){
            int next = vertices[i][j];
            if(low[i] != low[next]){
                if (!connected[low[next]]) ans++;
                if (connected[low[next]] == 1) ans--;
                connected[low[next]]++;
            }
        }
    }
	printf("%d\n", (ans + 1)/2);
}
