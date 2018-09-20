#include <bits/stdc++.h>

using namespace std;

int d[1001000];

void divisors(){
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j+=i) d[j]++;
    }
}

int main(){
    divisors();
    int a, b, c;
    long long int sum = 0;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++) sum+=d[i * j * k];
        }
    }
    printf("%lld", sum);
    return 0;
}