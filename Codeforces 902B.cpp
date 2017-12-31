#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> adjList[10100];
int colors[10100];
bool visited[10100] = {0};

int DFS(int v){
    stack<int> pila;
    pila.push(1);
    int steps = 1;
    while(!pila.empty()){
        int v = pila.top();
        pila.pop();
        visited[v] = true;
        for(int i = 0; i < adjList[v].size(); i++){
            int u = adjList[v][i];
            if(!visited[u]){
                pila.push(u);
                if(colors[v] != colors[u]) steps++;
            }
        }
    }
    return steps;
}

int main(){
    int n, v;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &v);
        adjList[i].push_back(v);
        adjList[v].push_back(i);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &colors[i]);
    printf("%d\n", DFS(1));
    return 0;
}