#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, readed = 0;
    scanf("%d %d", &n, &t);
    int books[n + 2];
    books[0] = 0;
    for(int i = 1 ; i <= n; i++){
        scanf("%d", &books[i]);
        books[i]+=books[i - 1]; //Array de suma para aplicar Binary Search
    }
    for(int i = 0; i < n; i++){
        int l = i + 1, r = n, mid;
        while(l <= r){
            mid = (l + r)/2;
            if(books[mid] - books[i] <= t) l = mid + 1; //Maximizar numero de libros
            else r = mid - 1;
        }
        readed = max(l - i, readed);
    }
    printf("%d", readed - 1);
    return 0;
}
/*
    Problema algo raro, al principio lo habia entendido mal, la gracia aqui es que solo puedes calcular sumando el tiempo
    desde el libro i hasta i + k, donde k es el numero de libros maximo que puedes leer en el tiempo t. Si lo hacia a
    fuerza bruta obtenia O(n^2), asi que opte con busqueda binaria que me da en total O(nlogn).
    La busqueda binaria la hago en un array de suma donde la i-esima posicion me guarda el tiempo total de libros leidos
    desde el primer hasta el i-esimo libro, entonces, trato de buscar cual es el maximo intervalo donde puedo leer
    de seguido.
*/