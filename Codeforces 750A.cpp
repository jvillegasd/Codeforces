#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, solved = 0;
    double problems;
    scanf("%d %d", &n, &k);
    problems = (double)k/60;
    for(int i = 1; i <= n; i++){
        if((double)5*i/60 + problems <= 4){
          problems+=(double)5*i/60;
          solved++;
        }else break;
    }
    printf("%d", solved);
    return 0;
}