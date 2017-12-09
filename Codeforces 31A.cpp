#include <stdio.h>

using namespace std;

int main(){
    int a[110], n;
    bool found = false;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1; i <= n && !found; i++){
        for(int j = 1; j <= n && !found; j++){
            if(i == j) continue;
            for(int k = j + 1; k <= n; k++){
                if(i != k && a[i] == a[j] + a[k]){
                    found = true;
                    printf("%d %d %d\n", i, j, k);
                    break;
                }
            }
        }
    }
    if(!found) printf("-1\n");
    return 0;
}