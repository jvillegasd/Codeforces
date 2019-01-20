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
vector<int> g[100100], ig[100100];
bool vist[100100];
int n, comp[100100], compSize[100100];
stack<int> s;

void DFS(int u){
    vist[u] = true;
    for(auto v : g[u]) if(!vist[v]) DFS(v);
    s.push(u);
}

void DFS(int u, int compi){
    vist[u] = true;
    comp[u] = compi;
    for(auto v : ig[u]) if(!vist[v]) DFS(v, compi);
}

void SCC(){
    int compi = 1, u;
    memset(vist, false, sizeof(vist));
    for(int i = 1; i <= n; i++) if(!vist[i]) DFS(i);
    memset(vist, false, sizeof(vist));
    while(!s.empty()){
        u = s.top();
        s.pop();
        if(!vist[u]) DFS(u, compi++);
    }
}

bool isAcyclic(int u){
    vist[u] = true;
    int exist = compSize[comp[u]] == 1;
    for(auto v : g[u]) if(!vist[v]) exist&=isAcyclic(v);
    for(auto v : ig[u]) if(!vist[v]) exist&=isAcyclic(v);
    return exist;
}

int main(){
    int m, u, v, ans;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), dEdge(u, v), ig[v].pb(u);
    SCC();
    for(int i = 1; i <= n; i++) compSize[comp[i]]++;
    memset(vist, false, sizeof(vist));
    ans = n;
    for(int i = 1; i <= n; i++) if(!vist[i]) ans-=isAcyclic(i);
    printf("%d", ans);
    return 0;
}
/*
    El problema se resuma a que dado "n" ciudades con "m" parejas importantes, hallar el minimo de aristas
    talque que las "m" parejas si o si tengan un camino ya sea directo o indirecto.
    Denotemos como G al grafo final que posee como aristas las "m" parejas y las demas ciudades que no aparecen.
    Denotemos como C a una componente de G.
    Analizando el problema se presentan 2 casos para una componente de G y es si posee ciclos o no:
    -) Si la componente no posee ciclos, entonces la respuesta para esa componente es |C| - 1 ya que se podria
        crear una cadena a raiz de un ordenamiento topoligo que clamente cumple con la condicion impuesta.
    -) Si la componente posee ciclos, entoneces la respuesta para esa componente es |C| ya que se podria crear
        una rueda de tal manera de que cada ciudad pudiera llegar a otra.
    Solucion 1, SCC descomposition o Descomposicion por Componentes Fuertemente Conexas:
    La idea es obtener las diferentes SCC que pueden contener cada C de G para luego verificar si alguna C posee
    ciclo o no, esto es sencillo ya que solo se veria si el tamaño de la SCC es 1 o mayor.
    PD: A pesar de que G es dirigido, al momento de guardar alguna C o verificar si tiene ciclo, se recorre G 
    sin tener en cuenta las direcciones para garantizar el recorrido de toda la componente.
*/