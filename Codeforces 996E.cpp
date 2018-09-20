#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y, index;
}points[100050];

int main(){
    int n, signs[100050];
    long long int xT = 0, yT = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &points[i].x, &points[i].y), points[i].index = i;
    while(true){
        xT = 0;
        yT = 0;
        for(int i = 0; i < n; i++){
            long long int xN = xT + points[i].x, yN = yT + points[i].y;
            long long int xN2 = xT - points[i].x, yN2 = yT - points[i].y;
            if(sqrt(xN*xN + yN*yN) <= sqrt(xN2*xN2 + yN2*yN2)){
                signs[points[i].index] = 1;
                xT+=points[i].x;
                yT+=points[i].y;
            }else{
                signs[points[i].index] = -1;
                xT-=points[i].x;
                yT-=points[i].y;
            }
        }
        if(sqrt(xT*xT + yT*yT) <= 1.5e+6) break; //Si coloco este condicional aqui si me funciona y no se porque
        random_shuffle(points, points + n);
    }
    for(int i = 0; i < n; i++) printf("%d ", signs[i]);
    return 0;
}
/*
    La estrategia que use fue realizar una implementacion greedy del problema pero, randomizarlo para cubrir casos 
    en donde el algoritmo greedy falle.
*/