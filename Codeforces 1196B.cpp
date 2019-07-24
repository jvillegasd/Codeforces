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
vector<int> g[0];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

int main(){
    int q, n, k, ai, even, odd, limit;
    scanf("%d", &q);
    while(q--){
        even=odd=0;
        vector<int> a;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &ai), (ai%2 == 0)?even++:odd++, a.pb(ai);
        if((k%2 == 0 && odd%2 == 0 || k%2 != 0 && odd%2 != 0) && k <= odd){
            printf("YES\n");
            for(int i = 0; i < n; i++){
                if(k == 1) break;
                if(a[i]%2 != 0){
                    printf("%d ", i+1);
                    k--;
                }
            }
            printf("%d\n", n);
        } else printf("NO\n");
    }
    return 0;
}
