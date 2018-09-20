#include <bits/stdc++.h>

using namespace std;

int divisors[3500]={0};

void sieve(){
    divisors[0]=divisors[1]=1;
    for(int i = 2; i <= 3000; i++){
        if(divisors[i] == 0) for(int j = i; j <= 3000; j+=i) divisors[j]++;
    }
}

int main(){
    int n, count = 0;
    sieve();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) if(divisors[i] == 2) count++;
    printf("%d", count);
    return 0;
}