#include <bits/stdc++.h>
typedef long long int lli;

using namespace std;

int main(){
    lli n, m, a, sum = 0;
    vector<lli> exhibit;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a), exhibit.push_back(a), sum+=a;
    sort(exhibit.begin(), exhibit.end());
    lli highestH = 0;
    for(int i = 0; i < n; i++) highestH = min(highestH + 1, exhibit[i]);
    printf("%lld", sum - (n + (exhibit[n - 1] - highestH)));
    return 0;
}
/*
    Para resolver este problema, hay que ordenar el vector de manera ascendente primero. Si nos damos cuenta,
    a medida que iteramos por las pilas, los bloques de la pila i-1 actuan como vista para el lado derecho
    de la camara, por lo que podemos eliminar el equivalente en bloques (si se puede) de la i-esima pila.
    Si se dibuja, se notara un patron de crecimiento de esos bloques que pueden ser eliminados, ese patron
    esta representado con el aumento en 1 de la variable "highestH", cuando se encuentre la altura minima de
    bloques que se pueden eliminar, esta se le resta a la pila con mayor cantidad de bloques para obtener
    los bloques que no se deben eliminar, luego se suman a los "n" bloques minimos para luego hallar la 
    respuesta.
*/