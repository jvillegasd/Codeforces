#include <stdio.h>

using namespace std;

int main(){
    bool bw = true;
    int n, m;
    char pixel;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        if(!bw) break;
        for(int j = 0; j < m; j++){
            scanf(" %c", &pixel);
            if(pixel != 'W' && pixel != 'B' && pixel != 'G'){
              bw = false;
              break;
            }
        }
    }
    if(bw) printf("#Black&White");
    else printf("#Color");
    return 0;
}