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
vector<int> g[200010];
int price[200010];
bool vist[200010][2];
lli dp[200010][2], sum[200010], ans[200010];

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

void DFS(int u, int p){
    if(p && g[u].size()==1){
        dp[u][0]=price[u];
        dp[u][1]=0;
        return;
    }
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u);
        sum[u]+=dp[v][0];
    }
    for(auto v : g[u]){
        if(v == p) continue;
        dp[u][0]=min(dp[u][0], sum[u]-dp[v][0]+dp[v][1]+price[u]);
        dp[u][1]=min(dp[u][1], sum[u]-dp[v][0]+dp[v][1]);
    }
    dp[u][0]=min(dp[u][0], sum[u]);
}

void DFS(int u, int k, int p){
    if(vist[u][k]) return;
    vist[u][k]=1;
    if(p && g[u].size()==1){
        if(!k) ans[u]=1;
        return;
    }
    if(!k){
        if(dp[u][0]==dp[u][1]+price[u]){
            ans[u]=1;
            int cnt=0;
            for(auto v : g[u]){
                if(v==p) continue;
                if(dp[v][1]-dp[v][0]==dp[u][1]-sum[u]) DFS(v, 1, u), cnt++;
            }
            for(auto v : g[u]){
                if(v==p) continue;
                if(cnt>1 || dp[v][1]-dp[v][0]!=dp[u][1]-sum[u]) DFS(v, 0, u);
            }
        }
        if(dp[u][0]==sum[u]){
            for(auto v : g[u]){
                if(v==p) continue;
                DFS(v, 0, u);
            }
        }
    }else{
        int cnt=0;
        for(auto v : g[u]){
            if(v==p) continue;
            if(dp[v][1]-dp[v][0]==dp[u][1]-sum[u]) DFS(v, 1, u), cnt++;
        }
        for(auto v : g[u]){
            if(v==p) continue;
            if(cnt>1 || dp[v][1]-dp[v][0]!=dp[u][1]-sum[u]) DFS(v, 0, u);
        }
    }
}

int main(){
    int n, u, v, cnt=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &price[i]), dp[i][0]=dp[i][1]=LONG_LONG_MAX;
    for(int i=0; i<n-1; i++) scanf("%d %d", &u, &v), uEdge(u, v);
    DFS(1, 0);
    DFS(1, 0, 0);
    printf("%lld ", dp[1][0]);
    for(int i=1; i<=n; i++) if(ans[i]) cnt++;
    printf("%d\n", cnt);
    for(int i=1; i<=n; i++) if(ans[i]) printf("%d ", i);
    return 0;
}
