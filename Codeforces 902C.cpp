#include <stdio.h>

using namespace std;

int main(){
    int h, index;
    int a[100005], sum[100005], trees[2][200005];
    bool perfect = true;
    scanf("%d", &h);
    for(int i = 0; i <= h; i++){
        scanf("%d", &a[i]);
        if(i) sum[i] = sum[i - 1];
        sum[i]+=a[i];
    }
    index = 0;
    trees[0][0] = trees[1][0] = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 0; j < a[i]; j++){
            index++;
            trees[0][index] = trees[1][index] = sum[i - 1];
        }
        if(a[i] > 1 && a[i - 1] > 1){
            trees[1][index]-=1;
            perfect = false;
        }
    }
    if(perfect) printf("perfect\n");
    else{     
        printf("ambiguous\n");
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < sum[h]; j++){
                printf("%d ", trees[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
    -) a[i] = i-esimo numeros de vertices del i-esimo nivel
    -) sum[i] = padre de la (i + 1)-esima altura
    -) el arbol es desbalanceado, siempre se abre al vertice de mayor numero
    -) para crear el segundo arbol no-isomorfo solo reasignar el padre al vertice de mayor numero de la i-esima altura
*/