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
vector<int> g[300100];
bool vist[300100], found[300100];
int sz[300100], x, y;

void DFS(int u){
    vist[u] = true;
    sz[u] = 1;
    if(u == x) found[u] = true;
    else found[u] = false;
    for(auto v : g[u]){
        if(!vist[v]){
            DFS(v);
            sz[u]+=sz[v];
            found[u]|=found[v];
        }
    }
}

int main(){
    int n, u, v, z;
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(y);
    for(auto v : g[y]){
        if(found[v]){
            z = v;
            break;
        }
    }
    printf("%lld", 1LL * n * (n - 1) - 1LL * sz[x] * (sz[y] - sz[z]));
    return 0;
}
/*
    La estrategia es hallar realizar complemento hallando primero los caminos que no son posibles de la sgt
    manera:
    sz[i] denota el tamaño del subarbol cuya raiz es "i", entonces, sz[x] * sz[y] nos da todos los caminos 
    posibles entre cada pareja de cada subarbol. "z" denota un hijo directo de "y" tal que se encuentre en el 
    camino de "y" a "x", por el hecho de que el subarbol "z" tiene caminos posibles debe ser quitados y
    eso es sz[y] - sz[z], dejando asi los nodos que deben pasar primero por "y" para ser visitados.

*/