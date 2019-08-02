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
lli sz[200010], dp[200010], ans=0;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS1(int u, int p){
    sz[u]=1;
    for(auto v : g[u]){
        if(v == p) continue;
        DFS1(v, u);
        sz[u]+=sz[v];
    }
}

void DFS2(int u, int p){
    dp[u]=sz[u];
    for(auto v : g[u]){
        if(v == p) continue;
        DFS2(v, u);
        dp[u]+=dp[v];
    }
}

void DFS3(int u, int p){
    ans=max(ans, dp[u]);
    for(auto v : g[u]){
        if(v == p) continue;
        dp[u]-=dp[v];
        dp[u]-=sz[v];
        sz[u]-=sz[v];
        sz[v]+=sz[u];
        dp[v]+=dp[u];
        dp[v]+=sz[u];
        DFS3(v, u);
        dp[v]-=dp[u];
        dp[v]-=sz[u];
        sz[v]-=sz[u];
        sz[u]+=sz[v];
        dp[u]+=dp[v];
        dp[u]+=sz[v];
    }
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS1(1, 0);
    DFS2(1, 0);
    DFS3(1, 0);
    printf("%lld", ans);
    return 0;
}
