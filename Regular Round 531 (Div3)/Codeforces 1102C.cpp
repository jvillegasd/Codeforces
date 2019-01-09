#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y, a[110], ans = 0;
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] <= x) ans++;
    }
    if(x > y) printf("%d", n);
    else printf("%d", ans/2 + ans%2);
    return 0;
}
/*
    Notese que para maximizar las puertas dañadas solo se tendran en cuenta las que bi <= x, entonces, como "y"
    busca minimizar la cantidad de puertas dañadas, mientras "x" destruye una puerta, "y" se sube la vitalidad a otras.
*/