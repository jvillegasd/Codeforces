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
bool vist[5010], vist2[5010];
int cnt;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u){
    vist[u]=1;
    for(auto v : g[u]) if(!vist[v]) DFS(v);
}

void DFS2(int u){
    vist2[u]=1;
    cnt++;
    for(auto v : g[u]) if(!vist2[v] && !vist[v]) DFS2(v);
}

bool cmp(const pii &a, const pii &b){
    return a.fp > b.fp;
}

int main(){
    int n, m, s, u, v, ans=0;
    vector<pii> bad_nodes;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), dEdge(u, v);
    DFS(s);
    for(u = 1; u <= n; u++){
        if(!vist[u]){
            memset(vist2, 0, sizeof(vist2));
            cnt=0;
            DFS2(u);
            bad_nodes.pb({cnt, u});
        }
    }
    sort(bad_nodes.begin(), bad_nodes.end(), cmp);
    for(auto pi : bad_nodes) if(!vist[pi.sp]) ans++, DFS(pi.sp);
    printf("%d", ans);
    return 0;
}
