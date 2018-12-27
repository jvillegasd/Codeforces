#include <bits/stdc++.h>

using namespace std;

int n, m, ai, aj;
bool vist[101], color[101], del[101];
vector<int> g[101];

void DFS(int node, int c){
    color[node] = c;
    vist[node] = true;
    for(int i = 0; i < g[node].size(); i++){
        if(!vist[g[node][i]]) DFS(g[node][i], !c);
        else if(vist[g[node][i]] && color[node] == color[g[node][i]] && !del[node]) del[g[node][i]] = true;
    }
}

int main(){
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &ai, &aj), g[ai].push_back(aj), g[aj].push_back(ai);
    for(int i = 1; i <= n; i++) if(!vist[i]) DFS(i, 0);
    for(int i = 1; i <= n; i++) if(del[i]) ans++;
    if((n - ans) % 2) ans++; //Los euipos deben tener el mismo tamaño
    printf("%d", ans);
    return 0;
}