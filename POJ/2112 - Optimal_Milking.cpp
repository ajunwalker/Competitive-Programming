#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 300
#define INF 0x3f3f3f

int graph[MAX][MAX];
int capacity[MAX][MAX];
int K, C, M, SIZE;

void initCapacity(int length){
    SIZE = K+C+2;
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j) capacity[i][j] = 0;
    }

    for (int i = K; i < K+C; ++i){
        for (int j = 0; j < K; ++j){
            if (graph[i][j] <= length) capacity[i][j] = 1;
        }
    }

    for (int i = 0; i < K; ++i) capacity[i][SIZE-1] = M;
    for (int i = K; i < K+C; ++i) capacity[SIZE-2][i]= 1;
}

int karp(int s, int t){

    int path[MAX];
    int maxflow = 0;

    while(true){
        for(int i = 0; i < SIZE; ++i) path[i] = -1;
        queue<int> q;

        for(q.push(s); !q.empty() && path[t] == -1; q.pop()){
            int curr = q.front();

            for(int next = 0; next < SIZE; ++next){
                if (capacity[curr][next] >= 1){
                    if (path[next] == -1){
                        path[next] = curr;
                        q.push(next);
                    }
                }
            }
        }

        if (path[t] == -1) break;

        int flow = INF;
        for(int curr = t; curr != s; curr = path[curr]){
            flow = min(flow, capacity[path[curr]][curr]);
        }
        maxflow += flow;

        for(int curr = t; curr != s; curr = path[curr]){
            capacity[path[curr]][curr] -= flow;
            capacity[curr][path[curr]] += flow;
        }
    }

    return maxflow;
}

void floyd(int N){
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < N; ++u){
            for(int v = 0; v < N; ++v){
                graph[u][v] = min(graph[u][v], graph[u][i] + graph[i][v]);
            }
        }
    }
}

int binarySearch(int left, int right, int key){
    while(left < right){
        int mid = (left+right)/2;
        initCapacity(mid);
        int flow = karp(K+C, K+C+1);
        if (flow < key){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main(){

    scanf("%d %d %d", &K, &C, &M);

    for(int i = 0; i < K+C; ++i){
        for(int j = 0; j < K+C; ++j){
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) graph[i][j] = INF;
        }
    }
    floyd(K+C);
    printf("%d\n", binarySearch(1, INF, C));
}
