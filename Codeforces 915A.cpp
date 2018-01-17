#include <stdio.h>

using namespace std;

int main(){
    int n, k, max = -1, input;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        if(input <= k && k % input == 0 && input > max) max = input;
    }
    if(k != 1) printf("%d\n", k/max);
    else printf("1\n");
    return 0;
}