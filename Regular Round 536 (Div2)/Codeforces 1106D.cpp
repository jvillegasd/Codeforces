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
vector<int> g[100100];
bool vist[100100];

int main(){
    int n, m, u, v;
    priority_queue<minHeap> pq;
    vector<int> path;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    pq.push(1);
    while(!pq.empty()){
        u = pq.top();
        pq.pop();
        if(vist[u]) continue;
        vist[u] = true;
        path.pb(u);
        for(auto v : g[u]) if(!vist[v]) pq.push(v);
    }
    for(int i = 0; i < path.size(); i++) printf("%d ", path[i]);
    return 0;
}