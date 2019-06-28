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

int main(){
    BOOST;
    string a, b;
    int cnt = 0, ps[1000010], ans = 0;
    cin >> a >> b;
    ps[0] = (a[0] == '1')?1:0;
    for(int i = 0; i < b.length(); i++) if(b[i] == '1') cnt++;
    for(int i = 1; i < a.length(); i++) if(a[i] == '1') ps[i] = ps[i-1] + 1; else ps[i] = ps[i-1];
    for(int i = b.length()-1; i < a.length(); i++) if((ps[i]-ps[i-b.length()]+cnt)%2==0) ans++;
    printf("%d", ans);
    return 0;
}
