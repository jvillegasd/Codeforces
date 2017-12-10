#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    bool degenerate = true;
    scanf("%d", &n);
    int segments[n];
    for(int i = 0; i < n; i++) scanf("%d", &segments[i]);
    sort(segments, segments + n);
    for(int i = 1; i < n - 1; i++){
        if(segments[i - 1] + segments[i] > segments[i + 1]){
            degenerate = false;
            break;
        }
    }
    if(!degenerate) printf("YES\n");
    else printf("NO\n");
    return 0;
}
/*
    Si se tiene un triangulo con lados: x <= y <= z,
    un triangulo degenerado es igual si se cumple esto: x + y = z,
    en cambio el triangulo no degenerado o el normalito es igual a: 
    x + y > z, es por eso que organizo el vector, para obtener segmentos
    tipo: x <= y <= z.
*/