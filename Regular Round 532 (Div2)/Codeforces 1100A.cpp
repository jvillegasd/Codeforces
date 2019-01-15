#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
vector<int> g[0];

int main(){
    int n, k, arr[110], ans = -1, arrC[110], it, st, c;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int b = 1; b <= n; b++){
        it = st = 0;
        memcpy(arrC, arr, sizeof(arr));
        for(int i = 0; i <= n; i++){
            c = b + i*k;
            if(c >= 1 && c <= n) arrC[c] = 0;
            c = b - i*k;
            if(c >= 1 && c <= n) arrC[c] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(arrC[i] == 1) it++;
            else if(arrC[i] == -1) st++;
        }
        ans = max(ans, abs(it - st));
    }
    printf("%d", ans);
    return 0;
}