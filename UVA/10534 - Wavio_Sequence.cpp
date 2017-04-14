#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int search(vector<int> &sequence, int left, int right, int val){
    while (right > left + 1) {
        int midpoint = (left+right)/2;
        if (sequence[midpoint] >= val) right = midpoint;
        else left = midpoint;
    }
    return right;
}

void LIS(vector<int> &sequence, vector<int> &result) {

    int length = 1;
    vector<int> mem(sequence.size(), 0);
    mem[0] = sequence[0];
    result[0] = 1;

    for (int i = 1; i < sequence.size(); i++) {

        if (sequence[i] < mem[0]) mem[0] = sequence[i];
        else if (sequence[i] > mem[length-1]) mem[length++] = sequence[i];
        else mem[search(mem, -1, length-1, sequence[i])] = sequence[i];

        result[i] = length;
    }
}

int main(){
    int size;
    while(cin >> size) {
        vector<int> increasing(size);
        vector<int> decreasing(size);

        for(int i = 0; i < size; ++i){
            cin >> increasing[i];
            decreasing[size-i-1] = increasing[i];
        }

        vector<int> leftRes(size, 0);
        vector<int> rightRes(size, 0);

        LIS(increasing, leftRes);
        LIS(decreasing, rightRes);

        reverse(rightRes.begin(), rightRes.end());

        int wavio = 1;
        for (int i = 0; i < size; ++i) {
            wavio = max(wavio, min(leftRes[i], rightRes[i]));
        }
        cout << wavio*2-1 << endl;

    }
}
