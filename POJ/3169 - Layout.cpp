#include <cstdio>
#include <algorithm>
using namespace std;

#define DIST_MAX 1000002
#define MAX 1001
#define CONST_MAX 10001

struct edge{
    int x, y, cost;
} L[CONST_MAX], D[CONST_MAX];

int shortest[MAX];

int bellman(int N, int ML, int MD){

    for(int i = 0; i < N; ++i){

        for(int j = 0; j+1 < N; ++j){
            if(shortest[j+1] < DIST_MAX){
                shortest[j] = min(shortest[j], shortest[j+1]);
            }
        }

        for(int j = 0; j < ML; ++j){
            int second = L[j].x - 1;
            if(shortest[second] < DIST_MAX){
                int first = L[j].y - 1;
                int cost = L[j].cost;
                shortest[first] = min(shortest[first], shortest[second] + cost);
            }
        }

        for(int j = 0; j < MD; ++j){
            int second = D[j].y - 1;
            if(shortest[ D[j].y - 1 ] < DIST_MAX) {
                int first =  D[j].x - 1;
                int cost = D[j].cost;
                shortest[first] = min(shortest[first], shortest[second] - cost);
            }
        }
    }

    if (shortest[0] < 0) return -1;
    if (shortest[N-1] == DIST_MAX) return -2;
    return shortest[N-1];
}

int main(){

    int N, ML, MD;
    while(scanf("%d %d %d", &N, &ML, &MD) != EOF){

        for(int i = 0; i < MAX; ++i) shortest[i] = DIST_MAX;
        shortest[0] = 0;

        for(int i = 0; i < ML; ++i){
            scanf("%d %d %d", &L[i].x, &L[i].y, &L[i].cost);
        }

        for(int i = 0; i < MD; ++i){
            scanf("%d %d %d", &D[i].x, &D[i].y, &D[i].cost);
        }
        printf("%d\n", bellman(N, ML, MD));
    }

}
