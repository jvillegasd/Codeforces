#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int a, b, cont;  
    scanf("%d %d", &a, &b);
    while(a >= 1 && b > 1 || a > 1 && b >=1){
        if(a <= b){
            a+=1;
            b-=2;
        }else{
            b+=1;
            a-=2;
        }
        cont++;
    }
    printf("%d", cont - 1);
    return 0;
}
//No se porque pero Codeforces solo me da AC si resto al contador