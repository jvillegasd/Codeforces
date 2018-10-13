#include <bits/stdc++.h>

using namespace std;

int s(long long int x) {
    int sum = 0;
    while(x) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main(){
    long long int n, root = -1;
    scanf("%lld", &n);
    for(int i = 1; i <= 81; i++){
        long long int x = (sqrt(i*i+4*n)-i)/2;
        int sx = s(x);
        if(x*x+sx*x-n == 0){
            root = x;
            break;
        }
    }
    printf("%lld", root);
    return 0;
}
/*
    Para resolver el problema facilmente hay que hacer un pequeño analisis. Primero, tenemos que n<=10^18, pero
    a la vez tenemos que x^2<=n, por lo que x<=10^9. Si nos vamos a S(x), tenemos que el peor caso es:
    S(999999999) = 9*9 = 81, entonces, solo nos queda es buscar por fuerza bruta el valor de la ecuacion.
*/