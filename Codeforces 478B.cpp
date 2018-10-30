#include <bits/stdc++.h>

using namespace std;

long long int comb(long long int n){
    return (n * (n - 1))/2;
}

int main(){
    long long int m, n, kmax, kmin;
    scanf("%lld %lld", &n, &m);
    kmax = comb(n - m + 1);
    kmin = (m - n%m) * comb(n/m) + n%m * comb(n/m + 1);
    printf("%lld %lld", kmin, kmax);
    return 0;
}
/*
    Es un problema de combinatoria, para el caso de los pares maximo tenemos que primero repartimos 1 integrante para
    cada grupo, tomamos de ejemplo n = 6 y m = 3: 1 - 1 - 1, luego, colocamos los demas integrantes en un solo equipo
    obteniendo asi 1 - 1 - 4 y kmax = 6. Para kmin lo que tenemos que hacer es distribuir equitativamente mientras se
    pueda y luego tener en cuenta el resto que no se pudo distribuir equitativamente, siguiendo el ejemplo anterior
    tenemos: 2 - 2 - 2 y kmin = 3.
*/