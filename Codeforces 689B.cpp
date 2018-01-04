#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <limits>

using namespace std;

vector<int> adjList[200010];
int INF = numeric_limits<int>::max();

void BFS(int start, int n){
    int dist[n];
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;
    queue<int> cola;
    cola.push(start);
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int i = 0; i < adjList[v].size(); i++){
            int u = adjList[v][i];
            if(dist[u] == INF){
                dist[u] = dist[v] + 1;
                cola.push(u);
            }
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", dist[i]);
}

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        adjList[i].push_back(i + 1);
        adjList[i + 1].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        adjList[i].push_back(m);
    }
    BFS(1, n);
    return 0;
}