#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int timeP[5], number, n, k, cont = 0;
    memset(timeP, 0, sizeof(timeP));
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d", &number);
        timeP[number]+=1;
    }
    for(int i = 0; i <= 5; i++){
        if(i + k <= 5) cont+=timeP[i];
        else break;
    }
    printf("%d", cont/3);
    return 0;
}