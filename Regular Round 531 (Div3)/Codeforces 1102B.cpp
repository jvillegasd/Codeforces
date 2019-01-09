#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, a[5100], c[5100], color = 1, ai;
    map<int, int> mapa;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), mapa[a[i]]++;
    if(k > n){
        printf("NO");
        return 0;
    }
    for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
        if(it-> second > k){
            printf("NO");
            return 0;
        }
    }
    for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
        ai = it->first;
        for(int i = 1; i <= n; i++){
            if(a[i] == ai) c[i] = color++;
            if(color == k + 1) color = 1;
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++) printf("%d ", c[i]);
    return 0;
}