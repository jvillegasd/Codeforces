#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, sum = 0, diameter, ant = -1, os, a;
    vector<int> maxD;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a), maxD.push_back(a), sum+=a;
    if(sum < 2 * n - 2) printf("NO\n");
    else{
        vector<int> ones;
        for(int i = 0; i < n; i++) if(maxD[i] == 1) maxD[i] = 0, ones.push_back(i);
        os = ones.size();
        diameter = (n - os) - 1 + min(2, os);
        printf("YES %d\n%d\n", diameter, n - 1);
        if(!ones.empty()) ant = ones.back(), ones.pop_back();
        for(int i = 0; i < n; i++){ //Armando el grafo linea
            if(maxD[i] > 1){
                if(ant != -1){
                    maxD[ant]--;
                    maxD[i]--;
                    printf("%d %d\n", ant + 1, i + 1);
                }
                ant = i;
            }
        }
        for(int i = n - 1; i >= 0; i--){ //Agregando los vertices de grado 1 a los de grados superiores
            while(!ones.empty() && maxD[i] > 0){
                maxD[i]--;
                printf("%d %d\n", i + 1, ones.back() + 1);
                ones.pop_back();
            }
        }
    }
    return 0;
}

/*
    La estrategia a usar es crear primero un grafo linea con los vertices que tengran grado 2 en adelante para
    poder satisfacer la condificon del maximo diametro, luego, los vertices de 1 grado, colocarlos en los nodos
    que tengan mayor grado. Si se fijan, a la final se esta creando un arbol, por lo que oslo es posible crear un
    grado si la suma de los grado es 2 * n - 2. El diametro del grado sera los el numero de vertices usado para el
    grafo linea menos 1 [(n - t) - 1], pero, se pueden agregar 2 nodos -uno en cada extremo- de 1 grado para alcanzar
    un mayor diametro, por lo que se le sumaria el minimo entre 2 o el numero de vertices de grado 1, entonces, el
    diametro estaria dado asi: (n - t) - 1 + min(2, t). Donde t = vertices de grado 1. El loop final empieza desde el
    final para poder agregar el nodo al final del grafo linea si es posible.
*/