#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long int quickPow(long long int a, long long int e){
    long long int ans = 1;
    while(e > 0){
        if((e&1) == 1) ans=(ans*a)%mod;
        a = (a*a)%mod;
        e >>= 1;
    }
    return ans;
}

int main(){
    string input;
    long long int ans = 0, num, dem, k, n;
    cin >> input >> k;
    n = input.size();
    num = (quickPow(2, k*n)%mod-1) % mod; //2^(k * n) - 1
    dem = (quickPow(2, n)-1)%mod; //2^n - 1
    dem = quickPow(dem, mod - 2); //Simular el inverso de dem
    for(long long int i = 0; i < n; i++) if(input[i] == '0' || input[i] == '5') ans = (ans+quickPow(2, i))%mod;
    ans = ((ans*num)%mod*dem%mod)%mod;
    printf("%lld", ans);
    return 0;
}
/*
    Es un problema de combinatoria, no voy a mentir, tuve que mirar un poco el tutorial para poder sacar la solucion
    optima. Empecemos a analizar: Tenemos que hallar todas las posibles maneras en la cual al eliminar digitos
    de la string obtengamos un numero divisible entre 5. Entonces, un numero es divisible entre 5 si y solo si el
    ultimo digito es 0 o 5, por lo que empezariamos a buscar las posiciones en la cual esten el 5 o 0. Cada vez que
    encontremos uno de estos numeros supondremos que ese sera el digito final de nuestro numero, entonces, tendremos 
    que eliminar todos los digitos a lado derecho de este pero en la parte izquierda no. Teniendo en cuenta lo dicho 
    anteriormente respecto a la composicion de un numero divisible entre 5, entonces, cada digito a lado izquierdo 
    del 5 o 0 encontrado tiene 2 opciones, que se elimine o no y así sucesivamente hasta la posicion i-1, de aqui 
    obtenemos la siguiente ecuacion:
                            2 * 2 * ... * 2 * (i - 1) = Prod j <- 0 hasta i de 2 = 2^i
    Y esto se repite por cada 5 o 0 encontrado, por lo que habria que sumar estas potencia para encontrar la solucion.
    Al finalizar este proceso, hay que extender el resultado para cada concatenacion, y para eso tenemos en cuenta que
    si en la i-esima posicion de la string original, la demas posiciones de las concatenaciones seria:
                    i, i + n, i + 2 * n, ..., i + (k - 1) * n, donde k es el numero de concatenaciones
    Ahora, extendiendo esto a la solucion parcial tendriamos que para cada 5 o 0 encontrado se hace:
                    2^i + 2^(i + n) + 2^(i + 2 * n) + 2^(i + 3 * n) + ... + 2^(i + (k - 1) * n)
                    2^i * (2^0 + 2^n + 2^(2 * n) + 2^(3 * n) + ... + 2^((k - 1) * n))
    Entonces, sacando un factor comun podemos obtener una expresion que se multiplicaria luego de obtener la
    sumatoria de las potencias:
                    Factor = 2^0 + 2^n + 2^(2 * n) + 2^(3 * n) + ... + 2^((k - 1) * n)
                    Factor = Sum i <- 0 hasta k - 1 de 2^(i * n) = (2^(k * n) - 1)/(2^n - 1)
*/