#include <stdio.h>

using namespace std;

int main(){
    int n, m, i=0, j=0, cont=0;
    scanf("%d %d", &n, &m);
    int games[n], wallet[m];
    for(int k = 0; k < n; k++) scanf("%d", &games[k]);
    for(int k = 0; k < m; k++) scanf("%d", &wallet[k]);
    while(i < n && j < m){
        if(wallet[j] >= games[i]){
            j++;
            cont++;
        }
        i++;
    }
    printf("%d", cont);
    return 0;
}