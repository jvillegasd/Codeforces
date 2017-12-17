#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int alpha[26] = {0};
    int k;
    char input[1010];
    string ans = "";
    bool possible = true;
    scanf("%d %s", &k, &input);
    for(int i = 0; input[i]; i++) alpha[input[i] - 'a']+=1;
    for(int i = 0; i < 26; i++){
        if(alpha[i] % k != 0){
            possible = false;
            break;
        }
    }
    for(int i = 0; i < 26 && possible; i++){
        for(int j = 0; j < alpha[i] / k; j++) ans += ('a' + i);
    }
    for(int i = 1; i <= k && possible; i++) cout << ans;
    if(!possible) printf("-1\n");
    return 0;
}
/*
    La estrategia a usar es guardar las ocurrencias de cada letra, luego, verificar si las ocurrencias son multiplos
    de la "k" recibida, sino, significa que no se puede representar de "k" manera. Luego de esto generar una string
    que al concatenarla "k" veces sea la representacion pedida. alpha[i]/k es cuantas veces va aparecer la
    letra en la string generada para que luego de concatenarla "k" veces, esten todas las ocurrencia de esa letra.
*/