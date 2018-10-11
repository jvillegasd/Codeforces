#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc, s, a, b, c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d %d %d", &s, &a, &b, &c);
        long long int choco = s/c, chocoBuy = 0, freeC = 0, total;
        chocoBuy = (choco/a)*a;
        freeC = (choco/a)*b;
        if(chocoBuy > choco) chocoBuy-=a, freeC-=b;
        total = chocoBuy + freeC;
        if(choco - chocoBuy) total+=choco - chocoBuy; 
        printf("%lld\n", total);
    }
    return 0;
}