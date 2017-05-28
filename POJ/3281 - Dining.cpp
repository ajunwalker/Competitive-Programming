#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f
#define MAX 1000

int capacity[MAX][MAX];
int path[MAX];

int karp(int s, int t, int SIZE){
    int maxflow = 0;
    while(true){
        for(int i = 0; i < SIZE; ++i) path[i] = -1;
        queue<int> q;

        for(q.push(s), path[s] = -2; !q.empty(); q.pop()){
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
        for(int curr = t; curr != 0; curr = path[curr]){
            flow = min(flow, capacity[path[curr]][curr]);
        }
        maxflow += flow;

        for(int curr = t; curr != 0; curr = path[curr]){
            capacity[path[curr]][curr] -= flow;
            capacity[curr][path[curr]] += flow;
        }
    }
    return maxflow;
}

int main(){

    int C, F, D;
    scanf("%d %d %d", &C, &F, &D);
    int SIZE = 2 + F + D + 2*C;

    // Initialise entire network
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            capacity[i][j] = 0;
        }
    }

    // Add connections from super source to food
    for(int i = 1; i <= F; ++i){
        capacity[0][i] = 1;
    }

    // Add connections between first and second layer cows
    for(int i = 0; i < C; ++i){
        capacity[i+1+F][i+1+F+C] = 1;
    }

    // Read in each cows preference
    for(int i = 1; i <= C; ++i){

        int Fi, Di, item;
        scanf("%d %d", &Fi, &Di);

        for(int j = 0; j < Fi; ++j){
            scanf("%d", &item);
            capacity[item][i+F] = 1;
        }

        for(int j = 0; j < Di; ++j){
            scanf("%d", &item);
            capacity[F+C+i][F+2*C+item] = 1;
        }
    }

    // Add connections between drinks and super sink
    for(int i = 0; i < D; ++i){
        capacity[1+F+2*C+i][1+F+2*C+D] = 1;
    }

    printf("%d\n", karp(0,SIZE-1,SIZE));
    /*
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            printf("%d ", capacity[i][j]);
        }
        printf("\n");
    }
    */
}
