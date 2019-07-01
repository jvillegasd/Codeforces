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
vector<int> g[28];
bool vist[28], be[28];
bool can = 1;
stack<int> sk;

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

void DFS(int u){
    vist[u] = 1;
    be[u] = 1;
    for(auto v : g[u]){
        if(!vist[v]) DFS(v);
        else if(be[v]) can = 0;
    }
    be[u] = 0;
    sk.push(u);
}

int main(){
    BOOST;
    int n, j;
    string lt[100], s, t;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> lt[i];
    for(int i = 1; i < n; i++){
        s = lt[i-1], t = lt[i];
        j = 0;
        while(j < s.size() && j < t.size() && s[j] == t[j]) j++;
        if(j < s.size() && j < t.size()) dEdge(s[j]-'a', t[j]-'a');
        else if(t.size() < s.size()){
            can = 0;
            break;
        }
    }
    if(can){
        memset(vist, 0, sizeof(vist)), memset(be, 0, sizeof(be));
        for(int i = 0; i < 26; i++) if(!vist[i]) DFS(i);
        if(can) while(!sk.empty()) printf("%c", sk.top()+'a'), sk.pop();
        else printf("Impossible");
    } else printf("Impossible");
    return 0;
}
