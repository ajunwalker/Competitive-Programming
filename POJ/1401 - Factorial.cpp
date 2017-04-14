#include <cstdio>
#include <cmath>

int main(){

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i){
        int val;
        scanf("%d", &val);

        int count = 0;

        for (int j = 1; pow(5,j) <= val; j += 1) {
            count += val/pow(5,j);
        }

        printf("%d\n", count);

    }

    return 0;
}
