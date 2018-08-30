#include <stdio.h>

using namespace std;

int main(){
    int n, lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    scanf("%d", &n);
    for(int i = 0; i < 14; i++){
        if(!(n % lucky[i])){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}