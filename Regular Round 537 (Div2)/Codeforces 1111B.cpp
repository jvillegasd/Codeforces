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

int main(){
    int n, m, k, po[100100];
    double avg = 0;
    lli sum = 0;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &po[i]);
    sort(po + 1, po + n + 1);
    for(int i = n - 1; i >= 0; i--){
        sum+=po[i + 1];
        if(i <= m) avg = max(avg, (sum + min(1LL * k * (n - i), 1LL * m - i)) * 1.0 / ((n - i) * 1.0) );
    }
    printf("%.6lf", avg);
    return 0;
}