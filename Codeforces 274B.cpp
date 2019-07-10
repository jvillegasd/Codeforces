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
vector<int> g[100010];
int a[100010];
lli dp[100010][2];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u);
        dp[u][0]=max(dp[u][0], dp[v][0]);
        dp[u][1]=max(dp[u][1], dp[v][1]);
    }
    a[u]+=dp[u][1]-dp[u][0];
    if(a[u] > 0) dp[u][0]+=a[u];
    else dp[u][1]-=a[u];
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    DFS(1, 0);
    printf("%lld", dp[1][0]+dp[1][1]);
    return 0;
}
