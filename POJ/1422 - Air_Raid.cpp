#include <cstdio>
using namespace std;

int network[121][121];
int visited[121];

bool find(int row, int intersections){
    for(int col = 1; col <= intersections; ++col){

        if (network[row][col] != 1 ) continue;
        else if (!visited[col] || find(visited[col], intersections)) {
            visited[col] = row;
            network[row][col]++;
            return true;
        }
    }
    return false;
}

int main(){
    int c, intersections, streets;

    // Repeat for given number of cases
    scanf("%d", &c);
    for(int i = 0; i < c; ++i){

        // Read in number of intersections and streets
        scanf("%d", &intersections);
        scanf("%d", &streets);

        // Network initialisation
        for(int row = 1; row <= intersections; ++row) visited[row] = false;
        for(int row = 1; row <= intersections; ++row){
            for(int col = 1; col <= intersections; ++col){
                network[row][col] = 0;
            }
        }

        // Read in connections
        for(int j = 1; j <= streets; ++j){
            int x, y;
            scanf("%d %d", &x, &y);
            network[x][y] = 1;
        }

        // From each point in the network, perform the Hungarian algorithm
        int ans = intersections;
        for(int row = 1; row <= intersections; ++row) ans -= find(row, intersections);
        printf("%d\n", ans);
    }
}
