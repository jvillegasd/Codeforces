#include <stdio.h>

using namespace std;

int main(){
    int pen, last, size, n, cont = 0;
    scanf("%d", &n);
    if(n == 1){
        scanf("%d", &size);
        if(size == 15) printf("DOWN\n");
        else if(size == 0) printf("UP\n");
        else printf("-1\n");
    }else if(n > 1) {
        while(cont < n){
            scanf("%d", &size);
            if(cont == n - 2) pen = size;
            if(cont == n - 1) last = size;
            cont++;
        }
        if(last == 0) printf("UP\n");
        else if(last == 15) printf("DOWN\n");
        else if(pen > last) printf("DOWN\n");
        else if(last > pen) printf("UP\n");
    }
    return 0;
}