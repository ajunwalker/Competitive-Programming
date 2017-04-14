#include <iostream>
using namespace std;

int height[30001]; // Height of the stacks
int above[30001]; // Distance to the top of the stack
int parent[30001];

 void init(){
     for (int i = 1; i <= 30001; i++){
         height[i] = 1;
         above[i] = 0;
         parent[i] = i;
     }
 }

// Find and compress path to top of stack
 int findParent(int x){
     if(x == parent[x]) return x;
     int par = findParent(parent[x]);
     above[x] += above[parent[x]];
     parent[x] = par;
     return par;
 }

// Hang b from a and adjust numbers
void makeUnion(int a, int b){
     int parentFrom = findParent(a);
     int parentTo = findParent(b);
     parent[parentFrom] = parentTo;
     above[parentFrom] =  height[parentTo];
     height[parentTo] += height[parentFrom];
 }

int main(){

    init();
    int count;
    cin >> count;

    for (int i = 0; i < count; ++i){

        char command;
        cin >> command;

        if (command == 'M'){

            int from, to;
            cin >> from >> to;
            makeUnion(from, to);

        }

        else {

            int block;
            cin >> block;
            int parent = findParent(block);
            int below = height[parent] - above[block] - 1;
            cout << above[block] << endl;

        }

    }

}
