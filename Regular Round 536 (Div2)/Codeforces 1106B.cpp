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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

struct food{
    lli c, i;

    bool operator<(const food &f2)const{
        if(c == f2.c) return i > f2.i;
        return c > f2.c;
    }
};

int main(){
    int n, m, ti, di;
    vector<lli> cust;
    lli a[100100], c[100100], cost;
    priority_queue<food> pq;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]), pq.push({c[i], i});
    while(m--){
        scanf("%d %d", &ti, &di);
        cost = 0;
        if(a[ti] - di >= 0) cost+=di * c[ti], a[ti]-=di;
        else{
            cost+=a[ti] * c[ti];
            di-=a[ti];
            a[ti] = 0;
            while(!pq.empty() && di > 0){
                lli chc = pq.top().c, chi = pq.top().i;
                pq.pop();
                if(!a[chi]) continue;
                if(a[chi] - di >= 0){
                    cost+=di * chc;
                    a[chi]-=di;
                    pq.push({chc, chi});
                    break;
                }else cost+=a[chi] * chc, di-=a[chi], a[chi] = 0;
            }
        }
        if(pq.empty() && di > 0) cost = 0;
        cust.pb(cost);
    }
    for(int i = 0; i < cust.size(); i++) printf("%lld\n", cust[i]);
    return 0;
}