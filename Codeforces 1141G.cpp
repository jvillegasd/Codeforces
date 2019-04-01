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
vector<pii> g[200010];
int colors[200010], deg[200010], opk;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

void DFS(int u, int p, int c){
    for(auto pi : g[u]){
        int v = pi.fp, id = pi.sp;
        if(v == p) continue;
        colors[id] = c;
        c = (c + 1) % opk;
        DFS(v, u, c);
    }
}

int main(){
    int n, k, u, v;
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        uwEdge(u, v, i);
        deg[u]++;
        deg[v]++;
    }
    sort(deg + 1, deg + 1 + n);
    reverse(deg + 1, deg + 1 + n);
    opk = deg[k + 1];
    DFS(1, 0, 0);
    printf("%d\n", opk);
    for(int i = 1; i < n; i++) printf("%d%c", colors[i] + 1, i==n-1?'\n':' ');
    return 0;
}
/*
    Si tomamos como "D" al grado maximo que tiene un vertice en "G", entonces, podemos asegurarnos de que
    podemos pintar de "D" colores distintos "G". Como tenemos que dejar que "k" vertices no cumplan la propiedad,
    entonces tenemos que encontrar un "opk" tal que solo desechemos "k" vertices.
*/