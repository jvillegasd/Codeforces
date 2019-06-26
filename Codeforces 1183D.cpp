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
vector<int> g[0];

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

bool cmp(const pii &a, const pii &b){
    return a.sp > b.sp;
}

int main(){
    int q, n, ai, cnt;
    lli ans;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &n);
        map<int, int> m;
        vector<pii> v;
        ans = 0;
        for(int j = 0; j < n; j++) scanf("%d", &ai), m[ai]++;
        for(auto &it : m) v.pb(it);
        sort(v.begin(), v.end(), cmp);
        ans+=v[0].sp;
        cnt = v[0].sp;
        for(int j = 1; j < v.size(); j++){
            cnt = max(min(cnt-1, v[j].sp), 0);
            ans+=cnt;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
