#include <stdio.h>

using namespace std;

int removeZero(int n){
    int number = 0, power = 1;
    while(n > 0){
        int mod = n % 10;
        if(mod != 0){
            number += power * mod;
            power *= 10;
        }
        n /= 10;
    }
    return number;
}

int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a + b;
    a = removeZero(a);
    b = removeZero(b);
    c = removeZero(c);
    if(a + b == c) printf("YES\n");
    else printf("NO\n");
    return 0;
}