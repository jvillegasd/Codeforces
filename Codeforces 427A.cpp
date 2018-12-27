#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, ans = 0, pol = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a > 0) pol+=a;
        if(a == -1 && pol > 0) pol--;
        else if(a == -1 && pol == 0) ans++;
    }
    printf("%d", ans);
    return 0;
}