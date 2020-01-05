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
#define MOD 1000000007
 
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];
vector<int> g[200010];
bool vist[200010];
lli w[200010], dp[200010];
lli cycles = 0, best_branch = 0;
 
lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}
 
bool DFS(int u, int p = 0){
    vist[u] = 1;
    bool cycle = 0;
    dp[u] = w[u];
    for(auto v : g[u]){
        if(vist[v] && v != p) cycle = 1;
        else if(!vist[v]){
            cycle = (DFS(v, u))?1:cycle;
            dp[u] = max(dp[u], w[u] + dp[v]);
        }
    }
    if(cycle) cycles+=w[u];
    else best_branch = max(best_branch, dp[u]);
    return cycle;
}
 
int main(){
    memset(vist, 0, sizeof(vist));
    int n, m, u, v, s;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &w[i]), dp[i] = 0;
    for(int i = 1; i <= m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    scanf("%d", &s);
    DFS(s);
    printf("%lld", cycles+best_branch);
    return 0;
}