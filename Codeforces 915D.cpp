#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> graph[100005];
int n, m, inDegree[505], cpyDegree[505];

bool topologicalSort(){ //Kahn's Topological sort
    int visitedNode = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) if(inDegree[i] == 0) q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visitedNode++;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }
    return visitedNode == n;
}

int main(){
    int u, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        inDegree[v]++;
        cpyDegree[v]++;
    }
    if(topologicalSort()){ //Verificar de que ya sea DIG
        printf("YES"); 
        return 0;
    }else{
        for(int i = 1; i <= n; i++){
            memcpy(inDegree, cpyDegree, sizeof(cpyDegree));
            if(inDegree[i] >= 1){
                inDegree[i]--; //Simular la eliminacion de la arista que crea el ciclo
                if(topologicalSort()){
                    printf("YES");
                    return 0;
                }
            }
        }
    }
    printf("NO");
    return 0;
}
/*
    Aprendi mucho sobre el DFS y varias de sus propiedades con este problema, fue muy productivo, sobre todo el aprender
    como funciona el topological sort. Bueno, la estrategia es en apoyarnos en las ventajas que nos da el topological sort
    y avergüar si se le puede realizar este ordenamiento, sino, empezar a simular que le quitamos una arista a cada nodo
    y a su vez realizar este ordenamiento para ver si ya es un DIG o no. Si al quitarle una arista no se llega al DIG,
    quiere decir que existe mas de un ciclo que cierra en ese nodo o que este se encuentra en otro.
*/