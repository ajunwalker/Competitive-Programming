#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {

    int sequence_length;
    int sequence_count;
    string sequences[100];
    int sequence_scores[100];

    scanf("%d %d", &sequence_length, &sequence_count);

    for (int i = 0; i < sequence_count; ++i){

        string str;
        cin >> str;
        sequences[i] = str;

        int inv = 0;
        for (int j = 0; j < sequence_length-1; ++j){
            for (int k = j+1; k < sequence_length; ++k){
                if (str[j] > str[k]) {
                    inv += 1;
                }
            }
        }

        sequence_scores[i] = inv;

    }

    int lowest;
    int index;
    for (int i = 0; i < sequence_count; ++i){

        lowest = 99999;

        for (int j = 0; j < sequence_count; ++j){
            if (sequence_scores[j] < lowest) {
                lowest = sequence_scores[j];
                index = j;
            }
        }

        sequence_scores[index] = 99999;
        printf("%s\n", sequences[index].c_str());
    }

}
