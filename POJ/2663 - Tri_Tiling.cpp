#include <iostream>
using namespace std;

#define MAX_SIZE 31
int mem[MAX_SIZE];
int mem2[MAX_SIZE];

int f(int n);
int g(int n);

int g(int n){
    if (mem2[n]) return mem2[n];
    mem2[n] = f(n-1) + g(n-2);
    return mem2[n];
}

int f(int n){
    if (mem[n]) return mem[n];
    mem[n] = f(n-2) + 2*g(n-1);
    return mem[n];
}

int main(){

    for(int i = 0; i < MAX_SIZE; ++i) mem[i] = 0;
    mem[0] = 1;
    mem[1] = 0;
    mem2[0] = 0;
    mem2[1] = 1;

    int num;
    cin >> num;

    while(num != -1){

        if (num % 2 != 0) cout << 0 << endl;
        else{
            cout << f(num) << endl;
        }

        cin >> num;
    }

}
