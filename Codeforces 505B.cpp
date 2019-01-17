#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<pii> g[110];
set<int> colors[110];
bool vist[110];

bool DFS(int u, int dest, int c){
    vist[u] = true;
    for(auto e : g[u]){
        int v = e.fp, ci = e.sp;
        if(ci == c){
            if(v == dest) return true;
            else if(!vist[v] && DFS(v, dest, c)) return true;
        }
    }
    return false;
}

int main(){
    int n, m, q, u, v, c, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d %d", &u, &v, &c), uwEdge(u, v, c), colors[u].ins(c), colors[v].ins(c);
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &u, &v);
        ans = 0;
        for(auto ci : colors[u]){
            memset(vist, false, sizeof(vist));
            if(DFS(u, v, ci)) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}