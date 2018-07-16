#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int problems[n], aux[n], profit = 0, last = 0;
    vector<pair<int, int>> aux1;
    vector<int> aux2;
    for(int i = 0; i < n; i++) {
        scanf("%d", &problems[i]);
        aux1.push_back(make_pair(problems[i], i + 1));
    }
    sort(aux1.begin(), aux1.end());
    for(int i = n - 1; i > n - 1 - k; i--){
        profit+=aux1[i].first;
        aux2.push_back(aux1[i].second);
    }
    sort(aux2.begin(), aux2.end());
    printf("%d\n", profit);
    if(k == 1){
        printf("%d", n);
        return 0;
    }
    for(int i = 0; i < k; i++){
        if(i == k - 1) printf("%d ", n - last); //Caso especial: el ultimo grupo se conforma con lo que quede
        else printf("%d ", aux2[i] - last);
        last = aux2[i]; 
    }
    return 0;
}
/*
    Este problema me costo entenderle el truco, la cuestion aqui es ordenar primero un vector auxilar para obtener la
    ganancia maxima y en otro vector auxilar ordenar las posiciones donde se ubican los problemas que te dan esa
    ganancia maxima. Al final con esas posiciones obtenidas solo es realizar un pequeño delta para obtener cuantos
    numeros (problemas) se encuentran en los intervalos donde estan los problemas que generan la mayor ganancia
*/