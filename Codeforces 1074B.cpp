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
vector<int> g[1100];
int x[1100], y[1100], k1, k2, xi;

void DFS(int u, int p){
    for(int i = 0; i < k1; i++){
        if(x[i] == u){
            xi = x[i];
            return;
        }
    }
    for(auto v : g[u]) if(v != p) DFS(v, u);
}

int main(){
    int n, u, v, tc, r, q, flag;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
        scanf("%d", &k1);
        for(int i = 0; i < k1; i++) scanf("%d", &x[i]);
        scanf("%d", &k2);
        for(int i = 0; i < k2; i++) scanf("%d", &y[i]);
        printf("B %d\n", y[0]);
        fflush(stdout);
        scanf("%d", &r);
        xi = 0;
        DFS(r, 0);
        printf("A %d\n", xi);
        fflush(stdout);
        scanf("%d", &q);
        flag = 0;
        for(int i = 0; i < k2; i++){
            if(q == y[i]){
                flag = 1;
                break;
            }
        }
        if(flag) printf("C %d\n", xi);
        else printf("C -1\n");
        fflush(stdout);
    }
    return 0;
}
/*
    Primer problema interactivo y tal vez el ultimo, muy complicado entender
    la input y output. Esta solucion funciona debido a que los jugadores pueden
    pintar los nodos que quieran, es decir, existen permutaciones.
    Los pasos son los siguientes:
      1) Imprimir "B y0" a la respuesta "r"
      2) Buscar el label "xi" mas cercano a "r"
      3) Imprimir "A xi" a la respuesta "q"
      4) Si "q" esta en el subarbol y imprimir "C xi", sino, "C -1"
    Al realizar el paso 1 se pinta el subarbol Y desde el nodo semejante "r".
    Al realizar el paso 3 se busca establecer si "xi" esta en el subarbol Y 
    buscando a "xi".
    Si en el paso 4 se imprime "C xi" significa que existe un camino entre
    "r" y "q" tal que pertenece al subarbol Y.
    Mas info: https://codeforces.com/blog/entry/62985
*/