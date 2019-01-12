#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
const int MAXN = 500100;
bool primesB[MAXN], vist[MAXN];
lli ans = 0;
int spf[MAXN], a[MAXN];
vector<int> primes, g[MAXN], divide[MAXN];

void sieve(){
    memset(primesB, true, sizeof(primesB));
    for(int i = 2; i * i <= MAXN; i++){
        if(primesB[i]){
            for(int j = i * i; j <= MAXN; j+=i) primesB[j] = false;
        }
    }
    for(int i = 2; i <= MAXN; i++) if(primesB[i]) primes.pb(i);
}

void smallPF(){
    spf[1] = 1;
    for(int i = 2; i < MAXN; i++) spf[i] = i;
    for(int i = 4; i < MAXN; i+=2) spf[i] = 2;
    for(int i = 3; i * i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i * i; j < MAXN; j+=i) if(spf[j] == j) spf[j] = i;
        }
    }
}

vector<int> fact(int num){
    vector<int> ans;
    while(num != 1){
        ans.pb(spf[num]);
        num/=spf[num];
    }
    return ans;
}

lli DFS(int u, int prime){
    vist[u] = true;
    lli f = 0, s = 0, t;
    for(auto v : g[u]){
        if(!vist[v] && !(a[v] % prime)){
            t = DFS(v, prime);
            if(t > f) s = f, f = t;
            else if(t > s) s = t;
        }
    }
    ans = max(ans, f + s + 1);
    return f + 1;
}

int main(){
    int n, u, v, pn;
    sieve();
    smallPF();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vector<int> factors = fact(a[i]);
        for(auto pf : factors) divide[pf].pb(i);
    }
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), addEdge(u, v);
    for(int i = 0; i < primes.size(); i++){
        pn = primes[i];
        for(auto u : divide[pn]) vist[u] = false;
        for(auto u : divide[pn]) if(!vist[u]) DFS(u, pn);
    }
    printf("%lld", ans);
    return 0;
}
/*
    Por el teorema fundamental de la aritmetica (TFA) sabemos de que todos los numeros son primos o numeros compuestos
    por uno o mas numeros primos y/o potencias de esta.
    Para un camino que cumpla que g(x, y) > 1, existe un GCD que es divisible con los nodos perteneciente al camino,
    por lo que tambien un factor primo del GCD tambien lo es, entonces, usando el TFA podemos concluir de que 
    la solucion es el maximo camino donde cada nodo sea divisible por algun factor primo del GCD.
    En el DFS se tienen 2 variables importantes "f" y "s", estos denotan el primer camino mas largo encontrado (f)
    y el segundo (s). Se tienen en cuenta estas dos variables debido a que se pueden unir el camino "f" que se obtuvo
    por un lado de la raiz y "s" del otro lado, por lo que f + s + 1 denota el camino union pasando por la raiz.
*/