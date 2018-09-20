#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, rounds = 0;
    scanf("%d %d %d", &n, &a, &b);
    a--;
    b--;
    while(a != b){ //El dividir entre 2 indica el numero del encuentro que jugaran
        a/=2;
        b/=2;
        rounds++;
    }
    if(rounds == log2(n)) printf("Final!");
    else printf("%d", rounds);
    return 0;
}
/*
    PD: Si no se entiendo lo que quize decir con el comentario anterior, intenta armar el arbol del torneo y traza
    lineas divisorias entre cada encuentro.
*/