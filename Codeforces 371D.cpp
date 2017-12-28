#include <stdio.h>
#include <math.h>

using namespace std;

int vessels[200010] = {0}, capacity[200010], nextV[200010], n;

void addWater(int p, int x){
    int i = nextV[p], delta;
    if(i > n) return;
    while(i < n){
        delta = abs(capacity[i] - vessels[i]);
        if(x <= delta){
            vessels[i]+=x;
            break;
        }
        x-=delta, vessels[i] = capacity[i], i++;
    }
    for(int j = i - 1; j >= nextV[p]; j--) nextV[j] = i;
}

int main(){
    int m, x, p, k, query;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &capacity[i]), nextV[i] = i;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &query);
        if(query == 1){
            scanf("%d %d", &p, &x);
            addWater(p - 1, x);
        }else{
            scanf("%d", &k);
            printf("%d\n", vessels[k - 1]);
        }
    }
    return 0;
}
/*
    La unica estrategia que use fue por motivos de evitar TLE (porque cuando lo probaba quedaba tildado) y para eso uso 
    un vector que me mantiene los indices siguientes a un recipiente, es decir, en caso dado de que un recipiente 
    este lleno este vector en la posicion de este recipiente lleno va a guardar la posicion del recipiente mas cercano 
    en donde puedan echar el agua faltante.
*/