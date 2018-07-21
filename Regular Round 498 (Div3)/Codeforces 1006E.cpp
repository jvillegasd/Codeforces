#include <stdio.h>
#include <vector>

using namespace std;

vector<int> tree[200005];
int dfsArray[200005], sizeTree[200005], index[200005], timeN = 0;

int DFS(int u){
    int subTree_size = 1;
    index[u] = timeN;
    dfsArray[timeN] = u;
    timeN++;
    for(int i = 0; i < tree[u].size(); i++) subTree_size += DFS(tree[u][i]);
    sizeTree[u] = subTree_size;
    return subTree_size;
}

int main(){
    int n, q, node, u, k;
    scanf("%d %d", &n, &q);
    for(int i = 2; i <= n; i++){scanf("%d", &node); tree[node].push_back(i);}
    DFS(1);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &u, &k);
        if(sizeTree[u] < k) printf("-1\n");
        else printf("%d\n", dfsArray[index[u] + k - 1]);
    }
    return 0;
}
/*
    La estrategia fue guardar el tamaño de cada subarbol (sizeTree), la secuencia que genera el DFS si se recorre desde
    el nodo fuente (dfsArray), el indice del i-esimo nodo del dfsArray (index) y por supuesto el DFS. Se realiza DFS
    desde el nodo fuente para poder obtener la secuencia que usaremos para resolver cada caso. Siempre probamos que "k"
    sea menor o igual al tamaño del subarbol "u", ya que si no lo es significa que ese nodo que busca no existe. Para
    buscar las respuesta usamos un pequeño juego de indices en dfsArray, tomamos el indice que tiene el nodo "u" en la
    secuencia DFS, lo sumamos con "k" y le restamos "1".
*/