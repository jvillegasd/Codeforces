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
struct node{
    int i, j, t;
};
char g[1100][1100];
int d[1100][1100], dj[4] = {1, -1, 0, 0}, dk[4] = {0, 0, 1, -1};

int main(){
    int n, m, p, speed[11], cont[11]={0}, turn = 0;
    bool emp;
    queue<node> pos[11];
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= p; i++) scanf("%d", &speed[i]);
    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 0; j < m; j++){
            scanf("%c", &g[i][j]);
            d[i][j] = INT_MAX;
            if('1' <= g[i][j] && g[i][j] <= '9'){
                pos[g[i][j] - '0'].push({i, j, turn});
                cont[g[i][j] - '0']++;
                d[i][j] = 0;
            }
        }
    }
    while(1){
        emp = true;
        for(int i = 1; i <= p; i++){
            while(!pos[i].empty() && pos[i].front().t == turn){
                int j = pos[i].front().i, k = pos[i].front().j;
                pos[i].pop();
                for(int l = 0; l < 4; l++){
                    int nj = j + dj[l], nk = k + dk[l];
                    if(nj < 0 || nj >= n || nk < 0 || nk >= m) continue;
                    if(g[nj][nk] == '.' && d[j][k] + 1 < d[nj][nk]){
                        emp = false;
                        d[nj][nk] = d[j][k] + 1;
                        g[nj][nk] = i + '0';
                        cont[i]++;
                        if(d[nj][nk] < speed[i]) pos[i].push({nj, nk, turn});
                        else{
                            pos[i].push({nj, nk, turn + 1});
                            d[nj][nk] = 0;
                        }
                    }
                }
            }
        }
        if(emp) break;
        turn++;
    }
    for(int i = 1; i <= p; i++) printf("%d ", cont[i]);
    return 0;
}