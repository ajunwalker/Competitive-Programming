#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1e18

long long grid[3][100001];
long long memo[3][100001];

// Find sum between two grid points x,y1 and x,y2
long long colSum(int x, int y1, int y2){
    long long total = 0;
    if (y1 > y2) for(; y2 <= y1; ++y2) total += grid[y2][x];
    else for(; y1 <= y2; ++y1) total += grid[y1][x];
    return total;
}

int main(){

    int size;
    cin >> size;

    for(int y = 0; y < 3; ++y){
        for(int x = 1; x <= size; ++x){
            cin >> grid[y][x];
        }
    }

    // Initialise memoization table
    for(int y = 0; y < 3; ++y) memo[y][0] = 0;
    memo[0][1] = grid[0][1];
    for(int y = 1; y < 3; ++y) memo[y][1] = memo[y-1][1] + grid[y][1];

    for(int x = 2; x <= size; ++x){
        for(int y1 = 0; y1 < 3; ++y1){
            memo[y1][x] = -MAX;

            // Find path that maximises the score from the pervious
            // column to the current grid point
            for(int y2 = 0; y2 < 3; ++y2){
                memo[y1][x] = max(memo[y1][x], memo[y2][x-1] + colSum(x, y1, y2));
            }

            // Find the sum of two columns for zigzag paths
            long long doubleCol = colSum(x, 0, 2) + colSum(x-1, 0, 2);
            memo[0][x] = max(memo[0][x], memo[2][x-2] + doubleCol);
            memo[2][x] = max(memo[2][x], memo[0][x-2] + doubleCol);
            memo[0][x] = max(memo[0][x], memo[0][x-2] + doubleCol);
            memo[2][x] = max(memo[2][x], memo[2][x-2] + doubleCol);
        }
    }
    cout << memo[2][size];
}
