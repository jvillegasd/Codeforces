#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long int lli;
lli ans = -1, dp[200100], sum[200100], a[200100], total = 0;
vector<int> g[200100];

void DFS(int u, int p, int lvl){
    dp[1]+=a[u] * lvl;
    sum[u] = a[u];
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u, lvl + 1);
        sum[u]+=sum[v];
    }
}

void DFS(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue; 
        dp[v] = dp[u] + total - 2*sum[v];
        DFS(v, u);
    }
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), total+=a[i];
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), g[u].pb(v), g[v].pb(u);
    DFS(1, 0, 0);
    DFS(1, 0);
    for(int i = 1; i <= n; i++) ans = max<lli>(ans, dp[i]);
    printf("%lld", ans);
    return 0;
}
/*
    Usar DP y DFS para resolver el problema. La solucion consiste en ejecutar 2 veces el DFS tanto para obtener la
    suma de cada subarbol como para llenar el array de DP.
    El primer DFS llenara el array sum[], que contiene para el i-esimo nodo la suma de todos sus descendientes,
    tambien, se guardara en DP[1] la suma de todos los nodos hacia la raiz.
    El segundo DFS llenara el array dp[] de la sgt forma:
        Para cada nodo u, dp[u] representa el peso si "u" fuera la raiz, entonces, para cada hijo "v" de "u" viene
        dado asi: dp[v] = dp[u] - sum[v] + total - sum[v] = dp[u] + total - 2 * sum[v]
            dp[u] - sum[v] -> Porque a medida de que la ubicacion de la raiz avanza un nivel, se debe restar 1 
                              unidad de distancia.
            total - sum[v] -> Porque se obtiene la suma de los nodos que no estan en el subarbol de "v", ademas,
                              a medida de que se avanza un nivel, se debe sumar 1 unidad de distancia.
*/