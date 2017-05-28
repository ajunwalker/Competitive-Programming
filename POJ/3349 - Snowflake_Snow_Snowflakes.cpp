#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100000

int f[MAX][6];
vector<int> table[MAX];

bool identical(int f1, int f2){
    for(int i = 0; i < 6; ++i){
        bool left = f[f1][0] == f[f2][i];
        bool right = f[f1][0] == f[f2][i];
        for(int j = 1; j < 6 && left; ++j){
            left = f[f1][j] == f[f2][(i+j)%6];
        }
        for(int j = 1; j < 6 && right; ++j){
            right = f[f1][j] == f[f2][(i+6-j)%6];
        }
        if(left || right) return true;
    }
    return false;
}

int main(){
    int num, found = 0;
    scanf("%d", &num);
    for(int i = 0; i < num && !found; ++i){
        int total = 0;
        for(int j = 0; j < 6; ++j){
            scanf("%d", &f[i][j]);
            total += f[i][j];
        }
        total %= MAX;
        for(int j = 0; j < table[total].size() && !found; ++j){
            if(identical(table[total][j],i)){
                found = 1;
            }
        }
        table[total].push_back(i);
    }
    if (found) printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
}
