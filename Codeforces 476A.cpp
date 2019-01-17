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
    int n, m, twoStep;
    scanf("%d %d", &n, &m);
    if(n < m) printf("-1");
    else{
        twoStep = n/2 + n%2;
        if(!(twoStep % m)) printf("%d", twoStep);
        else printf("%d", twoStep - twoStep % m + m);
    }
    return 0;
}
/*
    Solucion:
    twoStep tendra los pasos de "2" posibles y un paso de "1" si es impar, si twoStep no es multiplo de m, se 
    le quitara twoStep % m y esto significa que al conjunto creado se eliminara tantos "2" como twoStep % m valga, 
    para luego agregar o reemplazar "2" con tantos "1" como m valga.
*/