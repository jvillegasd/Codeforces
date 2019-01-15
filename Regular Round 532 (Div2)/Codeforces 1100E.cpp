#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
struct edge{
    int v, w, i;
};
vector<edge> g[100100];
vector<int> ans;
int vist[100100], n, atime[100100];
stack<int> s;

void topSort(int u, int mid){
    vist[u] = true;
    for(auto e : g[u]){
        int v = e.v, c = e.w;
        if(!vist[v] && c > mid) topSort(v, mid);
    }
    s.push(u);
}

bool DFS(int u, int mid){
    vist[u] = 1;
    for(auto e : g[u]){
        int v = e.v, c = e.w;
        if(c <= mid) continue;
        if(vist[v] == 1 || (!vist[v] && !DFS(v, mid))) return false;
    }
    vist[u] = 2;
    return true;
}

bool verify(int mid){
    memset(vist, 0, sizeof(vist));
    for(int i = 1; i <= n; i++) if(!vist[i] && !DFS(i, mid)) return false;
    return true;
}

int main(){
    int m, u, v, w, l = 0, r = -1, mid, mint, t = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d %d %d", &u, &v, &w), g[u].pb({v, w, i}), r = max(r, w);
    while(l <= r){
        mid = (l + r)/2;
        if(verify(mid)) mint = mid, r = mid - 1;
        else l = mid + 1;
    }
    memset(vist, 0, sizeof(vist));
    for(int i = 1; i <= n; i++) topSort(i, mint);
    while(!s.empty()){
        u = s.top();
        atime[u] = ++t;
        s.pop();
    }
    for(u = 1; u <= n; u++){
        for(auto e : g[u]){
            v = e.v;
            w = e.w;
            if(w <= mint && atime[u] > atime[v]) ans.pb(e.i);
        }
    }
    printf("%d %d\n", mint, ans.size());
    for(auto a : ans) printf("%d ", a);
    return 0;
}
/*
    Consideraciones:
    *) Denotemos como g' al subgrafo que solo posee arista cuyo peso w > mint.
    *) Se puede usar Binary Search para encontrar un minimo k tal que cumpla una condicion T y que exista alguna
        k' que tambien la cumpla, siendo k' > k.
    *) Para un digraph, con algunas aristas sin direccion, para poder darles direccion de tal manera de que digraph
        se convierta en DAG, se realiza primero un topological sort con las arista que tengan direccion, luego,
        para cada arista (u, v) que no las tenga, se le asignara la direccion dependiendo que nodo sale primero,
        es decir, la arista solo ira de "u" a "v" si "u" sale primero en el topSort que "v" y viceversa.
    Solucion:
    Se ocupa usar Binary Search para poder hallar el numero minimo de empleados (mint), para ir comprobando de
    que se va hallando el mint deseado se usa un DFS que va comprobando si con la mint hallada se siguen creando
    ciclos o no. Luego, al hallat mint, se realiza un topological sort a g', luego, guardar las aristas que se
    necesiten reasignar de direccion.
*/