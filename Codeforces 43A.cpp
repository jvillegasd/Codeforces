#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maxi = INT_MIN;
    string inp;
    map<string, int> mapa;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> inp, mapa[inp]++;
    for(map<string, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
        if(it->second > maxi){
            inp = it->first;
            maxi = it->second;
        }
    } 
    cout << inp;
    return 0;
}