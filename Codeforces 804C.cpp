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
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[300100], ic[300100], allowed;
int colors[500100], ci;
bool vist[300100], check[500100];

void DFS(int u){
    vist[u] = true;
    for(auto i : ic[u]){
        if(colors[i]) check[colors[i]] = true;
        else allowed.pb(i);
    }
    ci = 1;
    for(auto i : allowed){
        while(check[ci]) ci++;
        colors[i] = ci++;
    }
    for(auto i : ic[u]) check[colors[i]] = false;
    allowed.clear();
    for(auto v : g[u]) if(!vist[v]) DFS(v);
}

int main(){
    int n, m, sz, si, u, v, maxi = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &sz);
        while(sz--) scanf("%d", &si), ic[i].pb(si);
    }
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(1);
    for(int i = 1; i <= m; i++){
        maxi = max(maxi, colors[i]);
        if(!colors[i]) colors[i] = 1;
    }
    maxi = max(maxi, 1);
    printf("%d\n", maxi);
    for(int i = 1; i <= m; i++) printf("%d ", colors[i]);
    return 0;
}
/*
    El problema fue algo dificil de entender y me costo pero basicamente pide el minimo de colores necesarios
    tal que los nodo-helados no adjacentes sean del mismo color.
    Definamos nodo-helado como los nodos del grafo G y tambien definamos nodo-arbol como los nodos del arbol T.
    Solucion:
    Ir recorriendo cada nodo-arbol y guardar los nodo-helados de su set que no tengan color definido, luego,
    de manera Greedy ir asignando colores a estos nodos-helados, empezando desde el color "1" para asi cumplir
    la condicion de minimo de colores (no contar mucho). Finalizando, solo encontrar el numero de color mas grande
    que tambien denotara el minimo de colores usados y tener en cuenta de que si un nodo-hielo no fue pintado,
    entoces se pintara de "1".
    Notas:
    -) Los sets que tienen cada nodo-arbol son subgrafos de G
    -) Se busca colorear G y no T
    -) G es disconexo con subgrafos clique
    -) El problema basicamente busca el maximo clique de G
*/