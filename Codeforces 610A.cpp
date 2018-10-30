#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2) printf("0");
    else{
        if(n % 4) printf("%d", n/4);
        else printf("%d", n/4 - 1);
    }
    return 0;
}