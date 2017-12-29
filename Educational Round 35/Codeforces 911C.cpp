#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int k[4];
    for(int i = 0; i < 3; i++) scanf("%d", &k[i]);
    sort(k, k + 4);
    if(k[0]==1 || (k[0]==2 && k[1]==2) || (k[0]==3 && k[1]==3 && k[2]==3) || (k[0]==2 && k[1]==4 && k[2]==4)){
        printf("YES\n");
    } else printf("NO\n"); 
    return 0;
}
/*
    La estrategia es no dejarse engañar por el valor que puede tomar "ki", las unicas posibilidades para que almenos
    un foco este encendido cada segundo son esas, si no alcazan a ver el porque entonces has prueba de escritorio,
    eso si, teniendo en cuenta: 1 <= x <= 3 para no hacer tanto calculo.
*/