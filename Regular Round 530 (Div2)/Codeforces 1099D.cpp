#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long int lli;
vector<int> g[100100];
int val[100100];
lli sum[100100];

void DFS(int u, int p){
    if(sum[u] == -1){
        int mini = INT_MAX;
        for(auto v : g[u]) mini = min<lli>(mini, sum[v]);
        if(mini == INT_MAX) val[u] = 0;
        else{
            if(mini < sum[p]){
                printf("-1");
                exit(0);
            }
            val[u] = mini - sum[p];
        }
        sum[u] = val[u] + sum[p];
    }else{
        if(sum[u] < sum[p]){
            printf("-1");
            exit(0);
        }
        val[u] = sum[u] - sum[p]; 
    }
    for(auto v : g[u]) DFS(v, u);
}

int main(){
    int n, pi;
    lli ans = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &pi), g[pi].pb(i);
    for(int i = 1; i <= n; i++) scanf("%lld", &sum[i]);
    val[1] = sum[1];
    DFS(1, 0);
    for(int i = 1; i <= n; i++) ans+=val[i];
    printf("%lld", ans);
    return 0;
}