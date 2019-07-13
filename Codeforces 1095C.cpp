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
    int n, k, cnt=0;
    queue<int> q;
    map<int, int> mapa;
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= 30; i++){
        if(n & (1<<i)){
            if(i > 0) q.push(1<<i);
            mapa[1<<i]++;
        }
    }
    if(mapa.size() > k) printf("NO");
    else{
        cnt=mapa.size();
        while(cnt < k && !q.empty()){
            int qf = q.front();
            q.pop();
            mapa[qf]--;
            mapa[qf/2]+=2;
            if(qf/2 > 1) q.push(qf/2), q.push(qf/2);
            cnt++;
        }
        if(cnt < k) printf("NO");
        else{
            printf("YES\n");
            for(auto it : mapa) for(int i = 0; i < it.sp; i++) printf("%d ", it.fp);
        }
    }
    return 0;
}
