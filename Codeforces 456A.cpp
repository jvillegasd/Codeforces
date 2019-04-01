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
vector<int> g[0];

int main(){
    int n, ai, bi, flag = 0;
    vector<pii> l;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &ai, &bi), l.pb({ai, bi});
    sort(l.begin(), l.end());
    for(int i = 0; i < l.size() - 1; i++){
        if(l[i].fp < l[i + 1].fp && l[i].sp > l[i + 1].sp){
            flag = 1;
            break;
        }
    }
    if(flag) printf("Happy Alex");
    else printf("Poor Alex");
    return 0;
}