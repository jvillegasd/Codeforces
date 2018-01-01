#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool adjM[410][410];
bool visited[410] = {0};
int dist[410] = {-1};

int BFS(int n, bool railway){
    queue<int> cola;
    cola.push(1);
    dist[1] = 0;
    visited[1] = true;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        if(v == n) break;
        for(int i = 1; i <= n; i++){
            if(!visited[i] && adjM[v][i] == railway){
                cola.push(i);
                dist[i] = dist[v] + 1;
                visited[i] = true;
            }
        }
    }
    if(!visited[n]) return -1;
    return dist[n];
}

int main(){
    int n, m, u, v;
    bool railway = true;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adjM[u][v] = adjM[v][u] = 1;
    }
    if(adjM[1][n]) railway = false;
    printf("%d\n", BFS(n, railway));
    return 0;
}