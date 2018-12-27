#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ai, ans = 0;
    vector<int> stw;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), stw.push_back(ai);
    sort(stw.begin(), stw.end());
    for(int i = 1; i < n - 1; i++) if(stw[i] > stw[0] && stw[i] < stw[n - 1]) ans++;
    printf("%d", ans);
    return 0;
}