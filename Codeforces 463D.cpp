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
vector<int> g[1010];
bool vist[1010];
int dp[1010], maxi = INT_MIN;

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

void DFS(int u){
    vist[u] = 1;
    for(auto v : g[u]){
        if(!vist[v]) DFS(v);
        dp[u] = max(dp[u], dp[v]+1);
    }
    maxi = max(maxi, dp[u]);
}

int main(){
    int n, k, flag;
    int per[6][1010], pos[6][1010];
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) for(int j = 1; j <= n; j++) scanf("%d", &per[i][j]), pos[i][per[i][j]]=j;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            flag = 1;
            for(int l = 1; l <= k; l++) if(pos[l][j] <= pos[l][i]) flag = 0;
            if(flag) dEdge(i, j);
        }
    }
    for(int u = 1; u <= n; u++) if(!vist[u]) DFS(u);
    printf("%d", maxi+1);
    return 0;
}
