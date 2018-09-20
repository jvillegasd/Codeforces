#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int total = 2, sum, maxT = 0;
    scanf("%d", &n);
    int fib[n + 1];
    for(int i = 0; i < n; i++) scanf("%d", &fib[i]);
    if(n <= 2) printf("%d", n);
    else{
        for(int i = 2; i < n; i++){
            if(fib[i] == fib[i - 1] + fib[i - 2]){
                total++;
                maxT = max(total, maxT);
            }else total = 2;
        }
        maxT = max(total, maxT);
        cout << maxT;
    }
    return 0;
}