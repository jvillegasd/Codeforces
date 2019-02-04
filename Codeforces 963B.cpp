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
vector<int> g[200100];
int sz[200100], root;
bool vist[200100];

void delSubtree(int u){
    vist[u] = true;
    printf("%d\n", u);
    for(auto v : g[u]) if(!vist[v]) delSubtree(v);
}

void DFS(int u){
    int degree = 0;
    for(auto v : g[u]){
        DFS(v);
        if(!vist[v]) degree++;
    }
    if(u != root) degree++;
    if(!(degree & 1)) delSubtree(u);
}

int main(){
    int n, u;
    scanf("%d", &n);
    for(int v = 1; v <= n; v++){
        scanf("%d", &u);
        if(u) dEdge(u, v);
        else root = v;
    }
    if(n & 1) printf("YES\n"), DFS(root);
    else printf("NO");
    return 0;
}
/*
    Se trata el Arbol como direccionado porque solo se tiene que eliminar el subarbol cuya raiz v
    tenga degree(v) par.
*/