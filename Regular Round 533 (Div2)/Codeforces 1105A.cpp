#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

int main(){
    int n, a[1100], mini = INT_MAX, minia, ans, lb, hb, cont;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int t = 1; t <= 100; t++){
        minia = cont = 0;
        for(int i = 0; i < n; i++){
            if(abs(a[i] - t) > 1){
                lb = t - 1;
                hb = t + 1;
                if(abs(a[i] - lb) < abs(a[i] - hb)) minia+=abs(a[i] - lb), cont++;
                else if(abs(a[i] - hb) < abs(a[i] - lb)) minia+=abs(a[i] - hb), cont++;
            }else if(abs(a[i] - t) <= 1) cont++;
        }
        if(minia < mini && cont == n) ans = t, mini = minia;
    }
    printf("%d %d", ans, mini);
    return 0;
}