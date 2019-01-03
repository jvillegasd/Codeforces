#include <bits/stdc++.h>
#define pb push_back

using namespace std;
vector<int> g[200100], kid[200100];
bool vist[200100];

void DFS(int u){
    vist[u] = true;
    printf("%d ", u);
    for(auto v : g[u]) if(!vist[v] && (v == kid[u][0] || v == kid[u][1])) DFS(v);
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &u, &v), g[u].pb(v), g[v].pb(u), kid[i + 1].pb(u), kid[i + 1].pb(v);
    DFS(1);
    return 0;
}
/*
    La estrategia es armar un grafo no dirigido de las aristas dadas (Entender que los vecinos tienen cualquier
    orden, se nota en los ejemplos), guardar los vecinos que recuerda el i-esimo niño y correr un DFS en el grafo.
    El DFS solo va a visitar los nodos adjacentes que se encuentren en los vecinos que recuerda el nodo que se
    esta analizando para asi generar el grafo dirigido.
*/