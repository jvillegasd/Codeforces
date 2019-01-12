#include <bits/stdc++.h>

using namespace std;

int main(){
    int q, l, r, d;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d %d", &l, &r, &d);
        if(d < l) printf("%d\n", d);
        else printf("%d\n", (r/d + 1) * d);
    }
    return 0;
}