#include <stdio.h>

using namespace std;

int main(){
    int n, d, timeS, sum = 0;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
        scanf("%d", &timeS);
        sum += timeS;
    }
    if(sum + 10*(n-1) <= d) printf("%d\n", (d-sum)/5);
    else printf("-1\n");
    return 0;
}