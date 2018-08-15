#include <stdio.h>

using namespace std;

bool marked[1000100];
int sumPrime[1000100];

void sieveOfEratosthenes(){
    marked[0] = marked[1] = 1;
    for(int i = 2; i <= 1000090; i++){
        if(!marked[i]){
           for(int j = i + i; j <= 1000090; j+=i) marked[j] = true; 
        }
    }
    sumPrime[0] = 0;
    for(int i = 1; i <= 1000090; i++) {
        if(!marked[i]) sumPrime[i] = sumPrime[i - 1] + 1;
        else sumPrime[i] = sumPrime[i - 1];
    }
}

bool checkInterval(int a, int b, int l, int k){
    for(int i = a; i <= b - l + 1; i++) if(sumPrime[i + l - 1] - sumPrime[i - 1] < k) return false;
    return true;
}

void binarySearch(int a, int b, int k){
    int l = 1, r = b - a + 1, mid;
    while(r >= l){
        mid = (l + r)/2;
        if(checkInterval(a, b, mid, k)) r = mid - 1;
        else l = mid + 1;
    }
    if(l <= b - a + 1) printf("%d\n", l);
    else printf("-1\n");
}

int main(){
    sieveOfEratosthenes();
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    binarySearch(a, b, k);
    return 0;
}
/*
    En realidad es un ejercicio de implementación, lo unico que me mantuvo pensando fué el como hallar los primos en un
    intervalo, ya que seria muy ineficiente calcular si un numero es primo cada vez que verificaba, por lo que aprendí
    algo nuevo y es el metodo de eratostenes para calcular los primos con O(nlog(log(n))).
*/