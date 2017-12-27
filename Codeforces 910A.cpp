#include <stdio.h>
#include <iostream>

using namespace std;

int DFS(int index, int d, int steps, string path){
    int newIndex = -1;
    if(index == path.size() - 1) return steps;
    else{
        for(int i = 1; i <= d; i++){
            if(path[index + i] == '1') newIndex = index + i;
        }
        if(newIndex == -1) return -1;
    }
    return DFS(newIndex, d, steps + 1, path);
}

int main(){
    int n, d;
    string path;
    char input[120];
    scanf("%d %d %s", &n, &d, &input);
    path = input;
    printf("%d\n", DFS(0, d, 0, path)); 
}
// La estrategia es usar DFS para probar todas las posibilidades de salto