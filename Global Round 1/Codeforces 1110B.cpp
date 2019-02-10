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
    int n, m, k, b[100010], x = 0, ans = 0, bi;
    scanf("%d %d %d", &n, &m, &k);
    scanf("%d", &x);
    for(int i = 0; i < n - 1; i++) scanf("%d", &bi), b[i] = bi - (x + 1), x = bi;
    sort(b, b + n - 1);
    ans = n;
    for(int i = 0; i < n - k; i++) ans+=b[i];
    printf("%d", ans);
    return 0;
}