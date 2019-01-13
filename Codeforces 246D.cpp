#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
vector<int> g[100100];
set<int> q[1001000];
bool vist[100100];
int c[100100];

void DFS(int u){
    vist[u] = true;
    for(auto v : g[u]){
        if(c[u] != c[v]) q[c[u]].insert(c[v]);
        if(!vist[v]) DFS(v);
    }
}

int main(){
    int n, m, u, v;
    lli maxc = -1, minc = INT_MAX;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n ; i++) scanf("%d", &c[i]);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), addEdge(u, v);
    for(int i = 1; i <= n; i++){
        if(!vist[i]) DFS(i);
        maxc = max<lli>(maxc, q[c[i]].size());
    }
    for(int i = 1; i <= n; i++){
        if(q[c[i]].size() == maxc) minc = min<lli>(minc, c[i]);
    }
    printf("%lld", minc);
    return 0;
}
/*
    La estrategia es ir contado para cada color existente el numero de vecinos con diferentes colores, luego, si
    existen varios colores con una misma cantidad de vecinos, imprimir el menor.
    Nota: Me tocó usar un set debido a que se deben contar colores unicos, es decir si un nodo con un color "k",
    posee 3 vecinos con un color "k + 1", solo se debe contar una sola vez y no 3 veces, este error me ocurrió por
    falta de compresión lectora en ingles. 
*/