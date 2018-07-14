#include <stdio.h>

using namespace std;

int main(){
    int h, index;
    int a[100005], sum[100005], trees[2][200005];
    bool perfect = true;
    scanf("%d", &h);
    for(int i = 0; i <= h; i++){
        scanf("%d", &a[i]);
        //Ir recopilando los padres de los nodos
        if(i) sum[i] = sum[i - 1];
        sum[i]+=a[i];
    }
    index = 0; //Indica que nodo se esta trabajando
    trees[0][0] = trees[1][0] = 0;
    for(int i = 1; i <= h; i++){ //Recorrer por nivel el vector de numeros de nodos
        for(int j = 0; j < a[i]; j++){ //Asignar el padre sum[i - 1] a los a[i]-esimos nodos el i-esimo nivel
            index++;
            trees[0][index] = trees[1][index] = sum[i - 1];
        }
        if(a[i] > 1 && a[i - 1] > 1){ //Reasignar padre para crear el segundo arbol
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
    -) a[i] = numeros de nodos del i-esimo nivel
    -) sum[i - 1] = padre de los nodos del i-esimo nivel. Caso especial: sum[h] = total de nodos
    -) trees[i][j] = Padre el j-esimo nodo el i-esimo arbol
    -) El arbol es desbalanceado, siempre se abre al vertice de mayor numero teniendo en cuenta el ejemplo
    -) Para crear el segundo arbol no-isomorfo solo reasignar el padre al segundo vertice de mayor numero de la 
       (i - 1)-esima altura si se presenta la condicion: a[i] > 1 && a[i - 1] > 1
    -) Del ejemplo podemos tener en cuenta que si dos niveles consecutivos poseen mas de 1 nodo, entonces el arbol
       es ambigüo
*/