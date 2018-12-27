#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main(){
    int n, h, g, ans = 0, hi, gj;
    vector<pii> t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &h, &g), t.push_back(make_pair(h, g));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            hi = t[i].first;
            gj = t[j].second;
            if(hi == gj) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}