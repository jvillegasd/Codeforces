#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string inp;
    cin >> inp;
    bool winner;
    stack<char> s;
    for(int i = 0; i < inp.length(); i++){
        if(s.empty() || s.top() != inp[i]) s.push(inp[i]);
        else winner=!winner, s.pop();
    }
    if(winner) printf("Yes");
    else printf("No");
    return 0;
}