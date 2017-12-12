#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, boxes[200100], cont = 0;
    bool emptyB[200100];
    scanf("%d", &n);
    for(int i = 0; i < 200100; i++) emptyB[i] = true;
    for(int i = 0; i < n; i++) scanf("%d", &boxes[i]);
    sort(boxes, boxes + n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(boxes[j] > boxes[i] && emptyB[j]){
                emptyB[j] = false;
                cont++;
                break;
            }
        }
    }
    printf("%d\n", n - cont);
    return 0;
}
/*
    La estrategia es contar cuantas cajas pueden guardar otras cajas, la respuesta es el total de cajas - las cajas 
    que no estan vacias. Organizar el vector para optimizar el algoritmo.
*/