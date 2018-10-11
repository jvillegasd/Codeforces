#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    long long int max;
    long long int min = (n - 2*m > 0)?n-2*m:0;
    for(int i = 0; i <= n; i++){
        if((long long int)i*(i-1)/2 >= m){
            max = n - i;
            break;
        }
    }
    if(m == 0) min = max = n;
    printf("%lld %lld\n", min, max);
    return 0;
}