#include <bits/stdc++.h>

using namespace std;

int main(){
    int w, h, u1, d1, u2, d2;
    scanf("%d %d %d %d %d %d", &w, &h, &u1, &d1, &u2, &d2);
    if(d1 < d2) swap(u1, u2), swap(d1, d2);
    for(int i = h; i >= 0; i--){
        w+=i;
        if(i == d1) w-=u1;
        if(i == d2) w-=u2;
        w = max(w, 0);
    }
    printf("%d", w);
    return 0;
}
