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
vector<int> g[1000010];
multiset<int> dsu[1000010];
int k;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

int binsearch(int n, lli arr[], lli sum){
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==sum) return mid;
        if(arr[mid]<sum) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

void DFS(int u, int p, int d){
    if(p && g[u].size()==1){
        dsu[u].insert(d);
        return;
    }
    int bigc = -1, dk, dki_val;
    for(auto v : g[u]){
        if(v==p) continue;
        DFS(v, u, d+1);
        if(bigc == -1 || dsu[v].size() > dsu[bigc].size()) bigc = v;
    }
    swap(dsu[bigc], dsu[u]);
    for(auto v : g[u]){
        if(v==p || v==bigc) continue;
        for(auto di : dsu[v]){
            dk = d+k-(di-d);
            auto dki = dsu[u].upper_bound(dk);
            if(dki==dsu[u].begin()) dsu[u].insert(di);
            else{
                --dki;
                dki_val = *dki;
                dsu[u].erase(dki);
                dsu[u].insert(max(di, dki_val));
            }
        }
    }
}

int main(){
    int n, u, v;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    for(u=1; u<=n; u++){
        if(g[u].size()>1){
            DFS(u, 0, 0);
            printf("%d\n", dsu[u].size());
            break;
        }
    }
    return 0;
}
