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
int g[5][5];
int flag = 0, num;

int main(){
    BOOST;
    string inp;
    for(int i = 0; i < 4; i++){
        cin >> inp;
        for(int j = 0; j < 4; j++) g[i][j] = (inp[j] == '#')? 1 : 0;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            num = g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1];
            if(num == 3 || num == 4 || 4 - num == 3 || 4 - num == 4) flag = 1;
        }
    }
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}