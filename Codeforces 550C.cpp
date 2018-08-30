#include <string>
#include <iostream>

using namespace std;


int main(){
    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        for(int j = i + 1; j < input.length(); j++){
            for(int k = j + 1; k < input.length(); k++){
                int numi = input[i] - '0';
                int numj = input[j] - '0';
                int numk = input[k] - '0';
                if((numi * 100 + numj * 10 + numk) % 8 == 0){
                    printf("YES\n");
                    printf("%d\n", numi * 100 + numj * 10 + numk);
                    return 0;
                }
            }
        }
    }
    for(int i = 0; i < input.length(); i++){
        for(int j = i + 1; j < input.length(); j++){
            int numi = input[i] - '0';
            int numj = input[j] - '0';
            if((numi * 10 + numj) % 8 == 0){
                printf("YES\n");
                printf("%d\n", numi * 10 + numj);
                return 0;
            }
        }
    }
    for(int i = 0; i < input.length(); i++){
        if((input[i] - '0') % 8 == 0){
            printf("YES\n");
            printf("%c\n", input[i]);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
/*
    La estrategia a usar es apoyarse en la regla por la cual un numero es divisible entre 8, luego, aplicarla
    (buscar numeros subsecuentes de 1 a 3 cifras). Se podria hacer DFS pero en su momento me habia cansado 
    porque no la pude hacer por ahi, ademas, teniendo en cuenta los casos en donde el numero de divisible entre 8, 
    solo serian 3 paras aninados.
*/