#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
int n;
lli ans = 0, odd = 0, even = 0, sum[200100];
vector<int> g[200100];

void DFS(int u, int p, int lvl){
    if(lvl % 2) odd++;
    else even++;
    sum[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u, lvl + 1);
        sum[u]+=sum[v];
    }
    ans+=sum[u]*(n - sum[u]);
}

int main(){
    int u, v;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), addEdge(u, v);
    DFS(1, 0, 0);
    printf("%lld", (ans + odd * even)/2);
    return 0;
}
/*
    Antes de empezar con la solucion, hay que tener en cuenta un concepto sobre los caminos en grafos.
    En los grafos, la suma de todos los caminos entre cualquier par de nodos es N! teniendo en cuenta de
    que las aristas pesan 1. Para explicar esto en arboles supongamos que tengamos 2 subarboles ST1 y ST2
    que estan conectados por una arista, entonces, las veces en que se usa esta arista para los caminos 
    que existen entre cada par de nodos de ST1 y ST2 es: ST1.size * ST2.size. Generalizando esta informacion 
    podemos obtener la suma de todos los caminos entre cualquier par de nodos de un arbol sumando 
    ST.size * (N - ST.size) para cada subarbol, asi, se van sumando las veces que cada arista es usada para
    los caminos que hay entre los nodos de ST con los demas.

    Empezemos con la solucion:
    Definamos: P(u, v) como la distancia que hay entre "u" y "v", PA(u, v) como la distancia anterior a la nueva arista.
    Cuando se tiene dos nodos "u" y "v" que no estan unidos directamente en el arbol original, P(u, v) = d.
    Al crear el nuevo grafo, se añade una nueva arista que conecta directamente "u" y "v" pero ahora:
                                            
                                                    __
                                                   |
                                                   | d/2 si PA(u, v) es par
                                        P(u, v) =  |
                                                   | (d + 1)/2 si PA(u, v) es impar
                                                   |__
                                                   
    Denotemos: Ans como la suma de todos los caminos entre cualquier par de nodos y O como el numero de caminos
    de longitud impar.
    Para hallar O, tenemos que contar los nodos que tenga altura par e impar, luego multiplicar los valores. Esto
    funciona porque solo existen caminos de longitud impar si la altura de los pares de nodos tienen diferente paridad.
    Finalizando, la respuesta es (Ans + O)/2.
*/