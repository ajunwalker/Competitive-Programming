#include <cstdio>

int main(){

    int count = 0;
    int num;
    scanf("%d", &num);

    int lo = 1;
    int hi = 1;
    int sum = 1;

    while ( lo <= num || hi <= num ) {

        if ( sum < num ){
            hi += 1;
            sum += hi;
        }
        else if ( sum > num ) {
            sum -= lo;
            lo += 1;
        }
        else {
            count += 1;
            hi += 1;
            sum += (hi-lo);
            lo += 1;
        }
    }

    printf("%d\n", count);

}
