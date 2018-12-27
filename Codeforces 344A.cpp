#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0;
    string inp;
    char ant = 'a';
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> inp;
        if(ant != inp[0]) ans++, ant = inp[0];
    }
    printf("%d", ans);
    return 0;
}