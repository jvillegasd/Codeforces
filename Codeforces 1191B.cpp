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
    BOOST;
    string a, b, c;
    cin >> a >> b >> c;
    map<char, vector<int>> mapa;
    mapa[a[1]].pb(a[0]-'0');
    mapa[b[1]].pb(b[0]-'0');
    mapa[c[1]].pb(c[0]-'0');
    for(auto it : mapa){
        if(it.sp.size() == 2){
            vector<int> v = it.sp;
            sort(v.begin(), v.end());
            if(v[1]-v[0]==1 || v[1]-v[0]==2 || v[0]==v[1]) printf("1"); //Shuntsu or Koutsu
            else printf("2"); //Koutsu
            exit(0);
        }
        if(it.sp.size() == 3){
            vector<int> v = it.sp;
            sort(v.begin(), v.end());
            if(v[1]-v[0]==1 && v[2]-v[1]==1 || v[0]==v[1] && v[1]==v[2]) printf("0"); //Perfect Shuntsu or Koutsu
            else if(v[1]-v[0]==1 || v[2]-v[1]==1 || v[1]-v[0]==2 || v[2]-v[1]==2 || v[0]==v[1] || v[1]==v[2]) printf("1"); //Shuntsu or Koutsu
            else printf("2"); //Koutsu
            exit(0);
        }
    }
    printf("2");
    return 0;
}
