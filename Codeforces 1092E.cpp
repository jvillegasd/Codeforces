#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<int> g[2100];
int parent[2100];
int b, maxi;
bool vist[2100];

void DFS(int u, int cont){
    vist[u] = true;
    cont++;
    for(auto v : g[u]){
        if(!vist[v]){
            if(cont >= maxi) maxi = cont, b = v;
            parent[v] = u;
            DFS(v, cont);
        }
    }
}

pii treeDiam(int u){
    vector<int> path;
    memset(parent, -1, sizeof(parent));
    memset(vist, false, sizeof(vist));
    maxi = 0;
    DFS(u, 0);
    memset(vist, false, sizeof(vist));
    parent[b] = -1;
    DFS(b, 0);
    while(true){
        path.push_back(b);
        b = parent[b];
        if(b == -1) break;
    }
    return {maxi, path.size() == 1? u : path[path.size()/2]};
}

bool cmp(const pii &a, const pii &b){
    return a.first > b.first;
}

int main(){
    int n, m, u, v, diam;
    vector<pii> nodes, ans;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), g[u].push_back(v), g[v].push_back(u);
    for(int i = 1; i <= n; i++) if(!vist[i]) nodes.push_back(treeDiam(i));
    sort(nodes.begin(), nodes.end(), cmp);
    u = nodes[0].second;
    for(int i = 1; i < nodes.size(); i++){
        v = nodes[i].second;
        ans.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    diam = treeDiam(1).first;
    printf("%d\n", diam);
    for(auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
/*
    La estrategia es localizar los diametros de todos los bosques, luego, -si se puede- tomar el nodo de la mitad
    del camino del diametro de cada bosque y añadirlo con una arista al nodo de la mitad del camino del diametro mas
    grande. Finalizando, hallar de nuevo el diametro del arbol creado e imprimir las arista necesarias del proceso
    anterior.
*/