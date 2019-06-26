#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
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
int n, k;
lli a[110];

int main(){
    int q, flag;
    lli mini;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &n, &k);
        mini = LONG_LONG_MAX;
        for(int j = 0; j < n; j++) scanf("%lld", &a[j]), mini = min(mini, a[j]);
        mini+=k;
        flag = 0;
        for(int j = 0; j < n; j++){
            if(abs(a[j]-mini)>k){
                flag = 1;
                break;
            }
        }
        if(flag) printf("-1\n");
        else printf("%lld\n", mini);
    }
    return 0;
}
