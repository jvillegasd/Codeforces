#include <bits/stdc++.h>

using namespace std;

string toLower(string in){
    for(int i = 0; i < in.length(); i++) if(in[i] >= 'A' && in[i] <= 'Z') in[i]+=32;
    return in;
}

int main(){
    int n, ans = 0;
    map<char, int> mapa;
    string in;
    scanf("%d", &n);
    cin >> in;
    in = toLower(in);
    for(int i = 0; i < n; i++){
        mapa[in[i]]++;
        if(mapa[in[i]] == 1) ans++;
    }
    if(ans == 26) printf("YES");
    else printf("NO"); 
    return 0;
}