#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[1010];

bool DFS(int u){
    int leaf = 0; 
    for(auto v : g[u]){
        if(g[v].empty()) leaf++;
        else if(!DFS(v)) return false;
    }
    return leaf >= 3;
}

int main(){
    int n, u;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &u), dEdge(u, i);
    if(DFS(1)) printf("Yes");
    else printf("No");
    return 0;
}