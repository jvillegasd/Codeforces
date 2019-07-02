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
vector<int> g[50010];
int k;
lli cnt = 0, dp[50010][510];

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
    dp[u][0] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u);
        for(int i = 1; i <= k; i++) cnt+=dp[v][i-1]*dp[u][k-i];
        for(int i = 1; i <= k; i++) dp[u][i]+=dp[v][i-1];
    }
}

int main(){
    int n, u, v;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(1, 0);
    printf("%lld", cnt);
    return 0;
}
