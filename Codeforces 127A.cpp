#include <bits/stdc++.h>

using namespace std;

int main(){
    float x, y, total = 0, xo, yo;
    int n, k;
    scanf("%d %d %f %f", &n, &k, &xo, &yo);
    while(--n){
        scanf("%f %f", &x, &y);
        total+=sqrt((y - yo) * (y - yo) + (x - xo) * (x - xo));
        xo = x;
        yo = y;
    }
    printf("%.6f", total * k/50);
    return 0;
}