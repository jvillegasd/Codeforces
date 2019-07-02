#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<pii> g[200010];
int dp[200010], bad_edges = 0;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

int binsearch(int n, lli arr[], lli sum){
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==sum) return mid;
        if(arr[mid]<sum) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

void DFS(int u, int p){
    for(auto v : g[u]){
        if(v.fp == p) continue;
        dp[v.fp]+=dp[u]+v.sp;
        if(v.sp == -1) bad_edges++;
        DFS(v.fp, u);
    }
}

int main(){
    int n, u, v, mini = INT_MAX;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), g[u].pb({v, 1}), g[v].pb({u, -1});
    DFS(1, 0);
    for(u = 1; u <= n; u++) mini = min(mini, dp[u]);
    printf("%d\n", bad_edges+mini);
    for(u = 1; u <= n; u++) if(dp[u] == mini) printf("%d ", u);
    return 0;
}
