#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int n, k, cont = 0, lucky;
    char input[100010];
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%s", &input);
        lucky = 0;
        for(int i = 0; input[i]; i++){
            if(input[i] == '4' || input[i] == '7') lucky++;
        }
        if(lucky <= k) cont++;
    }
    printf("%d\n", cont);
    return 0;
}