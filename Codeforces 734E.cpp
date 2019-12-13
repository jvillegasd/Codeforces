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
#define MOD 1000000007

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];
vector<int> g[200010], tree[200010];
map<int, int> label;
int color[200010], cnt=1, diameter=0, node;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void buildTree(int u, int p=0){
    for(auto v : g[u]){
        if(v == p) continue;
        if(color[u] == color[v]) label[v] = label[u];
        else{
            label[v] = cnt++;
            tree[label[u]].pb(label[v]);
            tree[label[v]].pb(label[u]);
        }
        buildTree(v, u);
    }
}

void DFS(int u,  int p=0, int dist=0){
    for(auto v : tree[u]){
        if(v == p) continue;
        if(dist + 1 > diameter) diameter=dist+1, node=v;
        DFS(v, u, dist+1);
    }
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(u = 1; u <= n; u++) scanf("%d", &color[u]);
    for(int i = 0; i < n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    label[1] = cnt++;
    buildTree(1);
    if(tree[1].size()){
        DFS(1);
        DFS(node);
        printf("%d", (diameter+1)/2);
    } else printf("0");
    return 0;
}
