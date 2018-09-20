#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p;
    bool period = true;
    char input[3000];
    scanf("%d %d %s", &n, &p, input);
    for(int i = 0; i + p < n; i++){
        if(input[i] != input[i + p]){
            if(input[i] == '.'){
                input[i] = ('1' - input[i + p]) + '0';
            } else if(input[i + p] == '.'){
                input[i + p] = ('1' - input[i]) + '0';
            }
            period = false;
            break;
        }else if(input[i] == '.'){
            input[i] = '1';
            input[i + p] = '0';
            period = false;
            break;
        }
    }
    if(!period){
      for(int i = 0; i < n; i++) if(input[i] == '.') input[i] = '0'; //Para rellenar los puntos faltantes
      printf("%s", input);
    }
    else printf("No");
    return 0;
}