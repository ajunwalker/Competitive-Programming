#include <cstdio>
#include <cmath>

int main(){

    const double PI = atan(1)*4;

    int scenarios;
    scanf("%d", &scenarios);

    for (int i = 0; i < scenarios; ++i){
        double R, n;
        scanf("%lf %lf", &R, &n);

        double radius =  sin(PI/n)*R / (1.0+sin(PI/n));
        printf("Scenario #%d:\n%.3f\n\n", i+1, radius);
    }
    return 0;
}
