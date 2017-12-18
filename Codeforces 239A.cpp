#include <stdio.h>

using namespace std;

int main(){
    int x = 1, n, y, k;
    bool found = false;
    scanf("%d %d %d", &y, &k, &n);
    while(x * k <= n){
        if(x * k > y){
            found = true;
            printf("%d ", x * k - y);
        }
        x++;
    }
    if(!found) printf("-1\n");
    return 0;
}