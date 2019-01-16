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
vector<int> g[1000100], d[100100];
vector<pii> info;

bool cmp(const pii &a, const pii &b){
    return a.sp < b.sp;
}

int main(){
    int n, k, di, u, flag, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &di);
        d[di].pb(i);
        info.pb({i, di});
    }
    sort(info.begin(), info.end(), cmp);
    if(info[0].sp != 0) printf("-1");
    else{
        for(int i = 1; i < info.size(); i++){
            u = info[i].fp;
            di = info[i].sp - 1;
            if(di == -1){
                printf("-1");
                return 0;
            }
            flag = 0;
            for(auto v : d[di]){
                if(g[v].size() < k){
                    uEdge(u, v);
                    ans++;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                printf("-1");
                return 0;
            }
        }
        printf("%d\n", ans);
        for(u = 1; u <= n; u++){
            for(auto v : g[u]) if(u > v) printf("%d %d\n", u, v);
        }
    }
    return 0;
}
/*
    Para cada nodo "u" con d[u] != 0, solo se puede crear arista con alguno nodo "v" tal que d[v] >= d[u] - 1.
    Mi estrategia es ir uniendo cada nodo "u" con un solo nodo "v" que tenga d[v] = d[u] - 1, tener en cuenta
    los casos donde no es posible reconstruir el grafo.
*/