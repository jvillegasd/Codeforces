#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long int lli;
typedef pair<lli, int> pli;

struct edge{
    int y, w, index;
};

vector<edge> g[400000];

void dijkstra(int n, int k){
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    vector<int> ans;
    bool vist[400000];
    lli dist[400000], idx[400000], cont = 0;
    for(int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    memset(vist, false, sizeof(vist));
    memset(idx, -1, sizeof(idx));
    dist[1] = 0;
    pq.push({dist[1], 1});
    while(!pq.empty() && cont < k){
        auto pa = pq.top();
        int u = pa.second;
        pq.pop();
        if(vist[u]) continue;
        vist[u] = true;
        if(idx[u] != -1) cont++, ans.pb(idx[u]); //Guarda el indice de la ultima arista procesada
        for(auto v : g[u]){
            if(dist[v.y] > dist[u] + v.w){
                dist[v.y] = dist[u] + v.w;
                idx[v.y] = v.index;
                pq.push({dist[v.y], v.y});
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto u : ans) printf("%d ", u + 1);
}

int main(){
    int n, m, k, x, y, w;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) scanf("%d %d %d", &x, &y, &w), g[x].pb({y, w, i}), g[y].pb({x, w, i});
    dijkstra(n, k);
    return 0;
}
/*
    La estrategia es obtener siempre "k" aristas, es decir, revisaremos "k + 1" nodos mientras hallamos los caminos
    cortos. Teniendo lo anterior en cuenta, el problema se resume a hallar los caminos cortos desde el nodo "1" hasta
    que se cuenten exactamente "k + 1" nodos.
*/