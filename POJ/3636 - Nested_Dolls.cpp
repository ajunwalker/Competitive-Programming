#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 20001

struct doll{
    int width, height;
} dolls[MAX];

int cmp(doll a, doll b){
    if (a.width != b.width) return a.width < b.width;
    else return a.height > b.height;
}

int main(){
    int c, m;
    scanf("%d", &c);

    for(int i = 0; i < c; ++i){

        scanf("%d", &m);
        for(int j = 0; j < m; ++j){
            scanf("%d %d", &dolls[j].width, &dolls[j].height);
        }

        sort(dolls, dolls+m, cmp);
        int arr[MAX];
        for(int j = 0; j < MAX; ++j) arr[j] = 0;

        int total = 1;
        for(int j = 0; j < m; ++j){

            int left = 0, right = total;
            while(left < right){
                int m = (left+right)/2;
                if (arr[m] < dolls[j].height){
                    right = m;
                }
                else left = m+1;
            }

            if (left == total) total++;
            arr[left] = dolls[j].height;
        }
        printf("%d\n", total);
    }
}
