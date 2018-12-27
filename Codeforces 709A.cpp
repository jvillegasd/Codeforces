#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, d, oi, sum = 0, ans = 0;
    vector<int> org;
    scanf("%d %d %d", &n, &b, &d);
    for(int i = 0; i < n; i++) scanf("%d", &oi), org.push_back(oi);
    for(int i = 0; i < n; i++){
        if(org[i] > b) continue;
        sum+=org[i];
        if(sum > d) ans++, sum = 0;
    }
    printf("%d", ans);
    return 0;
}