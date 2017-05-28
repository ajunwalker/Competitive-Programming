#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge{
    int x, y;
}edges[200];

float dist[2000][2000];

void floyd(int count){
    for(int i = 0; i < count; ++i){
        for(int u = 0; u < count; ++u){
            for(int v = 0; v < count; ++v){
                dist[u][v] = min(dist[u][v], max(dist[u][i],dist[i][v]));
            }
        }
    }
}

void construct(int count){
    for(int u = 0; u < count; ++u){
        for(int v = 0; v < count; ++v){
            double left = pow(1.0*edges[u].x-edges[v].x,2);
            double right = pow(1.0*edges[u].y-edges[v].y,2);
            dist[u][v] = sqrt(left+right);
            dist[v][u] = dist[u][v];
        }
    }
}

int main(){
    int count, c = 0;
    while(scanf("%d", &count) && count != 0){

        memset(dist,0,sizeof dist);

        for(int i = 0; i < count; ++i){
            scanf("%d %d", &edges[i].x, &edges[i].y);
        }
        construct(count);
        floyd(count);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++c, dist[0][1]);
    }
}
