#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, moves=0;
    scanf("%d", &n);
    char pin1[n], pin2[n];
    scanf("%s %s", pin1, pin2);
    for(int i = 0; i < n; i++){
        int disk1 = pin1[i], disk2 = pin2[i];
        moves += min(10-abs(disk1-disk2), abs(disk1-disk2));
    }
    printf("%d", moves);
    return 0;
}
/*
    No sabia que C++ no soportaba la operacion Modulo como se conoce matematicamente en su totalidad, por lo
    que tuve que improvisar para simular lo que queria hacer con Modulo
*/