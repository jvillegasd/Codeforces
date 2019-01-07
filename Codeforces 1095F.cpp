#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
int parent[200100];

void makeSet(int n){
    for(int i = 0; i < n; i++) parent[i] = i;
}

int find(int i){
    if(i == parent[i]) return i;
    return parent[i] = find(parent[i]);
}

bool unionSet(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    if(iRoot == jRoot) return false; 
    parent[iRoot] = jRoot;
    return true;
}

int main(){
    lli a[200100];
    vector<pair<lli, pii>> edges; 
    int n, m, xi, yi, ai;
    lli wi, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d %d %lld", &xi, &yi, &wi), edges.pb({wi, {--xi, --yi}});
    int j = min_element(a, a + n) - a; //Para hallar el indice del elemento minimo, distancia de punteros
    for(int i = 0; i < n; i++) if(i != j) edges.pb({a[i] + a[j], {i, j}});
    sort(edges.begin(), edges.end());
    makeSet(n);
    for(auto e : edges){
        int u = e.second.first, v = e.second.second;
        if(unionSet(u, v)) ans+=e.first;
    }
    printf("%lld", ans);
    return 0;
}