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
bool vist[200100];
int pa[200100], d;

void DFS(int u){
    vist[u] = true;
    for(auto v : g[u]){
        if(!vist[v]){
            pa[v] = u;
            if(u == 1) d--;
            DFS(v);
        }
    }
}

int main(){
    int n, m, u, v;
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    if(g[1].size() < d) printf("NO");
    else{
        DFS(1);
        if(d < 0) printf("NO");
        else{
            for(auto v : g[1]){
                if(pa[v] != 1 && d){
                    pa[v] = 1;
                    d--;
                }
            }
            printf("YES\n");
            for(int i = 2; i <= n; i++) printf("%d %d\n", pa[i], i);
        }
    }
    return 0;
}