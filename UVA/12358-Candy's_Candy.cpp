#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long findVariations(long arr[], long variety, long min, long count, long pack_size){

    // Find how many packs minimum we need
    long remainder = (min - variety) % pack_size;
    long divisible = min - variety - remainder;

    for (int i = 0; i < count; ++i){
        if ((arr[i] - variety - remainder) % pack_size != 0){
            return 0;
        }
    }
    return divisible/pack_size;
}

int main(){

    long count;
    scanf("%ld", &count);

    while(count != 0){

        // Parse all the candies into an array
        long divisor = 0;
        long min = -1;
        long arr[count];
        for (long i = 0; i < count; ++i) {
            cin >> arr[i];
            divisor = gcd(divisor, arr[i]);
            if (min == -1 || arr[i] < min) min = arr[i];
        }

        // Total number of varieties to be returned
        long total_variety = 0;

        // Select how many candies in the variety pack
        for (long i = 1; i*i < divisor+1; ++i){

            // Make sure the candies are divisible by the variety pack size
            if ( divisor % i  == 0 ){
                long pack_size = i*count;
                total_variety += findVariations(arr, i, min, count, pack_size);
                if (i*i == divisor) continue;
                total_variety += findVariations(arr, i, min, count, count * divisor / i);
            }
        }

        printf("%ld\n", total_variety);
        scanf("%ld", &count);
    }

    return 0;
}
