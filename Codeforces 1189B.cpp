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

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    int n, ai, flag=0;
    lli check;
    vector<int> a;
    scanf("%d", &n);
    int ans[n];
    for(int i = 0; i < n; i++) scanf("%d", &ai), a.pb(ai);
    sort(a.begin(), a.end(), cmp);
    for(int i = 0, j = 0; i < n; i++){
        if(i%2==0) ans[j]=a[i], j++;
        else ans[n-j]=a[i];
    }
    if(ans[1]+ans[n-1] > ans[0] && ans[n-2]+ans[0] > ans[n-1]){
        for(int i = 1; i < n-1; i++){
            if(ans[i-1]+ans[i+1] <= ans[i]){
                flag=1;
                break;
            }
        }
    } else flag=1;
    if(flag) printf("NO");
    else{
        printf("YES\n");
        for(int i = 0; i < n; i++) printf("%d ", ans[i]);
    }
    return 0;
}
