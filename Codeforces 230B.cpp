#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

bool prime[1000010];

void sieveOfErathostenes(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i < 1000010; i++){
        if(prime[i]){
            for (int j = 2*i; j < 1000010; j+=i) prime[j] = false;
        }
    }
}

int main(){
    sieveOfErathostenes();
    long long int n;
    cin >> n;
    long long int array[n];
    for(int i = 0; i < n; i++) cin >> array[i];
    for(int i = 0; i < n; i++){
        int square = (int)sqrt(array[i]);
        if(square - sqrt(array[i]) == 0){
            if(prime[square]) printf("YES\n");
            else printf("NO\n");
        }else printf("NO\n");
    }
    return 0;
}
/*
    La estrategia es usar la criba de eratostenes y apoyarse del teorema fundamental de la aritmetica.
    Primero, teniendo en cuenta el teorima antes mencionados, se puede presentar de que un numero sea
    simplemente representado como x^2 donde x es un numero primo, esto quiere decir de que los T-primos
    seran aquellos numeros que sean un numero primo elevado a la dos para que pueda tener exactamente 3
    divisores
*/