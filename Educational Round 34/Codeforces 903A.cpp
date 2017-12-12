#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        int DP[120];
        DP[0] = 0;
        for(int i = 1; i <= x; i++){
            DP[i] = -1;
            if(3 <= i && DP[i - 3] != -1) DP[i] = DP[i - 3] + 1;
            if(7 <= i && DP[i - 7] != -1) DP[i] = max(DP[i - 7] + 1, DP[i]);
        }
        if(DP[x] != -1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
    La estrategia es usar DP para saber cuantas porciones maximas (de 3 o 7) puede comer dado una cantidad de porcion,
    luego, ver en el vector DP si en la posicion de la porcion dada hay una cantidad maxima, si no lo hay, es
    que no puede comprar esas porciones.
*/