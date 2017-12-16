#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int a, b , c, ans;
    scanf("%d %d %d", &a, &b, &c);
    ans = a + b + c;
    ans = max(ans, a * (b + c));
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * b * c);
    printf("%d\n", ans);
    return 0; 
}
/*
    La estrategia es realizar todas las combinaciones posibles e imprimir el maximo valor posible.
*/