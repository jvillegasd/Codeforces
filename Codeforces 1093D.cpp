#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
vector<int> g[400000];
int color[400000], cont[2], pot[400000];
bool bip;

void DFS(int u, int c){
    color[u] = c;
    cont[c]++;
    for(auto v : g[u]){
        if(color[v] == -1) DFS(v, !c);
        else if(color[v] == color[u]) bip = false;
    }
}

int main(){
    int tc, n, m, u, v, pos, ans = 1;
    pot[0] = 1;
    for(int i = 1; i < 400000; i++) pot[i] = (2 * pot[i - 1]) % mod;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) g[i].clear(), color[i] = -1;
        ans = 1;
        for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), g[--u].push_back(--v), g[v].push_back(u); 
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                bip = true;
                cont[0] = cont[1] = 0;
                DFS(i, 0);
                if(!bip) break;
                pos = (pot[cont[0]] + pot[cont[1]]) % mod;
                ans = (ans * 1LL * pos) % mod;
            }
        }
        if(bip) printf("%d\n", ans);
        else printf("0\n");
    }
    return 0;
}
/*
    La estrategia es tomar "1, 2, 3" como colores y darse cuenta de que si un nodo esta coloreado de un numero
    par, los adjacentes deben ser impar y viceversa. Solo es posible que el grafo sea "beautiful" si y solo si
    todas las componentes del grafo son bipartitas, entonces, la solucion es multiplicar las formar en que se
    puede pintar cada componente. El numero de formas en que se puede pintar una componente es:
                                                2^a + 2^b
                            Donde a es el tamaño del primer conjunto y b el tamaño del otro
    El conjunto a esta conformado por los nodos que se pintan con el "2", y el conjunto b esta conformado por
    los nodos que pueden ser pintados de "1" o "3".
*/