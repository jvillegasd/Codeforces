#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b, c, DP[4010];
    scanf("%d %d %d %d", &n, &a, &b, &c);
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a <= i && DP[i - a] != -1) DP[i] = DP[i] = DP[i - a] + 1;
        if(b <= i && DP[i - b] != -1) DP[i] = max(DP[i - b] + 1, DP[i]);
        if(c <= i && DP[i - c] != -1) DP[i] = max(DP[i - c] + 1, DP[i]);
    }
    printf("%d\n", DP[n]);
    return 0;
}
/*
    La estrategia es usar DP para maximizar cuantas piezas de cinta puede cortar.
*/