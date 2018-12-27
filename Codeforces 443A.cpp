#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0;
    string line;
    map<char, int> mapa;
    getline(cin, line);
    for(int i = 0; i < line.length(); i++){
        mapa[line[i]]++;
        if(line[i] == ',' || line[i] == '{' || line[i] == '}' || line[i] == ' ') continue;
        if(mapa[line[i]] == 1) ans++;
    }
    printf("%d", ans);
    return 0;
}