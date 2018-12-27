#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h, a, ans = 0;
    vector<int> fh;
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++) scanf("%d", &a), fh.push_back(a);
    for(int i = 0; i < n; i++){
        if(fh[i] <= h) ans+=1;
        else ans+=2;
    }
    printf("%d", ans);
    return 0;
}