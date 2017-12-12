#include <stdio.h>

using namespace std;

int main(){
    int k2, k3, k5, k6, sum = 0;
    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
    while(k2 > 0 && k5 > 0 && k6 > 0){
        k2--;
        k5--;
        k6--;
        sum += 256;
    }
    while(k2 > 0 && k3 > 0){
        k2--;
        k3--;
        sum += 32;
    }
    printf("%d\n", sum);
    return 0;
}