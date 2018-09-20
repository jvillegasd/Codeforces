#include <bits/stdc++.h>

using namespace std;

int x[20000], y[20000], n;
bool visited[20000];

void DFS(int i){
    visited[i] = true;
    for(int j = 1; j <= n; j++){
        if(!visited[j] && (x[i] == x[j] || y[i] == y[j])) DFS(j);
    }
}

int main(){
    int unvisited = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
            unvisited++;
        }
    }
    printf("%d", unvisited - 1);
    return 0;
}
/*
    La estrategia en este problema es de ir visitando cada punto que se pueda, osea, teniendo en cuenta si los puntos
    son iguales en x o y. Ir ejecutando DFS en cada punto e ir contando los que marcan no visitado porque ahi se puede
    poner un nuevo punto, a la final, la respuesta solo es lo que contaste menos 1.
*/