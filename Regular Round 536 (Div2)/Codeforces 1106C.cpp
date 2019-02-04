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
    int n, s[300100];
    lli ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);
    sort(s, s + n);
    for(int i = 0; i < n/2; i++) ans+=(s[i] + s[n - i - 1]) * (s[i] + s[n - i - 1]);
    printf("%lld", ans);
    return 0;
}
/*
    Esto funciona por el: Rearrangement inequality
*/
