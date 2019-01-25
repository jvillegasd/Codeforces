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
vector<int> g[200100];
int order[200100];
bool vist[200100];

bool cmp(const int &a, const int &b){
    return order[a] < order[b];
}

int main(){
    int n, u, v, seq[200100];
    queue<int> q;
    vector<int> bfsq;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    for(int i = 1; i <= n; i++) scanf("%d", &seq[i]), order[seq[i]] = i;
    for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);
    q.push(1);
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(vist[u]) continue;
        vist[u] = true;
        bfsq.pb(u);
        for(auto v : g[u]) if(!vist[v]) q.push(v);
    }
    for(int i = 1; i <= n; i++){
        if(seq[i] != bfsq[i - 1]){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
/*
    El BFS barre pero nivel desde el hijo mas a la izquierda hasta el que esta mas a la derecha y esto implica
    en el orden de impresion, por eso se tiene en cuenta el orden de la secuencia BFS que nos dan en la input
    y organizamos los nodos del arbol descendentemente ayudandose del orden anteriormente mencionado.
*/