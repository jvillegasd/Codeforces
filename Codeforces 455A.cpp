#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int n, number;
    long long int freq[1000000], DP[1000000];
    memset(freq, 0, sizeof(freq));
    memset(DP, 0, sizeof(DP));
    scanf("%d", &n);
    while(n--){
        scanf("%d", &number);
        freq[number]+=1;
    }
    DP[0] = 0; //Caso inicial
    DP[1] = freq[1]; //Caso inicial 2, caso cuando la input esta formado por 0 y 1.
    for(int i = 2; i <= 1000000; i++){
        DP[i] = max(DP[i - 1], DP[i - 2] +   i * freq[i]);
    }
    printf("%lld\n", DP[1000000]);
    return 0;
}
/*
    Un problema complicado para mi, creo que es porque soy muy novato en DP, tuve que resolverlo con ayuda.
    La estrategia a usar es DP, es un problema de optimizacion, si analizamos bien los ejemplos nos damos cuenta
    que la maxima cantidad de puntos posibles lo tienen los numeros que aparecen mas veces en la input, por lo que 
    tenemos que contar cuantas veces aparece un numero en la input. Como siempre el vector DP contiene los puntos
    optimos para los subproblemas, lo dificil es hallar la formula para atacar el ejercicio. Si observamos con los
    ejemplos nos damos cuenta de dos posibilidades: si escogemos un numero o no, es mas facil explicarlo con el
    for-loop del DP. Cada "i" tiene dos posibilidades, si es escogida o no:
    1) Si "i" fue escogida quiere decir que los puntos ganados serian freq[i]*i + DP[i - 2], porque DP[i - 2]?, es
    por las reglas (Si tomas un numero "i", entonces se eliminan del vector todos los numero "i" + 1 e "i" - 1), eso
    quiere decir que los puntos optimos de DP[i - 1] no los tenemos en cuenta porque son eliminados.
    2) Si "i" no fue escogida toca tomar DP[i - 1] porque "i" por las reglas seria eliminada.
*/