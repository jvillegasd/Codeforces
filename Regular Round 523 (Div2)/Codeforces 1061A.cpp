#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, s, sum = 0;
    scanf("%lld %lld", &n, &s);
    if(n >= s) printf("1\n");
    else{
        while(s > n){
            s-=n;
            sum++;
        }
        sum++;
        printf("%lld\n", sum);
    }
    return 0;
}