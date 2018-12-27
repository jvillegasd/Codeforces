#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) printf("%c", alpha[i % k]);
    return 0;
}