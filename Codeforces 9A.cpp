#include <bits/stdc++.h>

using namespace std;

int main(){
    int y, w, g, gcd;
    scanf("%d %d", &y, &w);
    g = max(y, w);
    gcd = __gcd(7 - g, 6);
    if(7 - g == 6) printf("1/1");
    else printf("%d/%d", (7 - g) / gcd, 6 / gcd);
    return 0;
}