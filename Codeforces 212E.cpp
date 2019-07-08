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
vector<int> g[5010];
int dp[5010][5010], n, sz[5010], ans[5010];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, int p){ //C(u) = children of node "u"
    dp[u][0]=1; //Consider only subtree "v"
    sz[u]=1;
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u);
        sz[u]+=sz[v];
        for(int i = n-1; i >=0; i--) if(dp[u][i]) dp[u][i+sz[v]]=1; //Set all possible subgraphs from C(u)
    }
    int fnodes = n-sz[u]; //left nodes
    for(int i = n-1; i >=0; i--) if(dp[u][i]) dp[u][i+fnodes]=1; //Set all possible subgraphs by combining fnodes with C(u)
    for(int i = 1; i < n-1; i++) if(dp[u][i]) ans[i]=1;
}

int main(){
    int u, v, cnt=0;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(1, 0);
    for(int i = 1; i < n-1; i++) if(ans[i]) cnt++;
    printf("%d\n", cnt);
    for(int i = 1; i < n-1; i++) if(ans[i]) printf("%d %d\n", i, n-1-i); //From precalculated subgraphs, get complement
    return 0;
}
