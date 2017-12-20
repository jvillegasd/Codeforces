#include <stdio.h>

using namespace std;

int main(){
    int even = 0, odd = 0, n, number;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &number);
        if(number % 2 == 0) even++;
        else odd++;
    }
    if(odd % 2 == 1) printf("%d\n", odd);
    else printf("%d\n", even);
    return 0;
}
/*
    Un problema demasiado sencillo, la estrategia a usar es sumar cuantos numeros pares e impares hay en la input, como
    solo se va a robar una bolsa, entonces esos contadores van a representar las maneras que se puede roban una bolsa.
    Lo demas viene recordando reglas matematicas, si hay una cantidad par de numeros impares es obvio que su suma es
    un numero par, por lo que imprimiriamos cuantos numero pares posee la input, en cambio si no hay una cantidad par
    de numeros impares, entonces es obvio decir que hay que quitar una bolsa impar para que la suma sea par, por lo
    que imprimiriamos la cantidad de impares
*/