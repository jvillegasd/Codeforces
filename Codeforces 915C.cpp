#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional> 

using namespace std;

char a[20], b[20], ans[20];
int visited[20], endF = false;

void DFS(int index, bool firstFound){
    if(endF) return; //Evitar calculos innecesarios
    if(index == strlen(a)){
        endF = true;
        return;
    }
    for(int i = 9; i >= 0; i--){ //Empezar desde los mayores para evitar calculos innecesarios
        if(visited[i] > 0){ //Probar con un numero disponible
            if(b[index] - '0' == i || firstFound){ //Encontrar un digito igual que b[index] o demas luego de (1)
                visited[i]--;
                ans[index] = i + '0';
                DFS(index + 1, firstFound);
                if(endF) return;
                visited[i]++; //Rehabilitar el numero para permutarlo
            }else if(b[index] - '0' > i){ //Encontrar un digito grande pero menor que b[index] -> (1)
                visited[i]--;
                ans[index] = i + '0';
                DFS(index + 1, true);
                if(endF) return;
                //Esta condicion no rehabilita el numero porque el que se encuentra aqui es el mayor que puede colocarse
            }
        }
    }
}

int main(){
    scanf("%s %s", a, b);
    if(strlen(b) > strlen(a)){
        sort(a, a + strlen(a), greater<int>());
        printf("%s\n", a);
    }else{
        for(int i = 0; i < strlen(a); i++) visited[a[i] - '0']++;
        DFS(0, false);
        printf("%s\n", ans);
    }
    return 0;
}
/*
    Use DFS porque debia hacer permutaciones, en este caso estan condicionadas. Mi implementacion del DFS para este
    problema viene dado de la sgt forma: Ir buscando primordialmente numeros disponibles que sean igual o menor que
    los digitos de b. Uso la variable "firstFound" para indicar que apenas encuentre un numero disponible grande pero 
    menor que el digito de b pueda agregar los demas digitos sin restricciones, es decir, agregar numeros que no 
    sigan las condiciones antes mencionadas y solo concentrarme en formar con los numeros faltantes el mayor posible.  
*/