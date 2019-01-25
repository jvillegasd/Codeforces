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
    int vc = 1, hc = 1;
    string inp;
    cin >> inp;
    for(int i = 0; i < inp.length(); i++){
        if(inp[i] == '0'){
            printf("1 %d\n", vc++);
            if(vc == 5) vc = 1;
        } else{
            printf("3 %d\n", hc);
            hc+=2;
            if(hc == 5) hc = 1;
        }
    }
    return 0;
}
/*
    El stament final del output hizo que tardara en entender realmente que habia que hacer. Teniendo en cuenta
    de que solo interesa de que todas las fichas sean colocadas en el tablero 4x4 voy colocando las fichas
    verticales desde la columna 1 a la 4, de tal manera de que siempre que se lleve se desocupan esas posiciones y
    por otro lado, las verticales las coloco tambien de seguidas en la columna 3 cosa que tambien al colocar 2
    fichas horizontales, estas se desocupan para que sean reemplazadas por otras
*/