#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
int a[4200000], n;
bool vist[4200000], exist[4200000];
vector<int> g[0];

void DFS(int mask){
    if(vist[mask]) return;
    vist[mask] = true;
    for(int i = 0; i < n; i++) if((1 << i) & mask) DFS(mask - (1 << i));
    if(exist[mask]) DFS((1 << n) - 1 - mask);
}

int main(){
    int m, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]), exist[a[i]] = true;
    for(int i = 0; i < m; i++) if(!vist[a[i]]) DFS((1 << n) - 1 - a[i]), ans++;
    printf("%d", ans);
    return 0;
}
/*
    Antes de explicar la solucion hay que tener en cuenta un concepto que es sobre las mascaras y submascaras.
    Una mascara vendria siendo un numero en la cual tiene varios bits en "1" y/o "0" dependiendo de la situacion y las
    submascaras vendria siendo todos los numeros binarios posibles que se encuentra prendiendo o apagando los bits
    que inicialmente estaban en "1", ejemplo:
    Supongamos que tenemos mask = 10 entero y en binario mask = 1010, entonces, las submascaras posibles son:
                                                    1010
                                                    1000
                                                    0010
    Nota: El complemento A2 para un numero x es 2^n - 1 - x, donde n = numero de bits posibles.

    Explicacion de la solucion:
    Primero que todo, para crear una arista con "u" y "v" se debe cumplir que u & v = 0, esto solo es posible
    si "v" es el complemento de "u", notese que para cada submascara del complemento de "u", la afirmacion anterior
    tambien se cumple, es decir, "v" debe ser alguna submascara de "u". La solucion es para cada elemento a[i], sacar 
    su complemento e ir viendo de que alguna(s) de sus submascaras pertenezcan tambien al array a[].
*/