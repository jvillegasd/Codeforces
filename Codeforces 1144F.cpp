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
vector<int> g[200010];
vector<pii> e;
int color[200010], vist[200010], bip = 1;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void DFS(int u, int c){
    color[u] = c;
    vist[u] = 1;
    for(auto v : g[u]){
        if(!vist[v]) DFS(v, c ^ 1);
        else if(color[u] == color[v]) bip = 0;
    }
}

int main(){
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v), e.pb({u, v});
    DFS(1, 0);
    if(bip){
        printf("YES\n");
        for(auto ei : e) printf("%d", color[ei.fp] < color[ei.sp]);
    }else printf("NO");
    return 0;
}