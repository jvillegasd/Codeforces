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
lli nl, arr[0];
vector<int> g[100010];
int k, d[100010], parent[100010];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}

void DFS(int u, int p){
    d[u]=d[p]+1;
    parent[u]=p;
    for(auto v : g[u]){
        if(v == p) continue;
        if(!d[v]) DFS(v, u);
        else if(d[u]-d[v] >= k){
            printf("%d\n", d[u]-d[v]+1);
            for(int i = 0, j = u; i <= d[u]-d[v]; i++) printf("%d ", j), j=parent[j];
            exit(0);
        }
    }
}

int main(){
    int n, m, u, v;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(1, 1);
    return 0;
}
