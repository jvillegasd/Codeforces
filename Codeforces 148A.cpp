#include <stdio.h>

using namespace std;

int main(){
    int k, l, m, n, d, cont = 0;
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    if(k == 1 || l == 1 || m == 1 || n == 1) printf("%d\n", d);
    else{
        for(int i = 1; i <= d; i++){
            if(i%k!= 0 && i%l!= 0 && i%m!= 0 && i%n!= 0) cont++;
        }
        printf("%d\n", d - cont);
    }
    return 0;
}
/*
    La estrategia es contar los numeros que no son divisibles entre "k, l, m y n" y al final se le resta a "d", se cuenta
    esos numeros ya que son los dragones que se escapan.
*/