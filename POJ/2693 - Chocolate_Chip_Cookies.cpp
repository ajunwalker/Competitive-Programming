#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;

int main(){

    pair<double,double> points[200];
    int count = 0;
    double p1 = -1;
    double p2 = -1;
    scanf("%lf %lf", &p1, &p2);
    points[count].first = p1;
    points[count++].second = p2;
    scanf("%lf %lf", &p1, &p2);

    while ( (points[count-1].first != p1 || points[count-1].second != p2) && count < 200){
        points[count].first = p1;
        points[count++].second = p2;

        scanf("%lf %lf", &p1, &p2);
    }

    int max = 0;

    // Select first cookie
    for (int i = 0; i < count; ++i){

        // Find another cookie within the diameter
        for (int j = 0; j < count; ++j){

            // Calculate diameter
            double diff_x = points[i].first - points[j].first;
            double diff_y = points[i].second - points[j].second;
            double dist = sqrt( pow(diff_x, 2) + pow(diff_y, 2) );

            // Check if the diameter is within 5cm
            if (dist <= 5.0){

                pair<double,double> centre;
                centre.first = (points[i].first + points[j].first)/2;
                centre.second = (points[i].second + points[j].second)/2;

                // Find all othe cookies within the radius
                int cookies = 0;
                for (int k = 0; k < count; ++k){
                    diff_x = centre.first - points[k].first;
                    diff_y = centre.second - points[k].second;
                    dist = sqrt( pow(diff_x, 2) + pow(diff_y, 2) );

                    // Calculate distance from centre point
                    if (dist <= 2.5) {
                        cookies++;
                    }
                }
                if (cookies > max){
                    max = cookies;
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
