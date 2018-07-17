#include <stdio.h>

using namespace std;

int main(){
    int n, m, prime = 100019, weight = 1000000000, u = 1, v = 3;
    scanf("%d %d", &n, &m);
    printf("%d %d\n", prime, prime);
    printf("1 2 %d\n", prime - (n - 2));
    for(int i = 2; i <= n - 1; i++) printf("%d %d 1\n", i, i + 1);
    for(int i = 0; i < m - (n - 1); i++){
        printf("%d %d %d\n", u, v, weight);
        v++;
        if(v > n) u++, v = u + 2;
    }
    return 0;
}
/*
    Para resolver este problema debemos tener en cuenta que tanto el MST como el shortest path siempre van a usar n - 1
    aristas, por lo que debemos preocuparnos solamente con este numero de aristas. Para asignar el peso a cada una de
    estas n - 1 aristas parti de una variable que posee un numero primo grande que denota el resultado del shortest path
    y del MST, con esto empezamos a crear nuestro grafo de la siguiente forma:
        *) Casi todas las n - 1 aristas tendran peso de 1 y solo una tendra un peso de "prime - (n - 2)", donde "prime" 
        es el numero primo mencionado anteriormente. Todo esto con motivo de garantizar el MST y el shortest path con 
        suma de pesos impar, es decir, nosotros estamos construyendo un grafo que cumpla con el numero primo.
        *) Para las aristas faltantes solo es asignarle un peso lo suficientemente grande como para que no se tenga
        en cuenta al momento del calcular el MST y el shortest parh
*/