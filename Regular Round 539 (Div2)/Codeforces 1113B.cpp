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
    int n, a[50010], sum = 0, mini = INT_MAX, cur, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), mini = min(mini, a[i]), sum+=a[i];
    ans = sum;
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= a[i]; x++){
            if(a[i] % x) continue;
            cur = sum - mini - a[i];
            cur+=mini*x + a[i]/x;
            ans = min(ans, cur);
        }
    }
    printf("%d", ans);
    return 0;
}   