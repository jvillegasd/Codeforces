#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int n, number, even = 0, ansEven, ansOdd;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &number);
        if(number%2==0){
            even++;
            ansEven = i + 1;
        }else{
            ansOdd = i + 1;
        }
    } 
    if(even == 1) printf("%d\n", ansEven);
    else printf("%d\n", ansOdd);
    return 0;
}
/*
    Hay que imprimir el indice donde esta el numero que difiere en paricidad, me explico, si en una input hay 5 numeros
    en los cuales 4 son pares, entonces lo que tienes que imprimir es la ubicacion del impar y/o viceversa.
*/