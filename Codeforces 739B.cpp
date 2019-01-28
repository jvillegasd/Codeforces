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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<pii> g[200100];
vector<int> path;
int a[200100], parent[200100];
lli ans[200100], d[200100];

void DFS(int u, int p){
    path.pb(u);
    int l = 0, r = path.size() - 1, mid = 0, i = 0;
    while(l <= r){
        mid = (l + r)/2;
        if(d[u] - d[path[mid]] <= a[u]) i = mid, r = mid - 1;
        else l = mid + 1;
    }
    ans[parent[u]]++;
    ans[parent[path[i]]]--;
    for(auto pa : g[u]){
        int v = pa.fp, w = pa.sp;
        if(v == p) continue;
        d[v] = d[u] + w;
        DFS(v, u);
    }
    path.pob();
}

void prefixSum(int u, int p){
    for(auto pa : g[u]){
        int v = pa.fp;
        if(v == p) continue;
        prefixSum(v, u);
        ans[u]+=ans[v];
    }
}

int main(){
    int n, u, w;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int v = 2; v <= n; v++) scanf("%d %d", &u, &w), uwEdge(u, v, w), parent[v] = u;
    DFS(1, 0);
    prefixSum(1, 0);
    for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}
/*
    La estrategia es buscar el nodo "i" mas lejano de "u" tal que cumpla la condicion dada, luego, como todos los
    nodos que esten entre "u" e "i" tambien cumplen la condicion dada, entonces se debe sumar "+1" a todos
    esos nodos para indicar de que ellos pueden controlar a "u". Para buscar al nodo lejano "i" se usa busqueda
    binaria ya que como la distancia va creciendo a la par del nivel del arbol entonces hay un orden creciente y
    para indicar cuantos nodos controlan se aplica una tecnica de suma de intervalos en un array que se explica
    aqui: https://www.geeksforgeeks.org/constant-time-range-add-operation-array/. Teniendo en cuenta el metodo
    de suma de intervalo, en este caso el intervalo es:  i <= x <= parent[u] (donde x es un nodo entre path(i, v))
    ya que parent[u] es el nodo mas cercano que controla a "u" e "i" porque parent[i] no controla a "u".
*/