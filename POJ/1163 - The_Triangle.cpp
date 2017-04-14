#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100
int mem[MAX_SIZE];

int main(){
    int mx = 0;
    int num;
    cin >> num;

    for(int i = 0; i < num; ++i){
        int newMem[MAX_SIZE];
        for (int j = 0; j <= i; ++j){

            int next;
            cin >> next;

            if (j == 0){
                newMem[0] = mem[0] + next;
            }
            else if(j == i){
                newMem[i] = mem[i-1] + next;
            }
            else{
                newMem[j] = max(mem[j-1], mem[j]) + next;
            }

            mx = max(mx, newMem[j]);

        }
        for(int j = 0; j <= i; ++j){
            mem[j] = newMem[j];
            //cout << mem[j] << " ";
        }
        //cout << endl;
    }
    cout << mx << endl;
}
