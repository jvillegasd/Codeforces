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

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bins(lli n,lli arr[],lli sum){int l=0,r=n-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}

vector<lli> div(lli n){
    vector<lli> ans;
    for(lli i = 2; i <= sqrt(n); i++){
        if(!(n%i)){
            if(n/i==i) ans.pb(i);
            else ans.pb(i), ans.pb(n/i);
        }
    }
    return ans;
}

int main(){
    lli n, ans=0;
    scanf("%lld", &n);
    if(n == 2) printf("0");
    else{
        for(lli i = 2; i <= n; i++){
            vector<lli> d = div(i);
            for(auto di : d){
                if(di == i) continue;
                ans+=(4*(i/di));
            }
        }
        printf("%lld", ans);
    }
    return 0;
}
