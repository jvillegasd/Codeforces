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
    int n;
    scanf("%d", &n);
    if(n % 4 == 1) printf("0 A");
    else if((n+1) % 4 == 1) printf("1 A");
    else if((n+2) % 4 == 1) printf("2 A");
    else if(n % 4 == 3) printf("0 B");
    else if((n+1) % 4 == 3) printf("1 B");
    else if((n+2) % 4 == 3) printf("1 B");
    else if(n % 4 == 2) printf("0 C");
    else if((n+1) % 4 == 2) printf("1 C");
    else if((n+2) % 4 == 2) printf("2 C");
    else printf("0 D");
    return 0;
}
