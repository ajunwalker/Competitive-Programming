#include <cstdio>
using namespace std;

#define MAX 601

int graph[MAX][MAX];
bool net[MAX][MAX];
int network[MAX];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

bool find(int row, int curr, int N){
    for (int col = 0; col < N; ++col){
        if (net[row][col] && !graph[curr][col]){
            graph[curr][col] = 1;

            if(network[col] == -1){
                network[col] = row;
                return true;
            }
            else if(find(network[col], curr, N)){
                network[col] = row;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int c;
    scanf("%d", &c);
    for (int i = 1; i <= c; ++i){

        int N, total = 0;
        scanf("%d", &N);

        for (int j = 0; j < MAX; ++j){
            network[j] = -1;
            for (int k = 0; k < MAX; ++k) graph[j][k] = -1;
            for (int k = 0; k < MAX; ++k) net[j][k] = false;
        }

        // Read in the graph
        for (int row = 0; row < N; ++row){
            char line[MAX];
            scanf("%s", line);
            for (int col = 0; col < N; ++col){
                if (line[col] == '#'){
                    graph[row][col] = total;
                    total += 1;
                }
            }
        }

        for (int row = 0; row < N; ++row){
            for (int col = 0; col < N; ++col){
                for (int j = 0; j < 4 && graph[row][col] >= 0; ++j){

                    int y = row+dy[j];
                    int x = col+dx[j];

                    if (y >= 0 && y < N && x >= 0 && x < N && graph[y][x] >= 0) {
                        net[graph[row][col]][graph[y][x]] = true;
                    }
                }
            }
        }
        for(int j = 0; j < MAX; ++j){
            for(int k = 0; k < MAX; ++k) graph[j][k] = 0;
        }

        int answer = 0;
        for (int row = 0; row < total; ++row) answer += find(row, row, total);
        printf("Case %d: %d\n", i, answer/2);
    }
}
