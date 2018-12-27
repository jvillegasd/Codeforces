#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc, a;
    float n;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &a);
        n = 2.00/(1.00-a/180.00);
        if((int)(n * 100) % 100 == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
    Para hallar el angulo interior de un poligono regular con n lados se usa:
                                        b = 180 * (n - 2)/n
    Despejando n tenemos que:
                                        n = 2/(1 - b/180)
    Entonces, el poligono es regular si n es entero.
*/