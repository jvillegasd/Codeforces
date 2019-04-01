#include <bits/stdc++.h>
#define pb push_back
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

int main(){
    lli n, m, divi;
    int cnt = 0;
    scanf("%lld %lld", &n, &m);
    if(m % n) printf("-1");
    else{
        divi = m / n;
        while(!(divi % 2) || !(divi % 3)){
            if(!(divi % 2)) divi/=2, cnt++;
            else if(!(divi % 3)) divi/=3, cnt++;
        }
        if(divi != 1) printf("-1");
        else printf("%d", cnt);
    }
    return 0;
}