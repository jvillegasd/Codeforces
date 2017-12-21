#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int n, x, sum = 0, cont = 0, number;
    scanf("%d %d", &n, &x);
    while(n--){
        scanf("%d", &number);
        sum += number;
    }
    sum = abs(sum);
    if(sum == 0) printf("0\n");
    else{
        while(sum > 0){
            sum-=x;
            cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
/*
    La estrategia a usar es ir sumando cada numero, despues de esto, si la suma no da cero procedemos a reducirla, aqui
    lo que se hace es ir restando "x" a esa suma para saber cuantos numeros faltan. Se resta "x" debido que nos piden
    el minimo de numeros necesarios y la "x" son el valor maximo que puedes tomar.
*/