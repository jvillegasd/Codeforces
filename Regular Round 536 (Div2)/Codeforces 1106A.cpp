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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

int main(){
    BOOST;
    int n, ans = 0;
    string inp;
    vector<string> mapa;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> inp, mapa.pb(inp);
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < n - 1; j++){
            if(mapa[i][j]=='X')
                if(mapa[i-1][j-1]==mapa[i][j])
                    if(mapa[i-1][j+1]==mapa[i-1][j-1])
                        if(mapa[i+1][j-1]==mapa[i-1][j+1])
                            if(mapa[i+1][j+1]==mapa[i+1][j-1]) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}