#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, k, d, totalT = 1, totalT2 = 1, c = 0;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    while(true){
        if(totalT % t == 0) c+=k;       
        if(c >= n) break;
        totalT++;
    }
    c = 0;
    while(true){
        if(totalT2 % t == 0) c+=k;
        if(totalT2 > d && (totalT2 - d) % t == 0) c+=k;
        if(c >= n) break;
        totalT2++;
    }
    if(totalT > totalT2) printf("YES");
    else printf("NO");
    return 0;
}