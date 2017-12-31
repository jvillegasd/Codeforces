#include <stdio.h>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

const int MAXI = numeric_limits<int>::max();
vector<pair<int, int>> adjList[100010];
int parent[100010], dist[100010];
bool visited[100010] = {0};

bool dijkstra(int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    parent[1] = 0;
    visited[1] = true;
    pq.push(make_pair(dist[1], 1));
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(node == n) return true;
        visited[node] = true;
        for(int i = 0; i < adjList[node].size(); i++){
            int in = adjList[node][i].first;
            int w = adjList[node][i].second;
            if(!visited[in] && dist[in] > dist[node] + w){
                dist[in] = dist[node] + w;
                parent[in] = node;
                pq.push(make_pair(dist[in], in));
            }
        }
    }
    return false;
}

void printPath(int end){
    vector<int> path;
    for(int v = end; v!= 0; v = parent[v]) path.push_back(v);
    for(int i = path.size() - 1; i > 0; i--) printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int main(){
    int n, m, in, out, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &out, &in, &w);
        adjList[out].push_back(make_pair(in, w));
        adjList[in].push_back(make_pair(out, w));
    }
    for(int i = 1; i <= n; i++) dist[i] = MAXI;
    if(dijkstra(n)) printPath(n);
    else printf("-1");
    return 0;
}