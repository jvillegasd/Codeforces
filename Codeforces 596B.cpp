#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int n;
    long long sum;
    scanf("%d",&n);
    int b[n];
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    sum = abs(b[0]);
    for(int i = 1; i < n; i++) sum+=abs(b[i]-b[i-1]);
    printf("%lld\n", sum);
    return 0;
}