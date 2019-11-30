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
map<int, int> newN;
map<int, pii> edges;
bool vist[200010], exist;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, int &last){
    vist[u] = 1;
    last = u;
    for(auto v : g[u]){
        if(vist[v]) continue;
        DFS(v, last);
    }
}

void DFS(int u, int last, int &leaf){
    vist[u] = 1;
    leaf = u;
    if(last == u) exist = 1;
    for(auto v : g[u]){
        if(vist[v]) continue;
        DFS(v, last, leaf);
    }
}

void cleanAll(int n){
    newN.clear();
    edges.clear();
    memset(vist, 0, sizeof(vist));
    for(int j = 1; j <= 200010; j++) g[j].clear();
}

int main(){
    int tc, n, x, y;
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++){
        scanf("%d", &n);
        cleanAll(n);
        int cnt = 0, last = 0, leaf = 0;
        vector<pii> ans;
        for(int j = 1; j <= n; j++){
            scanf("%d %d", &x, &y);
            if(newN.find(x) == newN.end()) newN[x] = ++cnt, edges[cnt] = {x, j};
            if(newN.find(y) == newN.end()) newN[y] = ++cnt, edges[cnt] = {y, j};
            uEdge(newN[x], newN[y]);
        }
        DFS(1, last);
        for(int u = 2; u <= cnt; u++){
            if(!vist[u]){
                exist = 0;
                DFS(u, last, leaf);
                if(!exist){
                    ans.pb({leaf, last});
                }
            }
        }
        printf("%d\n", ans.size());
        if(ans.size()){
            for(auto pi : ans) printf("%d %d %d\n", edges[pi.fp].sp, edges[pi.fp].fp, edges[pi.sp].fp);
        }
    }
    return 0;
}
