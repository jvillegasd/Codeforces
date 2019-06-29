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
vector<int> g[100010], tree[100010];
int block[100010], path[100010], parent[100010][18], tin[100010], tout[100010], dp[100010];
int cnt = 1, cntt = 0, lg2n = 18;
bool cb[100010], vist[100010];

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
    vist[u] = 1;
    path[u] = p;
    for(auto v : g[u]){
        if(v == p) continue;
        if(vist[v] && block[u] == -1){
            int nav = path[u];
            while(nav != v) block[nav] = cnt, nav = path[nav];
            block[u] = block[nav] = cnt;
            cb[cnt++] = 1;
        }
        else if(!vist[v]) DFS(v, u);
    }
    if(block[u] == -1) block[u] = cnt++;
}

void DFS2(int u, int p){
    dp[u] = cb[u] + dp[p];
    tin[u] = cntt++;
    parent[u][0] = p;
    for(int i = 1; i < lg2n; ++i) parent[u][i] = parent[parent[u][i-1]][i-1];
    for(auto v : tree[u]){
        if(v == p) continue;
        DFS2(v, u);
    }
    tout[u] = cntt++;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i = lg2n - 1; i >= 0; --i) if(!is_anc(parent[u][i], v)) u = parent[u][i];
    return parent[u][0];
}

int main(){
    int n, m, u, v, k, root, po[100010];
    po[0] = 1;
    for(int i = 1; i < 100010; i++) po[i] = (po[i-1]*2)%MOD;
    vector<pii> queries;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d %d", &u, &v), queries.pb({u, v});
    memset(block, -1, sizeof(block));
    DFS(1, 0);
    for(u = 1; u <= n; u++){
        for(auto v : g[u]) if(block[u] != block[v]) tree[block[u]].pb(block[v]);
    }
    DFS2(1, 1);
    for(auto qi : queries){
        u = block[qi.fp], v = block[qi.sp];
        root = lca(u, v);
        printf("%d\n", po[dp[u]+dp[v]-2*dp[root]+cb[root]]);
    }
    return 0;
}
