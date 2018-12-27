#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n, x, d, kid = 0;
    char c;
    scanf("%lld %lld", &n, &x);
    for(int i = 0; i < n; i++){
        scanf(" %c %lld", &c, &d);
        if(c == '+') x+=d;
        else{
            if(x - d >= 0) x-=d;
            else kid++;
        }
    }
    printf("%lld %lld", x, kid);
    return 0;
}