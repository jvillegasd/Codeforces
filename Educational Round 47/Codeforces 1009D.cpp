#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, m, e=0;
    scanf("%d %d", &n, &m);
    pair<int, int> graph[m+1];
    if(m < n - 1){ //Minimo de aristas necesarias para tener un grafo conexo
        printf("Impossible");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(e == m) break;
        for(int j = i + 1; j <= n; j++){
            if(__gcd(i, j) == 1){
                graph[e++] = make_pair(i, j);
                if(e == m) break;
            }
        }
    }
    if(e != m) printf("Impossible");
    else{
        printf("Possible\n");
        for(int i = 0; i < e; i++) printf("%d %d\n", graph[i].first, graph[i].second);
    }
    return 0;
}