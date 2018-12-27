#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    if(t == 10 && n == 1) printf("-1");
    else{
        if(t < 10) for(int i = 0; i < n; i++) printf("%d", t);
        else{
            for(int i = 0; i < n; i++){
                if(i < n - 1) printf("1"); 
                else printf("0");
            }
        }
    }
    return 0;
}