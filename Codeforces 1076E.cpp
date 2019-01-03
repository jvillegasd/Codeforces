#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[300100];
vector<pii> query[300100];
lli tree[1048576], ans[300100];

void updateTree(int node, int l, int r, int xi, int i, int j){
    if(i <= l && r <= j){
        tree[node]+=xi;
        return;
    }
    int mid = (l + r)/2;
    if(i <= mid) updateTree(2*node, l, mid, xi, i, j);
    if(mid < j) updateTree(2*node + 1, mid + 1, r, xi , i, j);
}

lli getSum(int node, int l, int r, int h, lli sum){
    if(l == r) return sum + tree[node];
    int mid = (l + r)/2;
    if(h <= mid) return getSum(2*node, l, mid, h, sum + tree[node]);
    else return getSum(2*node + 1, mid + 1, r, h, sum + tree[node]);
}

void DFS(int u, int ant, int h){
    for(auto q : query[u]){
        int di = q.first, xi = q.second;
        updateTree(1, 0, 524287, xi, h, h + di);
    }
    ans[u] = getSum(1, 0, 524287, h, 0);
    for(auto v : g[u]) if(v != ant) DFS(v, u, h + 1);
    for(auto q : query[u]){
        int di = q.first, xi = q.second;
        updateTree(1, 0, 524287, -xi, h, h + di);
    }
}

int main(){
    int n, m, x, y;
    lli vi, di, xi;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &x, &y), g[x].pb(y), g[y].pb(x);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%lld %lld %lld", &vi, &di, &xi), query[vi].pb({di, xi});
    DFS(1, 0, 0);
    for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}
/*
    La estrategia es usar DFS + Segment Tree debido a las numerosas queries que pide el problema. Para cada nodo y
    sus descendientes, crear el Segment Tree con intervalos de [h, h + di] dependiendo de la distancia "di" de
    la query, luego, deshacer cambios para los demas nodos con sus respectivos descendientes. Con este problema
    aprendi sobre Segment Tree y me di cuenta que dependiendo del problema se necesita una forma de crearlo, asi como
    los respectivos metodos para realizar las queries y updates. En este problema, el Segment Tree guarda la info
    de las queries que se hacen a cada nodo del Sub Tree a analizar, es por eso que el metodo update solo suma
    una vez "xi" y no a cada numero del intervalo, porque se va analizando de nodo a nodo. 
*/