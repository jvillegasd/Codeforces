#include <bits/stdc++.h>
#define pb push_back
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
vector<int> g[0];
int pa[100100];

struct edge{
    int u, v, w;
};

int find(int u){
    if(pa[u] == u) return u;
    return pa[u] = find(pa[u]);
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int main(){
    int u, v, w, n, m, k, ur, vr; 
    lli cnt[100100]={0};
    vector<edge> graph;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) pa[i] = i;
    for(int i = 0; i < k; i++) scanf("%d", &u), cnt[u] = 1;
    for(int i = 0; i < m; i++) scanf("%d %d %d", &u, &v, &w), graph.pb({u, v, w});
    sort(graph.begin(), graph.end(), cmp);
    for(auto e : graph){
        ur = find(e.u), vr = find(e.v);
        if(ur == vr) continue;
        pa[vr] = ur;
        cnt[ur]+=cnt[vr];
        if(cnt[ur] >= k){
            for(int i = 0; i < k; i++) printf("%d ", e.w);
            return 0;
        }
    }
    return 0;
}
/*
    La estrategia es obtener el MST del grafo para siempre el minimo costo de un camino ya que como siempre
    depende de la arista mas grande y con el MST minimizamos el tamaño de las aristas a tener en cuenta.
    A medida de que el MST se va formando, contar el numero de vertices especiales tiene los diferentes
    conjuntos disyuntos, cosa que al hallar una arista cuya union de conjuntos resulte en obtener un nuevo
    conjunto con todos los vertices especial el peso de esa arista sera la respuesta.
*/