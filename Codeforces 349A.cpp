#include <stdio.h>

using namespace std;

int main(){
    int n, change[3] = {0}, money;
    bool no = false;
    scanf("%d", &n);
    while(n-- > 0){
        scanf("%d", &money);
        if(money == 25) change[0]++;
        else if(money == 50) change[0]--, change[1]++;
        else if(money == 100){
            change[2]++;
            if(change[1] > 0) change[1]--, change[0]--;
            else change[0] -= 3;
        }
        if(change[0] < 0){
            printf("NO\n"), no = true;
            break;
        }
    }
    if(!no) printf("YES\n");
    return 0;
}
/*
    La mecanica aqui es simular una caja registradora y guardar los billetes de 25 tanto como sea posible, 
    ya que se usa para dar cambio al billete de 50 y de 100, procurar gastar prioritariamente el billete de 50.
*/