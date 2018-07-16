#include <stdio.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++) scanf("%d", &array[i]);
    /*for(int i = 0; i < n; i++){ //Version inicial
        bool even = (array[i] % 2 == 0) ? true : false, enter = false;
        for(int j = 0; j < n; j++){
            if(even && i != j && array[j] == array[i] - 1){
              array[j]++;
              enter = true;
            }else if(!even && i != j && array[j] == array[i] + 1){
              array[j]--;
              enter = true;
            }
        }
        if(!enter && array[i] % 2 == 0) array[i]--;
    }*/
    for(int i = 0; i < n; i++) if(array[i] % 2 == 0) array[i]--; //Version mejorada
    for(int i = 0; i < n; i++) printf("%d ", array[i]);
    return 0;
}