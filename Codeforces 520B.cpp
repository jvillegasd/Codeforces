#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int BFS(int n, int m){
    queue<int> cola;
    int clicks[10010];
    memset(clicks, -1, sizeof(clicks));
    clicks[n] = 0;
    cola.push(n);
    while(!cola.empty()){
        int number = cola.front();
        cola.pop();
        if(number == m) return clicks[number];
        else{
            if(2 * number <= 10000 && clicks[2 * number] == -1){
                clicks[2 * number] = clicks[number] + 1;
                cola.push(2 * number);
            }
            if(number - 1 >= 0 && clicks[number - 1] == -1){
                clicks[number - 1] = clicks[number] + 1;
                cola.push(number - 1);
            }
        }
    }
    return 0;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n > m) printf("%d\n", n - m);
    else printf("%d\n", BFS(n, m));
    return 0;
}