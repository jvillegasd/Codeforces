#include <bits/stdc++.h>
#define mod 1000000007
#define INF 2000000007

using namespace std;

vector<long long int> graph[400000];
vector<long long int> invGraph[400000];
vector<long long int> scc;
long long int cost[100100];
stack<long long int> endTimeNodes;
bool visited[100100];

void DFS(long long int u){
    visited[u] = true;
    for(long long int v : graph[u]){
        if(!visited[v]) DFS(v);
    }
    endTimeNodes.push(u);
}

void DFSSCC(long long int u){
    visited[u] = true;
    scc.push_back(u);
    for(long long int v : invGraph[u]){
        if(!visited[v]) DFSSCC(v);
    }
}

void StronglyConnectedComponents(){
    long long int sum = 0, ways = 1, count = 0, m;
    while(!endTimeNodes.empty()){
        long long int u = endTimeNodes.top();
        if(!visited[u]){
            scc.clear();
            DFSSCC(u);
            m = INF;
            count = 0;
            for(long long int i = 0; i < scc.size(); i++){
                long long int v = scc[i];
                m = min(m, cost[v]);
            }
            sum+=m;
            for(long long int i = 0; i < scc.size(); i++){
                long long int v = scc[i];
                if(cost[v] == m) count++;
            }
            ways*=(count%mod);
        }
        endTimeNodes.pop();
    }
    printf("%I64d %I64d", sum, ways % mod);
}

int main(){
    long long int u, v, n, m;
    scanf("%I64d", &n);
    for(long long int i = 1; i <= n; i++) scanf("%I64d", &cost[i]);
    scanf("%I64d", &m);
    for(long long int i = 0; i < m; i++){
        scanf("%I64d %I64d", &u, &v);
        graph[u].push_back(v);
        invGraph[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    for(long long int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }
    memset(visited, false, sizeof(visited));
    StronglyConnectedComponents();
    return 0;
}
/*
    Un problema bastante interesante de grafo. El ejercicio se hace facil si se tiene previo conocimiento sobre
    componentes fuertemente conexas. Yo uso esto ya que en el problema me dice que cada estacion puede cuidarse
    a si misma o a otras mientras que pueda volver a la union que le corresponde, tambien, tengo en cuenta esto
    debido a que las rutas en un solo sentido por lo que genera un digrafo. La estrategia es obtener las
    componentes fuertemente conexas del barrio, luego, en cada componente buscar el nodo o la union que menos
    costo tiene e ir sumandolo para obtener el costo final, para las maneras en que se puede comprar se busca
    que hallan mas uniones en la componente analizada que tenga el menor costo y contarlas, luego, multiplicarla
    en el total (recordar combinaciones para entender porque se multiplica).
*/