#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string inp;
    map<char, int> mapa;
    scanf("%d", &n);
    cin >> inp;
    for(int i = 0; i < n; i++) mapa[inp[i]]++;
    printf("%d", abs(mapa['0'] - mapa['1']));
    return 0;
}