#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, t = 0, max = 0;
    scanf("%d", &n);
    int queue[n];
    for(int i = 0; i < n; i++) scanf("%d", &queue[i]);
    sort(queue, queue + n);
    for(int i = 0; i < n; i++){
        if(queue[i] >= t){
            max++;
            t += queue[i];
        }
    }
    printf("%d\n", max);
    return 0;
}
//En resumidas cuentas, hay que obviar a los decepcionados, vas a tomar el tiempo de espera para los que no lo esten.