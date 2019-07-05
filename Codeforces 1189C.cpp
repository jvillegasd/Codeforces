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
lli nl, arr[100010];
vector<int> g[0];
pair<lli, lli> tree[400010];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void buildTree(int node, int l, int r){
    if(l == r){
        tree[node] = {arr[l], 0};
        return;
    }
    int mid = (l + r)/2, cnt=0;
    buildTree(2*node, l, mid);
    buildTree(2*node + 1, mid + 1, r);
    if(tree[2*node].fp+tree[2*node+1].fp >= 10) cnt=1;
    tree[node] = {(tree[2*node].fp+tree[2*node+1].fp)%10, tree[2*node].sp+tree[2*node+1].sp+cnt};
}

pair<lli, lli> query(int node, int l, int r, int i, int j){
    if(i <= l && r <= j) return tree[node];
    if(r < i || l > j) return {0,0};
    int mid = (l + r)/2, cnt=0;
    pair<lli, lli> a = query(2*node, l, mid, i, j);
    pair<lli, lli> b = query(2*node+1, mid + 1, r, i, j);
    if(a.fp+b.fp >= 10) cnt=1;
    return {(a.fp+b.fp)%10, a.sp+b.sp+cnt};
}

int main(){
    int n, q, l, r;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    buildTree(1, 1, n);
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(1, 1, n, l, r).sp);
    }
    return 0;
}
