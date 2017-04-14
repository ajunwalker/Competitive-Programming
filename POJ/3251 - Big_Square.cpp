#include <cstdio>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int size;
string grid[201];

int checkSize(int y1, int x1, int y2, int x2, int diff_x, int diff_y){

    int area = diff_y * diff_y + diff_x * diff_x;

    // Check if it makes any valid squares
    if ( y1-diff_x >= 0 && x1+diff_y >= 0 && y2-diff_x >= 0 && x2+diff_y >= 0 && y1-diff_x < size && x1+diff_y < size && y2-diff_x < size && x2+diff_y < size ){

        if ((grid[y1-diff_x][x1+diff_y] == 'J') && (grid[y2-diff_x][x2+diff_y] == 'J')){
            return area;
        }

    }

    if ( y1+diff_x >= 0 && x1-diff_y >= 0 && y2+diff_x >= 0 && x2-diff_y >= 0 && y1+diff_x < size && x1-diff_y < size && y2+diff_x < size && x2-diff_y < size ){

        if ((grid[y1+diff_x][x1-diff_y] == 'J') && (grid[y2+diff_x][x2-diff_y] == 'J')){
            return area;
        }

    }

    return 0;
}

int main(){

    // Read in size of grid
    scanf("%d", &size);

    // Populate grid
    for (int i = 0; i < size; ++i){ cin >> grid[i]; }

    int largest = 0;

    // Loop through grid
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){

            if (grid[i][j] == 'J'){

                // Loop backwards though the grid
                for (int a = size; a > i; --a){
                    for (int b = size; b > j; --b){

                        // Compute the distance between the two points
                        int diff_y = i-a;
                        int diff_x = j-b;
                        int area = diff_y*diff_y + diff_x*diff_x;


                        // Check if the area between the two points is greater than current largest
                        if ( (area > largest) && (grid[a][b] != 'B') ){
                            largest = max(largest, checkSize(i, j, a, b, diff_x, diff_y));
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", largest);
    return 0;
}
