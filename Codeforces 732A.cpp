#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, r, ans = 1;
    scanf("%d %d", &k, &r);
    while(true){
        if(ans * k % 10 == 0 || ans * k % 10 == r) break;
        ans++;
    }
    printf("%d", ans);
    return 0;
}