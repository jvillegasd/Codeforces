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
    int n, k, maxi = 0, cont, len;
    string inp;
    scanf("%d %d", &n, &k);
    cin >> inp;
    for(char l = 'a'; l <= 'z'; l++){
        cont = len = 0;
        for(int i = 0; i < n; i++){
            if(inp[i] == l) len++;
            if(len == k) cont++, len = 0;
            if(inp[i] != l) len = 0;
        }
        maxi = max(maxi, cont);
    }
    printf("%d", maxi);
    return 0;
}