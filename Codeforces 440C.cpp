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
vector<int> g[0];

lli ones[18];

int DFS(lli n, int i){
    if(!i) return 0;
    int cnt = (n / ones[i]) * i;
    n%=ones[i];
    return cnt + min(DFS(n, i - 1), DFS(ones[i] - n, i - 1) + i);
}

int main(){
    lli n;
    for(int i = 1; i <= 16; i++) ones[i] = ones[i - 1] * 10 + 1;
    scanf("%lld", &n);
    printf("%d", DFS(n, 16));
    return 0;
}
/*
    Existen dos casos posibles:
    1) El resto de la division puede expresarse de manera optima con "1"s
    2) La resta de ones[i] con el resto de la division puede expresarse de manera optima con "1"s
    Ejemplo: Hay dos formas de re-expresar n = 10:
    *) 1+1+1+1+1+1+1+1+1+1 = 10 <- Obtenemos esto si usamos (1)
    *) 11-1 = 10 <- Obtenemos esto si usamos (2)
    Claramente si usamos (2) en este caso obtendremos el minimo uso de "1"
*/