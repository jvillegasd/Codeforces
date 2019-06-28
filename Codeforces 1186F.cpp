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
vector<pii> g;
int deg[1000010], n, m, cnt = 0, cnt2 = 0, limit[1000010];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

int binsearch(int n, float arr[], int sum){
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==sum) return mid;
        if(arr[mid]<sum) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

bool cmp(const pii &a, const pii &b){
    if(a.fp != b.fp) return deg[a.fp] > deg[b.fp];
    return deg[a.sp] > deg[b.sp];
}

int main(){
    int u, v;
    vector<pii> ans;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), g.pb({u, v}), deg[u]++, deg[v]++;
    for(int i = 1; i <= n; i++) limit[i] = deg[i]/2 + deg[i]%2;
    sort(g.begin(), g.end(), cmp);
    for(auto e : g){
        u = e.fp, v = e.sp;
        if(deg[u] > limit[u] && deg[v] > limit[v]) deg[u]--, deg[v]--;
        else ans.pb(e);
    }
    printf("%d\n", ans.size());
    for(auto e : ans) printf("%d %d\n", e.fp, e.sp);
    return 0;
}
