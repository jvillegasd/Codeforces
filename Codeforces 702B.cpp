#include <stdio.h>
#include <map>

using namespace std;

int main(){
    long long n, cont = 0;
    int power[30];
    map<long long, int> ansMap;
    power[0] = 2;
    for(int i = 1; i < 30; i++) power[i] = 2*power[i-1];
    scanf("%lld", &n);
    long long arr[n];
    for(long long i = 0; i < n; i++) scanf("%lld", &arr[i]), ansMap[arr[i]] +=1;
    for(long long i = 0; i < n; i++){
        ansMap[arr[i]] -= 1;
        for (int j = 0; j < 30; j++){
            cont += ansMap[power[j] - arr[i]];
        }
    }
    printf("%lld\n", cont);
    return 0;
}
/*
    Lo que primero uno puede pensar es sacar logaritmos para tratar de hallar un exponente tal que si este es entero
    esa suma vendria siendo potencia de 2, esto implicaria sumar los pares posibles y conlleva mucha complejidad O(n^2),
    sin embargo, el codeforces no resuelve bien este tipo de solucion, entonces hay que plantear diferente la solucion,
    en vez de buscar el exponente, se va a buscar una parte de i-th pareja, entonces la ecuacion a usar seria: 
    2^x - ai = aj, si se encuentra aj en el vector dado, esto significaria que la pareja existe.
*/