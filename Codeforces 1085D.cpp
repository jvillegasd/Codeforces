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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

int main(){
    int n, s, deg[100100] = {0}, leafn = 0, u, v;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), deg[u]++, deg[v]++;
    for(int i = 1; i <= n; i++) if(deg[i] == 1) leafn++;
    printf("%.7lf", 2.0*s/leafn);   
    return 0;
}
/*
    La estrategia es repartir "s" en todos los nodos hojas y dejar las demas arista con peso "0", eso se tiene en
    cuenta en los casos de prueba.
*/