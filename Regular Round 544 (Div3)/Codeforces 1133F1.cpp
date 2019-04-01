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

int main(){
    int n, m, u, v, maxi = 0;
    queue<int> q;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    for(int i = 1; i <= n; i++) if(g[i].size() > maxi) u = i, maxi = g[i].size();
    q.push(u);
    vist[u] = true;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto v : g[u]) if(!vist[v]) vist[v] = true, q.push(v), printf("%d %d\n", u, v);
    }
    return 0;
}