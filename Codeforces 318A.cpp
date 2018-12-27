#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n, k;
    scanf("%lld %lld", &n, &k);
    if(k <= n/2 + n%2) printf("%lld", 2*k-1);
    else printf("%lld", 2*(k - (n/2 + n%2)));
    return 0;
}