#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 101
int dist[MAX][MAX];

void floyd(int count){
    for(int i = 1; i <= count; ++i){
        for(int u = 1; u <= count; ++u){
            for(int v = 1; v <= count; ++v){
                dist[u][v] = min(dist[u][v], dist[u][i]+dist[i][v]);
            }
        }
    }
}

void find(int count){
    int mn = 123456, index = 0;
    for(int i = 1; i <= count; ++i){
        int mx = 0;
        for(int j = 1; j <= count; ++j) if (i != j) mx = max(mx, dist[i][j]);
        if (mx < mn){
            mn = mx;
            index = i;
        }
    }
    (!index) ? printf("disjoint\n") : printf("%d %d\n", index, mn);
}

int main(){
    int brokers, friends, fr, time;

    while(scanf("%d", &brokers) && brokers != 0){
        for(int i = 1; i <= MAX; ++i){
            for(int j = 1; j <= MAX; ++j) dist[i][j] = 123456;
        }

        for(int i = 1; i <= brokers; ++i){

            scanf("%d", &friends);
            for(int j = 0; j < friends; ++j){

                scanf("%d %d", &fr, &time);
                dist[i][fr] = time;
            }
        }
        floyd(brokers);
        find(brokers);
    }
}
