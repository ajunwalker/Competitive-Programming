#include <cstdio>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; ++i){

        printf("Scenario #%d:\n", i+1);

        int petrol;
        scanf("%d", &petrol);

        for (int a = 0; a < petrol*2+1; ++a){

            printf("slice #%d:\n", a+1);

            for (int b = 0; b < petrol*2+1; ++b){
                for(int c = 0; c < petrol*2+1; ++c){
                    // Calculate manhattan distance from origin to current point
                    if (abs(petrol-a)+abs(petrol-b)+abs(petrol-c) <= petrol) {
                        printf("%d", abs(petrol-a)+abs(petrol-b)+abs(petrol-c));
                    }
                    else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }

}
