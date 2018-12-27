#include <bits/stdc++.h>

using namespace std;

string toLower(string w){
    for(int i = 0; i < w.length(); i++) if(w[i] >= 'A' && w[i] <= 'Z') w[i]+=32;
    return w;
}

string toUpper(string w){
    for(int i = 0; i < w.length(); i++) if(w[i] >= 'a' && w[i] <= 'z') w[i]-=32;
    return w;
}

int main(){
    int lc = 0;
    string inp;
    cin >> inp;
    for(int i = 0; i < inp.length(); i++) if(inp[i] >= 'a' && inp[i] <= 'z') lc++;
    if(lc >= inp.length() - lc) cout << toLower(inp);
    else cout << toUpper(inp);
    return 0;
}