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

int main(){
    BOOST;
    map<char,string> tabla;
    tabla['2']="2";
    tabla['3']="3";
    tabla['4']="322";
    tabla['5']="5";
    tabla['6']="53";
    tabla['7']="7";
    tabla['8']="7222";
    tabla['9']="7332";
    string inp, ans;
    int n;
    cin >> n;
    cin >> inp;
    for(int i = 0; i < n; i++) if(inp[i] != '0' || inp[i] != '1') ans+=tabla[inp[i]];
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans;
    return 0;
}