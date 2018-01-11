#include <stdio.h>

using namespace std;

int main(){
    int n, p, a, cont = 0;
    scanf("%d", &n);
    bool game[100] = {0};
    for(int i = 0; i < 2; i++){
        scanf("%d", &p);
        for(int j = 0; j < p; j++) scanf("%d", &a), game[a] = true;
    }
    for(int i = 1; i <= n; i++){
        if(game[i]) cont++;
    }
    if(cont == n) printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");
    return 0;
}