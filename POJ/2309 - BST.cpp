#include <cstdio>
#include <cmath>

int main(){

    unsigned long top = 4294967296 / 2;
    int depth = 30;

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i){

        unsigned long val;
        scanf("%ld", &val);

        unsigned long search = top;
        unsigned long search_depth = depth;

        while (search != val){
            if (search < val){
                search += pow(2, search_depth);
            }
            else {
                search -= pow(2, search_depth);
            }
            search_depth -= 1;
        }

        int left_depth = search_depth;
        long left_val = search;
        int right_depth = search_depth;
        long right_val = search;
        while(left_depth >= 0){
            left_val -= pow(2, left_depth);
            left_depth -= 1;
        }

        while(right_depth >= -1){
            right_val += pow(2, right_depth);
            right_depth -= 1;
        }

        printf("%ld %ld\n", left_val, right_val);

    }

    return 0;
}
